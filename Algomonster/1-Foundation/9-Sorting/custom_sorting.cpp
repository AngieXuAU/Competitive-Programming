#include <algorithm>
// #include <iostream>
#include <string>
#include <vector>

// copied from sample
int main() {
    struct Product {
        std::string name;
        int price;
        double rating;
    };

    std::vector<Product> products = {{"Laptop", 999, 4.5},
                                     {"Mouse", 25, 4.8},
                                     {"Keyboard", 79, 4.2},
                                     {"Monitor", 299, 4.6}};

    // Sort by price (ascending)
    std::sort(
        products.begin(), products.end(),
        [](const Product &a, const Product &b) { return a.price < b.price; });

    // Sort by rating (descending)
    std::sort(
        products.begin(), products.end(),
        [](const Product &a, const Product &b) { return a.rating > b.rating; });

    // Sort by name length
    std::sort(products.begin(), products.end(),
              [](const Product &a, const Product &b) {
                  return a.name.length() < b.name.length();
              });

    // Sort by multiple criteria: price, then rating
    std::sort(products.begin(), products.end(),
              [](const Product &a, const Product &b) {
                  if (a.price != b.price) {
                      return a.price < b.price;
                  }
                  return a.rating > b.rating;
              });

    return 0;
}