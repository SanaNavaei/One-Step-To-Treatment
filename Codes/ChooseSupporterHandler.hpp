#ifndef CHOOSESUPPORTERHANDLER_HPP
#define CHOOSESUPPORTERHANDLER_HPP

#include <iostream>
#include <sstream>
#include "../server/server.hpp"
#include "PatientRequest.hpp"
#include "Patient.hpp"
#include "SupporterService.hpp"
using namespace std;

class OneStepToTreatment;

class ChooseSupporterHandler : public RequestHandler
{
private:
    SupporterService *supporter_service;
    OneStepToTreatment *treatment;

public:
    ChooseSupporterHandler(SupporterService *supporter_service_);
    Supporter *ChooseSupporter(PatientRequest *req, Patient *patient);
    Response *callback(Request *req);
    void setOSTT(OneStepToTreatment *treatment_);
};

#endif