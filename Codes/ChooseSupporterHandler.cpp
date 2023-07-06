#include "ChooseSupporterHandler.hpp"
#include "OneStepToTreatment.hpp"
#include "errors.hpp"

ChooseSupporterHandler::ChooseSupporterHandler(SupporterService *supporter_service_)
{
    supporter_service = supporter_service_;
}

Supporter *ChooseSupporterHandler::ChooseSupporter(PatientRequest *req, Patient *patient)
{
    if (!patient->checkReqValid(req))
    {
        throw Notfound();
        return NULL;
    }
    if (!req->CheckStatus("confirmed"))
    {
        throw NotPaid();
        return NULL;
    }
    Supporter *supporter = supporter_service->setSupporter();
    supporter->updateStatus("busy");
    patient->setSupporter(supporter);
    req->changeStatus("sup assigned");
    return supporter;
}

Response *ChooseSupporterHandler::callback(Request *req)
{
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    ostringstream body;
    try
    {
        PatientRequest *req = treatment->getRequest();
        Patient *patient = treatment->getPatient();
        Supporter *supporter = ChooseSupporter(req, patient);
        treatment->setSupporter(supporter);
        res = Response::redirect("/sendInfo");
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

void ChooseSupporterHandler::setOSTT(OneStepToTreatment *treatment_)
{
    treatment = treatment_;
}