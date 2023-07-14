#ifndef OBS_PURCHASEHISTORY_H
#define OBS_PURCHASEHISTORY_H
#include <fstream>
#include <vector>
#include <iostream>

class PurchaseHistory {
private:
    std::vector<std::string> purchaseRecord;
public:
    void addPurchaseRecord(const std::string& record) {
        purchaseRecord.push_back(record);
    }

    void printPurchaseRecord() const {
        for(auto& book : purchaseRecord) {
            std::cout << book << std::endl;
        }
    }

    void savePurchaseHistoryToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (auto &record: purchaseRecord) {
                file << record << std::endl;
            }
            file.close();
            std::cout << "Purchase history saved to file." << std::endl;
        } else {
            std::cout << "Unable to open the file for saving purchase history." << std::endl;
        }
    }
};

#endif //OBS_PURCHASEHISTORY_H
