#ifndef DAO_HPP
#define DAO_HPP

#include <iostream>

class PatientService;
class TreatmentPackageService;
class SupporterService;
class HCD_Service;

class DAO
{
private:
    PatientService *patient_service;
    TreatmentPackageService *treatment_package_service;
    SupporterService *supporter_service;
    HCD_Service *hcd_service;

public:
    DAO(PatientService *patient_service_, TreatmentPackageService *treatment_package_service_, SupporterService *supporter_service_, HCD_Service *hcd_service_);
    void read_data_base();
    void update_data_base();
};

#endif