#ifndef HOSPITALCLINICDOCTOR_HPP
#define HOSPITALCLINICDOCTOR_HPP

#include <iostream>
#include <vector>
#include "Patient.hpp"

class HospitalClinicDoctor{
private:
    std::string name;
    std::string password;
    std::string email;
    std::string hos_cil_name;
    std::string status;
    std::vector<Patient*> patients;

public:
    HospitalClinicDoctor(std::string name_, std::string password_, std::string email_, std::string hos_cil_name_, std::string status_);//new
    bool checkStatus(std::string status_);
    void sendInfo(Patient* patient);
    void changeStatus(std::string status_);
    std::string getInfo();//new
};

#endif