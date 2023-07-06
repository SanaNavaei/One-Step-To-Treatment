#ifndef SENDINFOHANDLER_HPP
#define SENDINFOHANDLER_HPP

#include <iostream>
#include "../server/server.hpp"
#include "Supporter.hpp"
#include "Patient.hpp"
#include "HCD_Service.hpp"
using namespace std;

class OneStepToTreatment;
class PatientService;
class TreatmentPackageService;
class SupporterService;

class SendInfoHandler : public RequestHandler
{
private:
    HCD_Service *hcd_service;
    Patient *patient;
    PatientRequest *patient_req;
    Supporter *supporter;
    OneStepToTreatment *treatment;
    PatientService *patient_service;
    TreatmentPackageService *treatment_package_service;
    SupporterService *supporter_service;

public:
    SendInfoHandler(HCD_Service *hcd_service_, SupporterService* supporter_service_, TreatmentPackageService* treatment_package_service_, PatientService* patient_service_);
    void SendPatientInfo(Supporter *supporter, Patient *patient, PatientRequest *req);
    Response *callback(Request *req);
    void setOSTT(OneStepToTreatment *treatment_);
};

#endif