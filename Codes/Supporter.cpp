#include "Supporter.hpp"
#include "Patient.hpp"

#include <string> //new

Supporter::Supporter(std::string name_, int rank_, std::string email_, std::string phone_number_, std::string status_) // new
{
    name = name_;
    rank = rank_;
    email = email_;
    phone_number = phone_number_;
    status = status_;
}

std::string Supporter::checkStatus()
{
    return status;
}

void Supporter::updateStatus(std::string status_)
{
    status = status_;
}

void Supporter::AnnouncePatient(Patient *patient)
{
    patients.push_back(patient);
}

std::string Supporter::getInfo() // new
{
    std::string info = "";
    info += name;
    info += " ";
    info += std::to_string(rank);
    info += " ";
    info += email;
    info += " ";
    info += phone_number;
    info += " ";
    info += status;
    return info;
}

std::string Supporter::getStatus()//new3
{
    return status;
}