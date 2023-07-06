#include "PatientRequest.hpp"

#include <string>

PatientRequest::PatientRequest(time_t t, TreatmentPackage *p)
{
    Time = t;
    treatment_package = p;
    status = "not confirmed";
}

bool PatientRequest::CheckStatus(std::string status_)
{
    if (status == status_)
        return true;
    return false;
}

void PatientRequest::changeStatus(std::string status_)
{
    status = status_;
}

TreatmentPackage *PatientRequest::getPackage()
{
    return treatment_package;
}

std::string PatientRequest::getInfo()
{
    std::string info = "";
    info += std::to_string(Time);
    info += " ";
    info += std::to_string(treatment_package->getID());
    info += " ";
    info += status;
    return info;
}

std::string PatientRequest::getStatus()//new 3
{
    return status;
}