#include "HCD_Service.hpp"

void HCD_Service::assignHCD(Patient *patient)
{
    for (int i = 0; i < HCDs.size(); i++)
    {
        if (HCDs[i]->checkStatus("available"))
        {
            HCDs[i]->sendInfo(patient);
            HCDs[i]->changeStatus("busy");
            break;
        }
    }
}

void HCD_Service::addHCD(HospitalClinicDoctor* hcd)//new
{
    HCDs.push_back(hcd);
}

std::vector<HospitalClinicDoctor*> HCD_Service::getHCDs()//new
{
    return HCDs;
}