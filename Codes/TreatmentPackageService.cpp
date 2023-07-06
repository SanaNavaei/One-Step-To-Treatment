#include "TreatmentPackageService.hpp"

bool TreatmentPackageService::ValidPackage(int package_id)
{
    for (int i = 0; i < package_list.size(); i++)
    {
        if (package_list[i]->getID() == package_id)
        {
            return true;
        }
    }
    return false;
}

TreatmentPackage *TreatmentPackageService::reservePackage(int package_id)
{
    for (int i = 0; i < package_list.size(); i++)
    {
        if (package_list[i]->getID() == package_id)
        {
            if (!package_list[i]->check_capacity())
            {
                std::cerr << "no capacity!\n";
                return NULL;
            }
            package_list[i]->reduce_capacity();
            return package_list[i];
        }
    }
}

void TreatmentPackageService::addPackage(TreatmentPackage *treatment_pack) // new
{
    package_list.push_back(treatment_pack);
}

std::vector<TreatmentPackage *> TreatmentPackageService::getPackages() // new
{
    return package_list;
}