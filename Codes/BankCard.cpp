#include "BankCard.hpp"
#include <sstream>
#include <string>

BankCard::BankCard(std::string bank_card, std::string CVV_)
{
    CardNumber = std::stoi(bank_card);
    CVV = std::stoi(CVV_);
}