#include "ChoosePackageHandler.hpp"
#include "OneStepToTreatment.hpp"
#include "errors.hpp"

#include <ctime>

ChoosePackageHandler::ChoosePackageHandler(TreatmentPackageService *treatment_package_service_)
{
    treatment_package_service = treatment_package_service_;
}

PatientRequest *ChoosePackageHandler::ChoosePackageTreatment(Patient *patient, int package_id)
{
    if (!treatment_package_service->ValidPackage(package_id))
    {
        throw package_invalid();
        return NULL;
    }
    TreatmentPackage *package = treatment_package_service->reservePackage(package_id);
    PatientRequest *request = new PatientRequest(time(0), package);
    patient->add_request(request);
    int cost = package->getCost();
    Bill *bill = new Bill(cost, 0, package->getName());
    patient->setBill(bill);
    return request;
}

Response *ChoosePackageHandler::callback(Request *req)
{
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    ostringstream body;
    try
    {
        Patient *patient = treatment->getPatient();
        int package_id = stoi(req->getQueryParam("package"));
        PatientRequest *request = ChoosePackageTreatment(patient, package_id);
        treatment->setRequest(request);
        res = Response::redirect("/show_paymoney");
    }
    catch (exception &ex)
    {
        body << "<!DOCTYPE html>"
             << "<html>"
             << "<head>An error has ocuured!</head>"
             << "<br/>"
             << "<p>Error message: " << ex.what() << "</p>"
             << "<a href = \"/show_package\">try again</a></html>";
        res->setBody(body.str());
    }
    return res;
}

void ChoosePackageHandler::setOSTT(OneStepToTreatment *treatment_)
{
    treatment = treatment_;
}