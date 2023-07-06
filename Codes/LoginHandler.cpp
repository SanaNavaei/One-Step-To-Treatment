// #include "LoginHandler.hpp"
#include "OneStepToTreatment.hpp"
#include "errors.hpp"

LoginHandler::LoginHandler(PatientService *patient_service_)
{
    patient_service = patient_service_;
}

void LoginHandler::EnterLoginData(std::string username, std::string password, std::string email)
{
    bool is_exist = patient_service->PatientExists(email);
    if (!is_exist)
    {
        throw signup_first();
        return;
    }
    Patient *patient = patient_service->getPatient(password, email);
    patient->updateStatus(true);
    if (!patient->check_document_exist())
    {
        throw doc_invalid();
        return;
    }
    if (patient->check_bank_card_exist() == false)
    {
        throw card_invalid();
        return;
    }
    treatment->setPatient(patient);
    return;
}

Response *LoginHandler::callback(Request *req)
{
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    ostringstream body;
    try
    {
        EnterLoginData(req->getQueryParam("username"), req->getQueryParam("password"), req->getQueryParam("email"));
        res = Response::redirect("/show_package");
    }
    catch (exception &ex)
    {
        body << "<!DOCTYPE html>"
             << "<html>"
             << "<head>An error has ocuured!</head>"
             << "<br/>"
             << "<p>Error message: " << ex.what() << "</p>"
             << "<a href = \"/\">try again</a></html>";
        res->setBody(body.str());
    }
    return res;
}

void LoginHandler::setOSTT(OneStepToTreatment *treatment_)
{
    treatment = treatment_;
}