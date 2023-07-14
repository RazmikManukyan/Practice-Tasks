#ifndef OBS_SHOPPINGCART_H
#define OBS_SHOPPINGCART_H
#include <vector>
#include "Book.h"

class ShoppingCart{
private:
    std::vector<Book> cart;
public:
    void abbBook(const Book& book) {
        cart.push_back(book);
    }

    void removeBook(const Book& book) {
        for(auto it = cart.begin(); it != cart.end(); ++it){
            if(it->getTitle() == book.getTitle()) {
                cart.erase(it);
            }
        }
    }

    double getTotalPrice() const {
        double price = 0.0;
        for(auto& book : cart) {
            price += book.getPrice();
        }
        return price;
    }
};

#endif //OBS_SHOPPINGCART_H
