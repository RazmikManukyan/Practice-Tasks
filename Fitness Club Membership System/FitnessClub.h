#ifndef FCMS_FITNESSCLUB_H
#define FCMS_FITNESSCLUB_H
#include "Member.h"
#include <vector>
#include <fstream>

class FitnessClub{
private:
    std::vector<Member> members;
    std::vector<std::string> usageLog;
public:
    void addMember(const Member& member) {
        members.push_back(member);
    }

    Member* findMemberByName(const std::string& name) {
        for(auto& member : members) {
            if(member.getName() == name) {
                return &member;
            }
        }
        return nullptr;
    }

    void logUsage(const std::string& entry) {
        usageLog.push_back(entry);
    }

    void generateMonthlyStatistics(const Member& member) {
        std::cout << "Monthly Statistics for Member: " << member.getName() << std::endl;
        for(auto& entry : usageLog){
            std::cout << entry << std::endl;
        }
    }

    void generateMonthlyBill(const Member& member) {
        std::string filename = member.getName() + "_bill.txt";
        std::ofstream file(filename);
        if(file.is_open()) {
            file << "Monthly Bill for Member: " << member.getName() << std::endl;
            double totalCost = 0.0;
            MemberShipLevel memberShipLevel = member.getMemberShipLevel();
            switch (memberShipLevel) {
                case MemberShipLevel::STANDARD:
                    totalCost = member.calculateTotalCost(STANDARD_ENTRIES_FITNESS, STANDARD_ENTRIES_POOL, STANDARD_ENTRIES_MASSAGE);
                    break;
                case MemberShipLevel::PREMIUM:
                    totalCost = member.calculateTotalCost(STANDARD_ENTRIES_FITNESS * PREMIUM_MULTIPLIER, STANDARD_ENTRIES_POOL * PREMIUM_MULTIPLIER, STANDARD_ENTRIES_MASSAGE * PREMIUM_MULTIPLIER);
                    break;
                case MemberShipLevel::ALL_INCLUDED:
                    totalCost = member.calculateTotalCost(-1, -1, -1);
                    break;
            }

            file << "Total cost: " << totalCost << std::endl;
            file.close();
            std::cout << "Monthly bill generated and saved as " << filename << std::endl;
        } else {
            std::cout << "Unable to open the file for saving the monthly bill." << std::endl;
        }
    }
};


#endif //FCMS_FITNESSCLUB_H
