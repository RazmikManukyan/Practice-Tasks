#ifndef RECIPE_FINDER_RECIPEFINDER_H
#define RECIPE_FINDER_RECIPEFINDER_H
#include "Recipe.h"
#include <fstream>

class ReceiptFinder {
    std::vector<Recipe> recipes;
    std::string filename;
public:
    ReceiptFinder(const std::string &filename)
            : filename(filename) {
        loadRecipesFromFile();
    }

    void searchReceipt(const std::vector<std::string> &ingredients) const {
        std::cout << "Searching Receipt: " << std::endl;
        std::cout << "Ingredients: ";
        for(const auto& ingredient : ingredients) {
            std::cout << ingredient << ", ";
        }
        std::cout << std::endl;

        std::vector<Recipe> matchingRecipes;
        for(const auto& recipe : recipes) {
            const std::vector<std::string>& recipeIngredients = recipe.getIngredients();
            if(std::includes(recipeIngredients.begin(), recipeIngredients.end(), ingredients.begin(), ingredients.end())) {
                matchingRecipes.push_back(recipe);
            }
        }
        if(matchingRecipes.empty()) {
            std::cout << "No recipes found with the given ingredients." << std::endl;
        } else {
            std::cout << "Matching Recipes:" << std::endl;
            for(const auto& recipe : matchingRecipes) {
                std::cout << "Name: " << recipe.getName() << std::endl;
                std::cout << "Ingredients: ";
                for(const auto& ingredient : ingredients) {
                    std::cout << ingredient << ", ";
                }
                std::cout << std::endl;
                std::cout << "Instructions: " << recipe.getInstructions() << std::endl;
                std::cout << "-----------------------------" << std::endl;
            }
        }
    }

    void addRecipe(const Recipe& recipe) {
        recipes.push_back(recipe);
    }
private:
    void loadRecipesFromFile() {
        std::ifstream file(filename);
        if(file.is_open()) {
            std::string line;
            std::string recipeName;
            std::vector<std::string> recipeIngredients;
            std::string recipeInstructions;

            while (std::getline(file, line)) {
                if(line == "Name:") {
                    std::getline(file, recipeName);
                }else if(line == "Ingredients:") {
                    std::string ingredient;
                    while(std::getline(file, ingredient) && ingredient != "Instructions:") {
                        recipeIngredients.push_back(ingredient);
                    }
                } else if(line == "Instructions:") {
                    std::getline(file, recipeInstructions);
                    Recipe recipe(recipeName, recipeIngredients, recipeInstructions);
                    recipes.push_back(recipe);
                    recipeIngredients.clear();
                }
            }
            file.close();
            std::cout << "Recipes loaded from file." << std::endl;
        } else {
            std::cout << "No existing recipes found. Creating a new recipe file." << std::endl;
        }
    }

    void saveRecipeToFile() const {
        std::ofstream file(filename);
        if(file.is_open()) {
            for(const auto& recipe : recipes) {
                file << "Name: " << std::endl;
                file << recipe.getName() << std::endl;
                file << "Ingredients:" << std::endl;
                for(const auto& ingredient : recipe.getIngredients()) {
                    file << ingredient << std::endl;
                }
                file << "Instructions:" << std::endl;
                file << recipe.getInstructions() << std::endl;
                file << "----------------------------" << std::endl;
            }
            file.close();
        }
        else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }

};


#endif //RECIPE_FINDER_RECIPEFINDER_H
