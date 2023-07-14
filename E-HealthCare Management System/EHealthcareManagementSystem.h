#ifndef E_HEALTHCARE_MANAGEMENT_SYSTEM_EHEALTHCAREMANAGEMENTSYSTEM_H
#define E_HEALTHCARE_MANAGEMENT_SYSTEM_EHEALTHCAREMANAGEMENTSYSTEM_H
#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "MedicalHistory.h"

class EHealthcareManagementSystem {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<MedicalHistory> medicalHistories;
public:
    void registerPatient(const Patient& patient) {
        patients.push_back(patient);
        MedicalHistory medicalHistory;
        medicalHistories.push_back(medicalHistory);
    }
    void registerDoctor(const Doctor& doctor) {
        doctors.push_back(doctor);
    }
    void recordDiagnosis(const Patient& patient, const std::string& diagnosis) {
        int patientIndex = findPatientIndex(patient);
        if(patientIndex != -1) {
            medicalHistories[patientIndex].addDiagnosis(diagnosis);
        }
    }

    void recordTreatments(const Patient& patient, const std::string& treatment) {
        int patientIndex = findPatientIndex(patient);
        if(patientIndex != -1) {
            medicalHistories[patientIndex].addTreatment(treatment);
        }
    }

    void recordMedications(const Patient& patient, const std::string& medication) {
        int patientIndex = findPatientIndex(patient);
        if(patientIndex != -1) {
            medicalHistories[patientIndex].addMedication(medication);
        }
    }

    void generateMedicalHistoryReport(const Patient& patient) const {
        int patientIndex = findPatientIndex(patient);
        if(patientIndex != -1) {
            std::string filename = patient.getName() + "_medical_history_report.txt";
            std::ofstream file(filename);
            if(file.is_open()) {
                file << "Medical History Report for Patient: " << patient.getName() << std::endl;
                file << "Date of Birth: " << patient.getDataOfBirth() << std::endl;
                file << "Gender: " << patient.gender << std::endl;
                file << "Contact Info: " << patient.getContactInfo() << std::endl;
                file << "Medical Conditions: " << patient.getMedicalCondition() << std::endl;
                file << std::endl;
                medicalHistories[patientIndex].printMedicalHistory();
                file.close();
                std::cout << "Medical history report generated and saved as " << filename << std::endl;
            } else {
                std::cout << "Unable to open the file for saving the medical history report." << std::endl;
            }
        } else {
            std::cout << "Patient not found! ";
        }
    }
private:
    int findPatientIndex(const Patient& patient) const{
        for(int i = 0; i < patients.size(); ++i) {
            if(patients[i].getName() == patient.getName()) {
                return i;
            }
        }
        return -1;
    }
};

#endif //E_HEALTHCARE_MANAGEMENT_SYSTEM_EHEALTHCAREMANAGEMENTSYSTEM_H
