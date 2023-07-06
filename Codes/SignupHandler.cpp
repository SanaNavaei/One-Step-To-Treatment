#include "SignupHandler.hpp"
#include "OneStepToTreatment.hpp"
#include "errors.hpp"

SignupHandler::SignupHandler(PatientService *patient_service_)
{
    patient_service = patient_service_;
}

void SignupHandler::EnterSignupData(string username, string password, string email, string phone_number, string document, string bankCard, string CVV)
{
    bool is_exist = patient_service->PatientExists(email);
    if (is_exist)
    {
        throw resignup();
        return;
    }
    Document *document_ = new Document(document);
    BankCard *bank_card_ = new BankCard(bankCard, CVV);
    Patient *patient = new Patient(username, password, email, phone_number, document_, bank_card_);
    patient->updateStatus(true);
    patient_service->addPatient(patient);
    treatment->setPatient(patient);
    return;
}

Response *SignupHandler::callback(Request *req)
{
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    ostringstream body;
    try
    {
        EnterSignupData(req->getQueryParam("username"), req->getQueryParam("password"), req->getQueryParam("email"),
                        req->getQueryParam("phone_number"), req->getQueryParam("document"), req->getQueryParam("bankCard"), req->getQueryParam("CVV"));
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

void SignupHandler::setOSTT(OneStepToTreatment *treatment_)
{
    treatment = treatment_;
}