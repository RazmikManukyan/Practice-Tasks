#ifndef E_HEALTHCARE_MANAGEMENT_SYSTEM_MEDICALHISTORY_H
#define E_HEALTHCARE_MANAGEMENT_SYSTEM_MEDICALHISTORY_H
#include <iostream>
#include <vector>

class MedicalHistory{
private:
    std::vector<std::string> diagnoses;
    std::vector<std::string> treatments;
    std::vector<std::string> medications;
public:
    void addDiagnosis(const std::string& diagnosis) {
        diagnoses.push_back(diagnosis);
    }
    void addTreatment(const std::string& treatment) {
        treatments.push_back(treatment);
    }
    void addMedication(const std::string& medication) {
        medications.push_back(medication);
    }

    void printMedicalHistory() const{
        std::cout << "Medical History: " << std::endl;
        std::cout << "Diagnoses: ";
        for(const auto& diagnosis : diagnoses) {
            std::cout << diagnosis << ", ";
        }
        std::cout << std::endl;

        std::cout << "Treatments: ";
        for(const auto& treatment : treatments) {
            std::cout << treatment << ", ";
        }
        std::cout << std::endl;

        std::cout << "Medications: ";
        for(const auto& medication : medications) {
            std::cout << medication << ", ";
        }
        std::cout << std::endl;

    }
};


#endif //E_HEALTHCARE_MANAGEMENT_SYSTEM_MEDICALHISTORY_H
