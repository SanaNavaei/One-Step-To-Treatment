#ifndef PATIENTSERVICE_HPP
#define PATIENTSERVICE_HPP

#include <iostream>
#include <vector>
#include "Patient.hpp"

class PatientService
{
private:
    std::vector<Patient *> patient_list;

public:
    PatientService() {}
    bool PatientExists(std::string email);
    Patient *getPatient(std::string password, std::string email);
    void addPatient(Patient *patient);
    std::vector<Patient*> getPatients();//new
};

#endif