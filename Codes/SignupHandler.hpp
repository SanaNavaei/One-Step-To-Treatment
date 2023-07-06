#ifndef SIGNUPHANDLER_HPP
#define SIGNUPHANDLER_HPP

#include "PatientService.hpp"
#include "../server/server.hpp"
#include <iostream>
#include <sstream>
using namespace std;

class OneStepToTreatment;

class SignupHandler : public RequestHandler
{
private:
    PatientService *patient_service;
    Patient *patient;
    OneStepToTreatment *treatment;

public:
    SignupHandler(PatientService *patient_service_);
    void EnterSignupData(string username, string password, string email, string phone_number, string document, string bankCard, string CVV);
    Response *callback(Request *req);
    void setOSTT(OneStepToTreatment *treatment_);
};

#endif