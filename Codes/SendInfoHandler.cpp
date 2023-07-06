#include "SendInfoHandler.hpp"
#include "OneStepToTreatment.hpp"
#include "errors.hpp"
#include "DAO.hpp"

SendInfoHandler::SendInfoHandler(HCD_Service *hcd_service_, SupporterService *supporter_service_, TreatmentPackageService *treatment_package_service_, PatientService *patient_service_)
{
    hcd_service = hcd_service_;
    supporter_service = supporter_service_;
    treatment_package_service = treatment_package_service_;
    patient_service = patient_service_;
}

void SendInfoHandler::SendPatientInfo(Supporter *supporter, Patient *patient, PatientRequest *req)
{
    if (!patient->checkReqValid(req))
    {
        throw Notfound();
        return;
    }
    if (!req->CheckStatus("sup assigned"))
    {
        throw AlreadyPaid();
        return;
    }
    hcd_service->assignHCD(patient);
    supporter->AnnouncePatient(patient);
}

Response *SendInfoHandler::callback(Request *req)
{
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    ostringstream body;
    try
    {
        supporter = treatment->getSupporter();
        patient = treatment->getPatient();
        patient_req = treatment->getRequest();
        SendPatientInfo(supporter, patient, patient_req);
        DAO *dao_layer = new DAO(patient_service, treatment_package_service, supporter_service, hcd_service);
        dao_layer->update_data_base();
        res = Response::redirect("/Thank_show");
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

void SendInfoHandler::setOSTT(OneStepToTreatment *treatment_)
{
    treatment = treatment_;
}
