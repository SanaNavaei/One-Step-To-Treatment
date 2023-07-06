#ifndef TREATMENTPACKAGE_HPP
#define TREATMENTPACKAGE_HPP

#include <iostream>
#include <ctime>

class TreatmentPackage
{
private:
    int ID;           ///
    std::string name; //
    int estimatedCost;
    time_t Time;
    int capacity; ///

public:
    TreatmentPackage(int id, std::string name_, int estimated_cost, time_t t, int capacity_);//new 
    int getID();            ///
    int check_capacity();   //
    void reduce_capacity(); //
    int getCost();          ///
    std::string getName();  ///
    int calculatePayment(int percentage);
    int prePayment();
    std::string getInfo();//new
    int getCapacity();//new3
};

#endif