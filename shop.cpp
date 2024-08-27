#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Product {
    public:
        string name;
        double price;
        int quantity;

        Product(string n, double p, int q) : name(n), price(p), quantity(q) {}
};

class Shop {
    vector<Product> products;

    public:
        void addProduct() {
            string name;
            double price;
            int quantity;
            cout << "\nEnter product name: ";
            cin >> name;
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            products.push_back(Product(name, price, quantity));
            cout << "\nProduct added successfully" << endl;
        }

        void deleteProduct() {
            string name;
            cout << "\nEnter product name to delete: ";
            cin >> name;
            for(size_t i = 0; i < products.size(); i++) {
                if(products[i].name == name) {
                    products.erase(products.begin() + i);
                    cout << "\nProduct deleted successfully" << endl;
                    return;
                }
            }
            cout << "\nProduct not found" << endl;
        }

        void updateProduct() {
            string name;
            cout << "\nEnter product name to update: ";
            cin >> name;
            for(size_t i = 0; i < products.size(); i++) {
                if(products[i].name == name) {
                    cout << "\nEnter new price: ";
                    cin >> products[i].price;
                    cout << "Enter new quantity: ";
                    cin >> products[i].quantity;
                    cout << "\nProduct updated successfully" << endl;
                    return;
                }
            }
            cout << "\nProduct not found" << endl;
        }

        void displayProduct() {
            cout << "\n" << setw(15) << "Product Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
            for(size_t i = 0; i < products.size(); i++) {
                cout << setw(15) << products[i].name << setw(10) << products[i].price << setw(10) << products[i].quantity << endl;
            }
        }

        void buyProduct() {
            string name;
            int quantity;
            double total = 0.0;

            do
            {
                cout << "\nEnter product name to buy (or 'done' to finish): ";
                cin >> name;

                if(name == "done") {
                    break;
                }

                bool found = false;
                for(size_t i = 0; i < products.size(); i++) {
                    if(products[i].name == name) {
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        if(quantity > products[i].quantity) {
                            cout << "\nInsufficient stock!" << endl;
                        } else {
                            products[i].quantity -= quantity;
                            total += quantity * products[i].price;
                            cout << "\nProduct added to cart" << endl;
                        }
                        found = true;
                        break;
                    } 
                }
                if(!found) {
                    cout << "\nProduct not found" << endl;
                }
            } while (true);

            cout << "\nTotal amount: Rs." << total << endl;
            cout << "Payment successful" << endl;
        }
};

int main() {
    Shop shop;
    int choice;
    cout << "\nWELCOME TO THE SHOP MANAGEMENT CONSOLE APP" << endl;

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Seller mode" << endl << "2. Customer mode" << endl << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int sellerChoice;
                do {
                    cout << "\n- Seller Mode" << endl;
                    cout << "\n1. Add product" << endl << "2. Delete product" << endl << "3. Display product" << endl << "4. Update product" << endl << "5. Exit to main menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> sellerChoice;
                    switch(sellerChoice) {
                        case 1:
                            shop.addProduct();
                            break;
                        case 2:
                            shop.deleteProduct();
                            break;
                        case 3:
                            shop.displayProduct();
                            break;
                        case 4: 
                            shop.updateProduct();
                            break;
                        case 5: 
                            break;
                        default:
                            cout << "Invalid choice in seller mode" << endl;
                    }
                } while(sellerChoice != 5);
            }
            break;

            case 2:
                cout << "\n- Customer mode" << endl;
                shop.displayProduct();
                shop.buyProduct();
                break;
            case 3:
                cout << "\nExiting..." << endl;
                return 0;
            default:
                cout << "\nInvalid choice" << endl;
        }
    } while(choice != 3);
}
