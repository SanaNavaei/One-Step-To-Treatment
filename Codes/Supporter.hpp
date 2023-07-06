#ifndef SUPPORTER_HPP
#define SUPPORTER_HPP

#include <iostream>
#include <vector>

class Patient;

class Supporter
{
private:
    std::string name;
    int rank;
    std::string email;
    std::string phone_number;
    std::string status;
    std::vector<Patient *> patients;

public:
    Supporter(std::string name_, int rank_, std::string email_, std::string phone_number_, std::string status_); // new
    // void setSupPatietn();///
    std::string checkStatus();              //
    void updateStatus(std::string status_); ///
    /// bool CheckSupForPatient();
    void AnnouncePatient(Patient *patient); ///
    std::string getInfo();                  // new
    std::string getStatus();//new3
};

#endif