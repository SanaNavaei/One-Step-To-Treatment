#include "TreatmentPackage.hpp"

#include <string> //new

TreatmentPackage::TreatmentPackage(int id, std::string name_, int estimated_cost, time_t t, int capacity_)//new
{
    ID = id;
    name = name_;
    estimatedCost = estimated_cost;
    Time = t;
    capacity = capacity_;
}

int TreatmentPackage::getID()
{
    return ID;
}

int TreatmentPackage::check_capacity()
{
    return capacity;
}

void TreatmentPackage::reduce_capacity()
{
    capacity--;
}

int TreatmentPackage::getCost()
{
    return estimatedCost;
}

std::string TreatmentPackage::getName()
{
    return name;
}

int TreatmentPackage::calculatePayment(int percentage)
{
    return int(estimatedCost * percentage / 100);
}

std::string TreatmentPackage::getInfo()//new
{
    std::string info = "";
    info += std::to_string(ID);
    info += " ";
    info += name;
    info += " ";
    info += std::to_string(estimatedCost);
    info += " ";
    info += std::to_string(Time);
    info += " ";
    info += std::to_string(capacity);
    return info;
}

int TreatmentPackage::getCapacity()//new3
{
    return capacity;
}