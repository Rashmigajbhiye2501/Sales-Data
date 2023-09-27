#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Product {
    std::string name;
    double price;
};

struct Customer {
    int id;
    std::string name;
};

int main() {
    // list of products
    std::vector<Product> products = {
        {"Laptop", 60000},
        {"Mobile", 15000},
        {"Headphone", 500},
        {"Charger", 1200},
        {"Data Cable", 700}
    };

    // Customer information
    Customer customer;
    std::cout << "Enter Customer ID: ";
    std::cin >> customer.id;
    std::cin.ignore();  // Clear the newline character from the buffer
    std::cout << "Enter Customer Name: ";
    std::getline(std::cin, customer.name);

    // Choose a date
    std::string date;
    std::cout << "Enter a date (YYYY-MM-DD): ";
    std::cin >> date;

    // Create a vector to store quantities for all products (initialized with zeros)
    std::vector<int> quantities(products.size(), 0);

    // Total price
    double totalPrice = 0.0;

    // Display product menu
    std::cout << "Product Menu:" << std::endl;
    for (size_t i = 0; i < products.size(); ++i) {
        std::cout << i + 1 << ". " << products[i].name << " - INR" << products[i].price << std::endl;
    }

    // Allow the user to choose products and specify quantities using a switch statement
    char addAnotherProduct;
    do {
        int productChoice;
        std::cout << "Enter the number of the product you want to buy (1-" << products.size() << "): ";
        std::cin >> productChoice;

        // Validate the user's product choice
        if (productChoice < 1 || productChoice > static_cast<int>(products.size())) {
            std::cout << "Invalid choice. Please select a valid product." << std::endl;
        } else {
            int quantity;
            std::cout << "Enter the quantity of " << products[productChoice - 1].name << ": ";
            std::cin >> quantity;

            // Update the total price and store the quantity
            totalPrice += products[productChoice - 1].price * static_cast<double>(quantity);
            quantities[productChoice - 1] += quantity;

            // Ask if the user wants to add another product
            std::cout << "Add another product? (y/n): ";
            std::cin >> addAnotherProduct;
        }
    } while (addAnotherProduct == 'y' || addAnotherProduct == 'Y');

    // Display customer information, selected products, quantities, date, and total price
    std::cout << "Customer ID: " << customer.id << std::endl;
    std::cout << "Customer Name: " << customer.name << std::endl;
    std::cout << "Date chosen: " << date << std::endl;

    std::cout << "Selected Products:" << std::endl;
    for (size_t i = 0; i < products.size(); ++i) {
        if (quantities[i] > 0) {
            std::cout << "Product: " << products[i].name << ", Quantity: " << quantities[i] << std::endl;
        }
    }

    std::cout << "Total Price: INR" << std::fixed << std::setprecision(2) << totalPrice << std::endl;

    return 0;
}
