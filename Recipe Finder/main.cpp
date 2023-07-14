#include "RecipeFinder.h"
#include <sstream>
#include <algorithm>

int main() {
    ReceiptFinder receiptFinder("recipes.txt");

    Recipe recipe1("Pasta", { "Pasta", "Tomato Sauce", "Cheese" }, "1. Cook pasta. 2. Heat tomato sauce. 3. Combine pasta, sauce, and cheese.");
    Recipe recipe2("Salad", { "Lettuce", "Tomatoes", "Cucumber" }, "1. Chop lettuce, tomatoes, and cucumber. 2. Mix them together.");

    receiptFinder.addRecipe(recipe1);
    receiptFinder.addRecipe(recipe2);

    std::vector<std::string> searchIngredients = { "Pasta", "Tomato Sauce" };
    receiptFinder.searchReceipt(searchIngredients);


    return 0;
}
