#include "SupporterService.hpp"

Supporter* SupporterService::setSupporter()
{
    for(int i = 0; i < supporter_list.size(); i++)
    {
        if(supporter_list[i]->checkStatus() == "busy")
        {
            continue;
        }
        return supporter_list[i];
    }
    std::cerr << "all supporters busy!\n";
    return NULL;
}

void SupporterService::addSupporter(Supporter* sup)//new
{
    supporter_list.push_back(sup);
}

std::vector<Supporter*> SupporterService::getSupporters()//new
{
    return supporter_list;
}