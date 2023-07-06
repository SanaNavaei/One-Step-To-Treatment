#ifndef PATIENTREQUEST_HPP
#define PATIENTREQUEST_HPP

#include <iostream>
#include <ctime>
#include "TreatmentPackage.hpp"

class Patient;

class PatientRequest
{
private:
    time_t Time;
    TreatmentPackage *treatment_package;
    Patient *patient;
    std::string status;

public:
    PatientRequest(time_t t, TreatmentPackage *p);
    bool CheckStatus(std::string status_); ///
    TreatmentPackage *getPackage();        ///
    void changeStatus(std::string status_);
    std::string getInfo();//new
    std::string getStatus();//new3
};

#endif