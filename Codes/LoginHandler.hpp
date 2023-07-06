#ifndef LOGINHANLDER_HPP
#define LOGINHANDLER_HPP

#include "PatientService.hpp"
#include "../server/server.hpp"
#include <iostream>
#include <sstream>
using namespace std;

class OneStepToTreatment;

class LoginHandler : public RequestHandler
{
private:
    PatientService *patient_service;
    Patient *patient;
    OneStepToTreatment *treatment;

public:
    LoginHandler(PatientService *patient_service_);
    void EnterLoginData(std::string username, std::string password, std::string email);
    Response *callback(Request *req);
    void setOSTT(OneStepToTreatment *treatment_);
};

#endif