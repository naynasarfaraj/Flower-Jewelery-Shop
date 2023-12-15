#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store user account information
struct Account {
    char username[50];
    char password[50];
};

// Function to create a staff account
void createStaffAccount(struct Account *account) {
    printf("Create staff username: ");
    scanf("%s", account->username);

    printf("Create staff password: ");
    scanf("%s", account->password);

    printf("Staff account created successfully!\n");
}

// Login function for staff
void staffLogin(const struct Account *account) {
    char enteredUsername[50];
    char enteredPassword[50];

    printf("Username for staff login: ");
    scanf("%s", enteredUsername);

    printf("Password for staff login: ");
    scanf("%s", enteredPassword);

    // Compare the entered username and password with the staff account information
    if (strcmp(enteredUsername, account->username) == 0 && strcmp(enteredPassword, account->password) == 0)
    {
        printf("Staff login successful!\n");
    }
    else {
        printf("Invalid username or password. Login failed.\n");
    }
}

// Function to create a customer account
void createCustomerAccount(struct Account *account) {
    printf("Create customer username: ");
    scanf("%s", account->username);

    printf("Create customer password: ");
    scanf("%s", account->password);

    printf("Customer account created successfully!\n");
}

// Login function for customers
void customerLogin(const struct Account *account) {
    char enteredUsername[50];
    char enteredPassword[50];

    printf("Customer username for Login: ");
    scanf("%s", enteredUsername);

    printf("Customer password for Login: ");
    scanf("%s", enteredPassword);

    // Compare the entered username and password with the customer account information
    if (strcmp(enteredUsername, account->username) == 0 && strcmp(enteredPassword, account->password) == 0)
    {
        printf("Customer login successful!\n");
    }
    else {
        printf("Invalid username or password. Login failed.\n");
    }
}

// Define a structure to represent a floral jewelry product
struct Product {
    char name[100];
    int price;
    int id;
    char flowerType[50];
    int quantity;
};

// Function to insert a new floral jewelry product into the inventory
void insertProduct(struct Product inventory[], int *size, struct Product newProduct) {
    if (*size >= 100) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    // Find the position to insert the new product based on its name
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


// Define a simple structure to represent a jewelry item
struct JewelryItem {
    char name[100];
    int price;
    int id;
    char flowerType[50];
    int quantity;
};

// Function to search for a flower jewelry product by name
void searchItem(struct JewelryItem inventory[], int size, char productName[100]) {
    int i, found = 0;
    for (i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            found = 1;
            printf("Flower Jewelry: %s\n", inventory[i].name);
            printf("ID: %d\n", inventory[i].id);
            printf("Price: %d BDT\n", inventory[i].price);  // Corrected line
            printf("Flower Type: %s\n", inventory[i].flowerType);
            printf("Quantity: %d\n", inventory[i].quantity);
            break;
        }
    }


    if (!found) {
        printf("Flower Jewelry '%s' not found.\n", productName);
    }
}

// Function to add an item to the shopping cart
void addToCart(struct JewelryItem inventory[], int inventorySize, struct JewelryItem cart[], int *cartSize, int itemId) {
    if (itemId < 1 || itemId > inventorySize) {
        printf("Invalid item ID. Please enter a valid ID.\n");
        return;
    }

    // Check if the item is already in the cart
    for (int i = 0; i < *cartSize; i++) {
        if (cart[i].id == itemId) {
            cart[i].quantity++;
            printf("Added one more '%s' to the cart.\n", cart[i].name);
            return;
        }
    }

  // Find the item in the inventory and add it to the cart
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
void viewCart(struct JewelryItem cart[], int cartSize) {
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
    int choice;

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
         
            
            // Loop for staff login until successful
            int successfulLoginStaff = 0;

            while (!successfulLoginStaff) {
        
                // Check if staff login condition fails
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
                int menuChoice;
                
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
                printf("\nEnter jewelry ID: ");
                scanf("%d", &newProduct.id);
                printf("\nEnter jewelry price: ");
                scanf("%d", &newProduct.price);
                printf("\nEnter flower type: ");
                scanf("%s", newProduct.flowerType);
                printf("\nEnter quantity: ");
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
                searchItem(inventory, size, productName);
                break;
                    case 4:
                       displayInventory(inventory, size);
                break;
                    case 5:
                        printf("Successfully Logged-out.\n");
                        return 0;
                    default:
                        printf("Invalid choice.\n");
                }
                
            // Ask the staff if he/she wants to view the inventory again
                printf("View the inventory again? (y/n): ");
                scanf(" %c", &choice);
            }
            break;

        case 'c':
        case 'C':
            printf("Welcome To Flower Jewelry Shop!\n");
            createCustomerAccount(&customerAccount);
            
            // Loop for customer login until successful
            int successfulLoginCustomer = 0;

            // Loop for customer login until successful
while (!successfulLoginCustomer) {
    
    // Check if customer login condition fails
    printf("Enter customer username: ");
    scanf("%s", enteredUsername);

    printf("Enter customer password: ");
    scanf("%s", enteredPassword);


    if (strcmp(enteredUsername, customerAccount.username) == 0 &&
        strcmp(enteredPassword, customerAccount.password) == 0) {
        printf("Customer login successful!\n");
        successfulLoginCustomer = 1;
    } else {
        printf("Customer login failed. Please try again.\n");
    }
}

            // Creating an array to store jewelry items
    struct JewelryItem items[10];
   
    // Populate the jewelry items
    strcpy(items[0].name, "NonBridal");
    items[0].price = 1000;

    strcpy(items[1].name, "Bridal");
    items[1].price = 4000;

    strcpy(items[2].name, "BabySet");
    items[2].price = 1000;
   
    strcpy(items[3].name, "Kaleeras");
    items[3].price = 3500;

    strcpy(items[4].name, "NeckPieces");
    items[4].price = 500;

    strcpy(items[5].name, "Earrings");
    items[5].price = 500;
   
    strcpy(items[6].name, "Tairas");
    items[6].price = 350;
   
    strcpy(items[7].name, "FloralCrowns");
    items[7].price = 350;

    strcpy(items[8].name, "Haathphools");
    items[8].price = 600;

    strcpy(items[9].name, "Anklets");
    items[9].price = 600;

// Populate the jewelry items with unique IDs
for (int i = 0; i < 10; i++) {
    // Set the name directly without using strcpy
    switch (i) {
        case 0:
            strcpy(items[i].name, "NonBridal");
            break;
        case 1:
            strcpy(items[i].name, "Bridal");
            break;
        case 2:
            strcpy(items[i].name, "BabySet");
            break;
        case 3:
            strcpy(items[i].name, "Kaleeras");
            break;
        case 4:
            strcpy(items[i].name, "NeckPieces");
            break;
        case 5:
            strcpy(items[i].name, "Earrings");
            break;
        case 6:
            strcpy(items[i].name, "Tairas");
            break;
        case 7:
            strcpy(items[i].name, "FloralCrowns");
            break;
        case 8:
            strcpy(items[i].name, "Haathphools");
            break;
        case 9:
            strcpy(items[i].name, "Anklets");
            break;
    }

    // Set other attributes
    items[i].price;
    items[i].id = i + 1; // Unique ID for each item
    // ... (set other fields as needed)
}

            // Creating an array to store items in the shopping cart
            struct JewelryItem cart[100];
            int cartSize = 0;

            // Main menu loop
            while (1) {
                int choice;

                printf("\nWelcome to Flower Jewelry Shop\n");
                printf("\nEnter Your Choice: \n");
                printf("1. View Jewelries\n");
                printf("2. Search for Flower Jewelries\n");
                printf("3. Add to Cart\n");
                printf("4. View Cart\n");
                printf("5. Exit\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
            case 1:
                        // Display jewelry items
                        printf("\nJewelry Items:\n");
                        for (int i = 0; i < 10; i++) {
                            // Use %d for printing integers
                            printf("%d. %s - %d BDT\n", i + 1, items[i].name, items[i].price);
                        }
                        break;
            case 2:
                        // Search for jewelry
                            char searchName[100];
                            printf("Enter the name of the jewelry: ");
                            scanf("%s", searchName);
                            searchItem(items, 10, searchName);
                            break;
            case 3:
                    // Add to Cart
                    int itemId;
                    printf("Enter the ID of the item you want to add to the cart: ");
                    scanf("%d", &itemId);
                    addToCart(items, 10, cart, &cartSize, itemId);
                    break;
            case 4:
                   // View Cart
                    viewCart(cart, cartSize);
                     break;
            case 5:
                   // Exit the program
                   printf("Thank you for visiting the Flower Jewelry Shop!\n");
                return 0;
            default:
                    printf("Invalid choice. Please try again.\n");
                }
            }
            break;

        default:
            printf("Invalid User\n");
            // Handle invalid input if needed
            return 0;
    }

    printf("Thanks For Visiting. Have A Wonderful Day!\n");

    return 0;
}


