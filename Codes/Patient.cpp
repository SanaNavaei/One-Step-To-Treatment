#include "Patient.hpp"

Patient::Patient(std::string name_, std::string password_, std::string email_, std::string phone_number_, Document *document_, BankCard *bank_card_)
{
    name = name_;
    password = password_;
    email = email_;
    phone_number = phone_number_;
    status = true;
    document = document_;
    bank_card = bank_card_;
}

bool Patient::checkData(std::string email_)
{
    if (email == email_)
        return true;
    return false;
}

bool Patient::checkPass(std::string password_, std::string email_)
{
    if (password == password_ && email == email_)
        return true;
    return false;
}

bool Patient::check_bank_card_exist()
{
    if (bank_card == NULL)
        return false;
    return true;
}

bool Patient::check_document_exist()
{
    if (document == NULL)
        return false;
    return true;
}

void Patient::updateStatus(bool status_)
{
    status = status_;
}

void Patient::add_request(PatientRequest *r)
{
    request_list.push_back(r);
}

void Patient::setBill(Bill *bill_)
{
    bill = bill_;
}

bool Patient::checkReqValid(PatientRequest *req)
{
    for (int i = 0; i < request_list.size(); i++)
    {
        if (request_list[i] == req)
            return true;
    }
    return false;
}

Bill *Patient::getBill()
{
    return bill;
}

void Patient::setSupporter(Supporter *sup)
{
    supporter = sup;
}

std::vector<PatientRequest*> Patient::getRequests()//new
{
    return request_list;
}

std::string Patient::getEmail()//new
{
    return email;
}

Supporter* Patient::getSup()//new3
{
    return supporter;
}