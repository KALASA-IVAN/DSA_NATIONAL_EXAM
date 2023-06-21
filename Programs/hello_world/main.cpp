#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Item
{
    int item_id;
    std::string item_name;
    int item_quantity;
    std::string item_registration_date;
};

std::vector<Item> inventory;

// Utility function to trim leading and trailing whitespaces from a string
std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Function to add a new item to the inventory
void addItem(int item_id, const std::string &item_name, int item_quantity, const std::string &item_registration_date)
{
    Item newItem;
    newItem.item_id = item_id;
    newItem.item_name = item_name;
    newItem.item_quantity = item_quantity;
    newItem.item_registration_date = item_registration_date;
    inventory.push_back(newItem);
}

// Function to list items in alphabetical order
void listItems()
{
    if (inventory.empty())
    {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    std::sort(inventory.begin(), inventory.end(), [](const Item &a, const Item &b)
              { return a.item_name < b.item_name; });

    for (const auto &item : inventory)
    {
        std::cout << "Item ID: " << item.item_id << "    Item Name: " << item.item_name
                  << "    Quantity: " << item.item_quantity << "    Reg Date: " << item.item_registration_date << std::endl;
    }
}

// Function to display the help information
void displayHelp()
{
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "*                           Commands syntaxes            *" << std::endl;
    std::cout << "         itemadd <item_id> <item_name> <quantity> <registration_date>" << std::endl;
    std::cout << "         itemslist" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
}

int main()
{
    std::cout << "****************************************************" << std::endl;
    std::cout << "*                                                  *" << std::endl;
    std::cout << "*            Welcome to RCA Inventory System       *" << std::endl;
    std::cout << "*                                                  *" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    std::string command;

    while (true)
    {
        std::cout << "Enter a command (type 'help' for command syntax): ";
        std::getline(std::cin, command);
        command = trim(command);

        // Convert the command to lowercase
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);

        if (command == "itemadd")
        {
            int item_id, item_quantity;
            std::string item_name, item_registration_date;
            std::cin >> item_id >> item_name >> item_quantity >> item_registration_date;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            addItem(item_id, item_name, item_quantity, item_registration_date);
            std::cout << "Item added successfully." << std::endl;
        }
        else if (command == "itemslist")
        {
            listItems();
        }
        else if (command == "help")
        {
            displayHelp();
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command. Type 'help' to see the list of commands." << std::endl;
        }
    }

    return 0;
}
