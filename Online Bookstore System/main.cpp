#include "PurchaseHistory.h"
#include "Inventory.h"
#include "Customer.h"
#include "ShoppingCart.h"

int main() {
    Inventory inventory;
    PurchaseHistory purchaseHistory;

    Book book1("Title1", "Author1", "Genre1", 10.99, 5);
    Book book2("Title2", "Author2", "Genre2", 14.29, 3);
    inventory.addBook(book1);
    inventory.addBook(book2);

    Customer customer("John Doe", "john@example.com");

    ShoppingCart cart;
    cart.abbBook(book1);
    cart.abbBook(book2);

    double totalCost = cart.getTotalPrice();
    std::cout << "Total cost: " << totalCost << std::endl;

    std::string purchaseRecord = "Customer: " + customer.getName() + "| Total cost: " + std::to_string(totalCost) ;
    purchaseHistory.addPurchaseRecord(purchaseRecord);

    purchaseHistory.printPurchaseRecord();

    purchaseHistory.savePurchaseHistoryToFile("file.txt");

    return 0;
}
