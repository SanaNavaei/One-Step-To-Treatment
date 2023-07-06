#ifndef TREATMENTPACKAGESERVICE_HPP
#define TREATMENTPACKAGESERVICE_HPP

#include <iostream>
#include <vector>
#include "TreatmentPackage.hpp"

class TreatmentPackageService
{
private:
    std::vector<TreatmentPackage *> package_list;

public:
    TreatmentPackageService() {} ///
    // void SetReserveTime(now);
    // int getCost();
    bool ValidPackage(int package_id);                 ///
    TreatmentPackage *reservePackage(int package_id);  ///
    void addPackage(TreatmentPackage *treatment_pack); // new
    std::vector<TreatmentPackage *> getPackages();     // new
    // bool CheckTreatmentPackage();
    // void setTreatmentTime(now);
    // std::string getTreatmentPackage();
};

#endif