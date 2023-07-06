#include "errors.hpp"

const char *signup_first::what() const noexcept { return "signup first!\n"; }

const char *doc_invalid::what() const noexcept { return "document not available please enter document.\n"; }

const char *card_invalid::what() const noexcept { return "bank card not available please enter the bank card info.\n"; }

const char *resignup::what() const noexcept { return "login! you have alredy signed up\n"; }

const char *package_invalid::what() const noexcept { return "invalid package!\n"; }

const char *Notfound::what() const noexcept { return "request not found!\n"; }

const char *NotPaid::what() const noexcept { return "not paid yet!\n"; }

const char *AlreadyPaid::what() const noexcept { return "already paid!\n"; }
