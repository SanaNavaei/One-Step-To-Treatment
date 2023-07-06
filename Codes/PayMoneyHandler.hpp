#ifndef PAYMONEYHANDLER_HPP
#define PAYMONEYHANDLER_HPP

#include <iostream>
#include "../server/server.hpp"
#include "PatientRequest.hpp"
#include "Patient.hpp"
#include <sstream>
using namespace std;

#define PERCENTAGE 25

class OneStepToTreatment;

class PayMoneyHandler : public RequestHandler
{
private:
    OneStepToTreatment *treatment;

public:
    PayMoneyHandler() {}
    void PayMoney(PatientRequest *req, Patient *patient, int percentage);
    Response *callback(Request *req);
    void setOSTT(OneStepToTreatment *treatment_);
};

#endif