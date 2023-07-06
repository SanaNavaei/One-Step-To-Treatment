#ifndef HCD_SERVICE_HPP
#define HCD_SERVICE_HPP

#include <iostream>
#include <vector>
#include "Patient.hpp"
#include "HospitalClinicDoctor.hpp"

class HCD_Service{
private:
    std::vector<HospitalClinicDoctor*> HCDs;
public:
    HCD_Service(){}
    //void SendInfo();
    void assignHCD(Patient* patient);
    void addHCD(HospitalClinicDoctor* hcd);//new
    std::vector<HospitalClinicDoctor*> getHCDs();//new
};

#endif