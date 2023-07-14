#ifndef OBS_BOOK_H
#define OBS_BOOK_H
#include <iostream>

class Book{
private:
    std::string title;
    std::string author;
    std::string genre;
    double price;
    int quantity;
public:
    Book(const std::string& title, const std::string& author, const std::string& genre, double price, int quantity)
            :title(title), author(author), genre(genre), price(price), quantity(quantity){}

    const std::string getTitle() const {
        return title;
    }

    const std::string getAuthor() const {
        return author;
    }

    const std::string getGenre() const {
        return genre;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }
};

#endif //OBS_BOOK_H
