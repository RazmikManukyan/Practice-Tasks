#include "FitnessClub.h"

int main() {
    FitnessClub fitnessClub;

    Member member1("John", "john@example.com", MemberShipLevel::STANDARD);
    fitnessClub.addMember(member1);

    Member member2("Ann", "ann@example.com", MemberShipLevel::PREMIUM);
    fitnessClub.addMember(member2);

    Member member3("Jack", "jack@example.com", MemberShipLevel::ALL_INCLUDED);
    fitnessClub.addMember(member3);

    Member* foundMember = fitnessClub.findMemberByName("John");
    if(foundMember != nullptr) {
        if(foundMember->getRemainingEntriesFitness() > 0) {
            foundMember->decreaseRemainingEntriesFitness();
            fitnessClub.logUsage("John Doe entered the fitness area.");
        } else {
            std::cout << "John Doe has exhausted all fitness area entries for the month." << std::endl;
        }
    } else {
        std::cout << "Member not found. " << std::endl;
    }

    fitnessClub.generateMonthlyBill(member1);

    fitnessClub.generateMonthlyStatistics(member1);

    return 0;
}
