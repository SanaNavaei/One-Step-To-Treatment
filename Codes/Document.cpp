#include "Document.hpp"
#include <sstream>

Document::Document(std::string document)
{
    status = "not evaluated";
    std::istringstream ss(document);
    std::string kind_of_disease, disease_background;
    std::getline(ss, kind_of_disease, ',');
    std::getline(ss, disease_background, ',');
   // ss >> kind_of_disease >> disease_background;
    KindOfDisease = kind_of_disease;
    DiseaseBackground = disease_background;
}