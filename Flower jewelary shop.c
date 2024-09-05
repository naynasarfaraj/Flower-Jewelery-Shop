#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store user account information
struct Account {
    char username[50];
    char password[50];
};

// Structure to represent a floral jewelry product
struct Product {
    char name[100];
    int price;
    int id;
    char flowerType[50];
    int quantity;
};

// Function to create a staff account
void createStaffAccount(struct Account *account) {
    printf("Create staff username: ");
    scanf("%s", account->username);

    printf("Create staff password: ");
    scanf("%s", account->password);

    printf("Staff account created successfully!\n");
}

// Function to create a customer account
void createCustomerAccount(struct Account *account) {
    printf("Create customer username: ");
    scanf("%s", account->username);

    printf("Create customer password: ");
    scanf("%s", account->password);

    printf("Customer account created successfully!\n");
}

// Function to insert a new floral jewelry product into the inventory
void insertProduct(struct Product inventory[], int *size, struct Product newProduct) {
    if (*size >= 100) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    int i = *size;
    while (i > 0 && strcmp(newProduct.name, inventory[i - 1].name) < 0) {
        inventory[i] = inventory[i - 1];
        i--;
    }
    inventory[i] = newProduct;
    (*size)++;

    printf("Floral Jewelry '%s' added successfully!\n", newProduct.name);
}

// Function to delete a floral jewelry product by name
void deleteProduct(struct Product inventory[], int *size, char productName[50]) {
    int i, found = 0;
    for (i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < (*size - 1); i++) {
            inventory[i] = inventory[i + 1];
        }
        (*size)--;
        printf("Floral Jewelry '%s' deleted successfully!\n", productName);
    } else {
        printf("Floral Jewelry '%s' not found.\n", productName);
    }
}

// Function to search for a floral jewelry product by name
void searchProduct(struct Product inventory[], int size, char productName[50]) {
    int i, found = 0;
    for (i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            found = 1;
            printf("Flower Jewelry: %s\n", inventory[i].name);
            printf("ID: %d\n", inventory[i].id);
            printf("Price: %d BDT\n", inventory[i].price);
            printf("Flower Type: %s\n", inventory[i].flowerType);
            printf("Quantity: %d\n", inventory[i].quantity);
            break;
        }
    }

    if (!found) {
        printf("Flower Jewelry '%s' not found.\n", productName);
    }
}

// Function to display the entire flower jewelry inventory
void displayInventory(struct Product inventory[], int size) {
    printf("\nFlower Jewelry Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - ID: %d - Price: %dBDT - Flower Type: %s - Quantity: %d\n",
               i + 1, inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].flowerType, inventory[i].quantity);
    }
}

// Function to add an item to the shopping cart
void addToCart(struct Product inventory[], int inventorySize, struct Product cart[], int *cartSize, int itemId) {
    if (itemId < 1 || itemId > inventorySize) {
        printf("Invalid item ID. Please enter a valid ID.\n");
        return;
    }

    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].id == itemId) {
            cart[*cartSize] = inventory[i];
            (*cartSize)++;
            printf("Added '%s' to the cart.\n", inventory[i].name);
            return;
        }
    }

    printf("Item with ID %d not found in the inventory.\n", itemId);
}

// Function to display the contents of the shopping cart
void viewCart(struct Product cart[], int cartSize) {
    if (cartSize == 0) {
        printf("The shopping cart is empty.\n");
        return;
    }

    printf("\nShopping Cart:\n");
    for (int i = 0; i < cartSize; i++) {
        printf("%d. %s - %d BDT (Quantity: %d)\n", i + 1, cart[i].name, cart[i].price, cart[i].quantity);
    }
}

int main() {
    char userType[20];
    char choice;
    int menuChoice;

    struct Account staffAccount;
    struct Account customerAccount;
    struct Product inventory[100];
    int size = 0;
    struct Product newProduct;
    char productName[50];
    char enteredUsername[50]; 
    char enteredPassword[50];

    // Ask the user if they are staff or a customer
    printf("Are you Staff or Customer?\n ");
    scanf("%s", userType);

    // Comparing the user input and perform actions accordingly
    switch (userType[0]) {
        case 's':
        case 'S':
            printf("Welcome To Flower Jewelry Shop And Management System!\n");
            createStaffAccount(&staffAccount);
         
            int successfulLoginStaff = 0;
            while (!successfulLoginStaff) {
                printf("Enter staff username: ");
                scanf("%s", enteredUsername);

                printf("Enter staff password: ");
                scanf("%s", enteredPassword);

                if (strcmp(enteredUsername, staffAccount.username) == 0 && strcmp(enteredPassword, staffAccount.password) == 0) {
                    printf("Staff login successful!\n");
                    successfulLoginStaff = 1;
                } else {
                    printf("Staff login failed. Please try again.\n");
                }
            }

            // Ask the staff if they want to view the inventory
            printf("View the Inventory? (y/n): ");
            scanf(" %c", &choice);

            while (choice == 'y' || choice == 'Y') {
                printf("\nFloral Jewelry Shop And Management System\n");
                printf("1. Insert Flower Jewelry\n");
                printf("2. Delete Flower Jewelry\n");
                printf("3. Search Flower Jewelry by Name\n");
                printf("4. Display Inventory\n");
                printf("5. Exit\n");

                printf("Enter your choice: ");
                scanf("%d", &menuChoice);

                switch (menuChoice) {
                    case 1:
                        printf("\nEnter flower jewelry name: ");
                        scanf("%s", newProduct.name);
                        printf("Enter jewelry ID: ");
                        scanf("%d", &newProduct.id);
                        printf("Enter jewelry price: ");
                        scanf("%d", &newProduct.price);
                        printf("Enter flower type: ");
                        scanf("%s", newProduct.flowerType);
                        printf("Enter quantity: ");
                        scanf("%d", &newProduct.quantity);
                        insertProduct(inventory, &size, newProduct);
                        break;
                    case 2:
                        printf("Enter flower jewelry name to delete: ");
                        scanf("%s", productName);
                        deleteProduct(inventory, &size, productName);
                        break;
                    case 3:
                        printf("Enter flower jewelry name to search: ");
                        scanf("%s", productName);
                        searchProduct(inventory, size, productName);
                        break;
                    case 4:
                        displayInventory(inventory, size);
                        break;
                    case 5:
                        printf("Exiting Staff Panel.\n");
                        choice = 'n'; // Exit the while loop
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                        break;
                }
            }
            break;

        case 'c':
        case 'C':
            printf("Welcome To Flower Jewelry Shop And Management System!\n");
            createCustomerAccount(&customerAccount);

            int successfulLoginCustomer = 0;
            while (!successfulLoginCustomer) {
                printf("Enter customer username: ");
                scanf("%s", enteredUsername);

                printf("Enter customer password: ");
                scanf("%s", enteredPassword);

                if (strcmp(enteredUsername, customerAccount.username) == 0 && strcmp(enteredPassword, customerAccount.password) == 0) {
                    printf("Customer login successful!\n");
                    successfulLoginCustomer = 1;
                } else {
                    printf("Customer login failed. Please try again.\n");
                }
            }

            printf("\nView the Inventory? (y/n): ");
            scanf(" %c", &choice);

            struct Product cart[100];
            int cartSize = 0;
            int itemId;

            while (choice == 'y' || choice == 'Y') {
                printf("\n1. Add Flower Jewelry to Cart\n");
                printf("2. View Cart\n");
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &menuChoice);

                switch (menuChoice) {
                    case 1:
                        printf("Enter the item ID to add to cart: ");
                        scanf("%d", &itemId);
                        addToCart(inventory, size, cart, &cartSize, itemId);
                        break;
                    case 2:
                        viewCart(cart, cartSize);
                        break;
                    case 3:
                        printf("Exiting Customer Panel.\n");
                        choice = 'n';
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                        break;
                }
            }
            break;

        default:
            printf("Invalid user type.\n");
            break;
    }
    return 0;
}
