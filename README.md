# Shop Management Console App
This project is a simple C++ console application that simulates a basic shop management system. It allows sellers to manage products (add, delete, update, and display) and customers to view and purchase products.

## Features

- **Seller Mode:**
  - Add new products to the shop.
  - Delete existing products.
  - Update the price and quantity of products.
  - Display a list of all available products.

- **Customer Mode:**
  - View the list of products available in the shop.
  - Purchase products by specifying the quantity.
  - View the total amount after purchasing products.

## Getting Started

### Prerequisites

To compile and run this project, you'll need:

- A C++ compiler (e.g., g++, clang++)
- A terminal or command-line interface

### Running the Project

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/cloth-shop-management.git

2. Navigate to the project directory:
   ```bash
   cd cloth-shop-management

2. Compile the code:
   ```bash
   g++ main.cpp -o shop

3. Run the executable:
   ```bash
   ./shop

## Usage
After running the program, you will be presented with a menu to choose between Seller Mode, Customer Mode, and Exit. Below are detailed instructions for each mode:

### Seller Mode

1. Add Product:
  - Select "Seller mode" from the main menu.
  - Choose "Add product".
  - Enter the product name, price, and quantity when prompted.

2. Delete Product:
- Choose "Delete product" from the Seller Mode menu.
- Enter the name of the product you wish to delete.

3. Update Product:
- Choose "Update product".
- Enter the name of the product to be updated, followed by the new price and quantity.
  
4. Display Products:
- Select "Display product" to view the list of all products with their details.
  
### Customer Mode

1. View Products:
- Select "Customer mode" from the main menu to view available products.
  
2. Buy Product:
- Enter the name of the product you want to buy.
- Specify the quantity.
- Continue adding products until you type `done`.
- The program will then display the total amount and confirm payment.
