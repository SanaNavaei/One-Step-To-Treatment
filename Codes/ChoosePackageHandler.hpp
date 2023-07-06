#ifndef CHOOSEPACKAGEHANDLER_HPP
#define CHOOSEPACKAGEHANDLER_HPP

#include <iostream>
#include <sstream>
#include "../server/server.hpp"
#include "Patient.hpp"
#include "TreatmentPackageService.hpp"
#include "PatientRequest.hpp"
using namespace std;

class OneStepToTreatment;

class ChoosePackageHandler : public RequestHandler
{
private:
    TreatmentPackageService *treatment_package_service;
    OneStepToTreatment *treatment;
    Patient *patient;

public:
    ChoosePackageHandler(TreatmentPackageService *treatment_package_service_);
    PatientRequest *ChoosePackageTreatment(Patient *patient, int package_id);
    Response *callback(Request *req);
    void setOSTT(OneStepToTreatment *treatment_);
};

#endif