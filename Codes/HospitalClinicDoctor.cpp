#include "HospitalClinicDoctor.hpp"

//new
HospitalClinicDoctor::HospitalClinicDoctor(std::string name_, std::string password_, std::string email_, std::string hos_cil_name_, std::string status_)
{
    name = name_;
    password = password_;
    email = email_;
    hos_cil_name = hos_cil_name_;
    status = status_;
}

bool HospitalClinicDoctor::checkStatus(std::string status_)
{
    if(status == status_)
        return true;
    return false;
}

void HospitalClinicDoctor::sendInfo(Patient* patient)
{
    patients.push_back(patient);
}

void HospitalClinicDoctor::changeStatus(std::string status_)
{
    status = status_;
}


std::string HospitalClinicDoctor::getInfo()//new
{
    std::string info = "";
    info += name;
    info += " ";
    info += password;
    info += " ";
    info += email;
    info += " ";
    info += hos_cil_name;
    info += " ";
    info += status;
    return info;
}