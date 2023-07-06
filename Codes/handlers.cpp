#include "handlers.hpp"
// #include <vector>
// #include <string>
// #include <iostream>
// #include <sstream>
// #include <exception>

// Response *SignupHandler::callback(Request *req)
// {
//     Response *res = new Response;
//     res->setHeader("Content-Type", "text/html");
//     ostringstream body;
//     try
//     {
//         patient = EnterSignupData(req->getQueryParam("username"), req->getQueryParam("password"), req->getQueryParam("email"),
//                                   req->getQueryParam("phone_number"), req->getQueryParam("document"), req->getQueryParam("bankCard"), req->getQueryParam("CVV"));
//         res = Response::redirect("/");
//     }
//     catch (exception &ex)
//     {
//         body << "<!DOCTYPE html>"
//              << "<html>"
//              << "<head>An error has ocuured!</head>"
//              << "<br/>"
//              << "<p>Error message: " << ex.what() << "</p>"
//              << "<a href = \"/\">try again</a></html>";
//         res->setBody(body.str());
//     }
//     return res;
// }

// Patient *SignupHandler::EnterSignupData(string username, string password, string email, string phone_number,
//                                         string document, string bankCard, string CVV)
// {
//   bool is_exist = patient_service->PatientExists(email, phone_number);
//   if (is_exist)
//   {
//     std::cerr << "login! you have alredy signed up";
//     return;
//   }
//   Document *document_ = new Document(document);
//   BankCard *bank_card_ = new BankCard(bankCard, CVV);
//   Patient *patient = new Patient(username, password, email, phone_number, document, bankCard, CVV);
//   patient->updateStatus(true);
//   patient_service->addPatient(patient);
//   return patient;
// }