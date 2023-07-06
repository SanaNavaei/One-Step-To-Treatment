#include "PayMoneyHandler.hpp"
#include "OneStepToTreatment.hpp"
#include "errors.hpp"

void PayMoneyHandler::PayMoney(PatientRequest *req, Patient *patient, int percentage)
{
    if (!patient->checkReqValid(req))
    {
        throw Notfound();
        return;
    }
    if (!req->CheckStatus("not confirmed"))
    {
        throw AlreadyPaid();
        return;
    }
    int preCost = req->getPackage()->calculatePayment(percentage);
    Bill *bill = patient->getBill();
    bill->setPaid(preCost);
    bill->setDebt(preCost);
    req->changeStatus("confirmed");
}

Response *PayMoneyHandler::callback(Request *req)
{
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    ostringstream body;
    try
    {
        PatientRequest *req = treatment->getRequest();
        Patient *patient = treatment->getPatient();
        PayMoney(req, patient, PERCENTAGE);
        res = Response::redirect("/supporter");
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

void PayMoneyHandler::setOSTT(OneStepToTreatment *treatment_)
{
    treatment = treatment_;
}
