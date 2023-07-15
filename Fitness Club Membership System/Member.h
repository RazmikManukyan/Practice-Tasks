#ifndef FCMS_MEMBER_H
#define FCMS_MEMBER_H
#include <iostream>

const int STANDARD_ENTRIES_FITNESS = 12; const double costFitness = 10.99;
const int STANDARD_ENTRIES_POOL = 6; const double costPool = 8.99;
const int STANDARD_ENTRIES_MASSAGE = 1; const double costMassage = 15.99;
const int PREMIUM_MULTIPLIER = 2;

enum class MemberShipLevel{
    STANDARD,
    PREMIUM,
    ALL_INCLUDED
};

class Member {
private:
    std::string name;
    std::string contactInfo;
    MemberShipLevel memberShipLevel;
    int remainingEntriesFitness;
    int remainingEntriesPool;
    int remainingEntriesMassage;
public:
    Member(const std::string& name, const std::string& contactInfo, MemberShipLevel memberShipLevel)
            :name(name), contactInfo(contactInfo), memberShipLevel(memberShipLevel){
        switch (memberShipLevel) {
            case MemberShipLevel::STANDARD:
                remainingEntriesFitness = STANDARD_ENTRIES_FITNESS;
                remainingEntriesPool = STANDARD_ENTRIES_POOL;
                remainingEntriesMassage = STANDARD_ENTRIES_MASSAGE;
                break;
            case MemberShipLevel::PREMIUM:
                remainingEntriesFitness = STANDARD_ENTRIES_FITNESS * PREMIUM_MULTIPLIER;
                remainingEntriesPool = STANDARD_ENTRIES_POOL * PREMIUM_MULTIPLIER;
                remainingEntriesMassage = STANDARD_ENTRIES_MASSAGE * PREMIUM_MULTIPLIER;
                break;
            case MemberShipLevel::ALL_INCLUDED:
                remainingEntriesFitness = -1;
                remainingEntriesPool = -1;
                remainingEntriesMassage = -1;
                break;
        }
    }

    const std::string &getName() const {
        return name;
    }

    MemberShipLevel getMemberShipLevel() const {
        return memberShipLevel;
    }

    int getRemainingEntriesFitness() const {
        return remainingEntriesFitness;
    }

    int getRemainingEntriesPool() const {
        return remainingEntriesPool;
    }

    int getRemainingEntriesMassage() const {
        return remainingEntriesMassage;
    }

    void decreaseRemainingEntriesFitness() {
        if (remainingEntriesFitness > 0) {
            remainingEntriesFitness--;
        }
    }

    void decreaseRemainingEntriesPool() {
        if (remainingEntriesPool > 0) {
            remainingEntriesPool--;
        }
    }

    void decreaseRemainingEntriesMassage() {
        if (remainingEntriesMassage> 0) {
            remainingEntriesMassage--;
        }
    }

    void updateMemberShipLevel() {
        if(memberShipLevel != MemberShipLevel::ALL_INCLUDED) {
            memberShipLevel = static_cast<MemberShipLevel>(static_cast<int>(memberShipLevel) + 1);
        }
    }

    void downgradeMembershipLevel() {
        if(memberShipLevel != MemberShipLevel::STANDARD) {
            memberShipLevel = static_cast<MemberShipLevel>(static_cast<int>(memberShipLevel) - 1);
        }
    }

    double calculateTotalCost(int entriesFitness, int entriesPool, int entriesMassage) const{
        double totalCost = 0.0;
        int remainingEntriesFitness = getRemainingEntriesFitness();
        int remainingEntriesPool = getRemainingEntriesPool();
        int remainingEntriesMassage = getRemainingEntriesMassage();

        if(entriesFitness >= 0) {
            int usedEntryFitness = remainingEntriesFitness - entriesFitness;
            if(usedEntryFitness > 0) {
                totalCost += usedEntryFitness * costFitness;
            }
        }

        if(entriesPool >= 0) {
            int usedEntryPool = remainingEntriesPool - entriesPool;
            if(usedEntryPool > 0) {
                totalCost += usedEntryPool * costPool;
            }
        }

        if(entriesMassage >= 0) {
            int usedEntryMassage = remainingEntriesMassage - entriesMassage;
            if(usedEntryMassage > 0) {
                totalCost += usedEntryMassage * costMassage;
            }
        }

        return totalCost;
    }
};


#endif //FCMS_MEMBER_H
