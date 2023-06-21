#include <iostream>  // For cout and cin
#include <fstream>   // For file I/O
#include <sstream>   // For string streams 
#include <vector>    // For vectors
#include <algorithm> // For sort
#include <cctype>    // For isdigit
#include <stdexcept> // For invalid_argument
#include <regex>     // For regex_match
#include <locale>   // For case sensitive comparison
#include <iomanip>  // Added for setw and left manipulators

using namespace std;
struct Item
{
    int item_id;                   // Unique identifier for the item
    string item_name;              // Name of the item
    int item_quantity;             // Quantity of the item
    string item_registration_date; // Registration date of the item
};
vector<Item> inventory; // Vector to store the inventory items
/**
 * Function to check the provided date format
 */
bool isValidDateFormat(const string &date)
{
    // Check if the date has the format "YYYY-MM-DD"
    regex datePattern("\\d{4}-\\d{2}-\\d{2}");
    return regex_match(date, datePattern);
}
// Function to find an item in the inventory by name or ID
Item *findItem(const string &searchCriteria)
{
    // Search by ID
    if (isdigit(searchCriteria[0]))
    {
        int item_id = stoi(searchCriteria);
        for (auto &item : inventory)
        {
            if (item.item_id == item_id)
            {
                return &item;
            }
        }
    }
    // Search by name
    else
    {
        for (auto &item : inventory)
        {
            if (item.item_name == searchCriteria)
            {
                return &item;
            }
        }
    }
    return nullptr; // Item not found
}
/**
 * Function to add a new item to the inventory
 *
 * @param item_id The ID of the item
 * @param item_name The name of the item
 * @param item_quantity The quantity of the item
 * @param item_registration_date The registration date of the item
 */
void addItem(int item_id, const string &item_name, int item_quantity, const string &item_registration_date)
{
    // Check if the item_id already exists in the inventory
    Item *existingItemById = findItem(to_string(item_id));
    if (existingItemById != nullptr)
    {
        cout << "\n==> Item with ID " << item_id << " already exists in the inventory.\n"
             << endl;
        return;
    }
    Item item;
    item.item_id = item_id;
    item.item_name = item_name;
    item.item_quantity = item_quantity;
    item.item_registration_date = item_registration_date;
    inventory.push_back(item);
    // Save the item to the CSV file
    ofstream file("inventory.csv", ios::app);
    file << item.item_id << "," << item.item_name << "," << item.item_quantity << "," << item.item_registration_date << "\n";
    file.close();
}
/**
 * Comparison function to sort items alphabetically
 *
 * @param item1 The first item
 * @param item2 The second item
 * @return True if item1 comes before item2 in alphabetical order, false otherwise
 */
bool caseInsensitiveCompare(const std::string &str1, const std::string &str2)
{
    std::locale loc;
    for (std::size_t i = 0; i < str1.length() && i < str2.length(); ++i)
    {
        if (std::toupper(str1[i], loc) < std::toupper(str2[i], loc))
            return true;
        else if (std::toupper(str1[i], loc) > std::toupper(str2[i], loc))
            return false;
    }
    return (str1.length() < str2.length());
}
/**
 * Function to list all items in the inventory
 */
void listItems()
{
    if (inventory.empty())
    {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    std::sort(inventory.begin(), inventory.end(), [](const Item &a, const Item &b)
              { return caseInsensitiveCompare(a.item_name, b.item_name); });

    size_t maxIdLength = 0;
    size_t maxNameLength = 0;
    size_t maxQuantityLength = 0;
    size_t maxRegDateLength = 0;

    for (const auto &item : inventory)
    {
        maxIdLength = max(maxIdLength, to_string(item.item_id).length());
        maxNameLength = max(maxNameLength, item.item_name.length());
        maxQuantityLength = max(maxQuantityLength, to_string(item.item_quantity).length());
        maxRegDateLength = max(maxRegDateLength, item.item_registration_date.length());
    }

    // Print the items with aligned columns
    for (const auto &item : inventory)
    {
        cout << "Item ID: " << setw(maxIdLength) << left << item.item_id
                  << "        Item Name: " << setw(maxNameLength) << left << item.item_name
                  << "        Quantity: " << setw(maxQuantityLength) << left << item.item_quantity
                  << "        Reg Date: " << setw(maxRegDateLength) << left << item.item_registration_date << endl;
    }
}
/**
 * Function to display the help information
 */
void displayHelp()
{
    cout << "\n-----------------------------------------\n";
    cout << "*               Commands syntaxes       *\n";
    cout << "-----------------------------------------\n";
    cout << "itemadd <item_id> <item_name> <quantity> <registration_date>\n";
    cout << "itemslist\n";
    cout << "exit <to exit the program>\n\n";
}
/**
 * Function to convert a string to lowercase
 *
 * @param str The input string
 * @return The lowercase version of the string
 */
string toLowerCase(const string &str)
{
    string result;
    for (char c : str)
    {
        result += tolower(c);
    }
    return result;
}
int main()
{

    cout << "****************************************************" << endl;
    cout << "*                                                  *" << endl;
    cout << "*            Welcome to RCA Inventory System       *" << endl;
    cout << "*                                                  *" << endl;
    cout << "****************************************************" << endl;
    cout << endl;
    // Read inventory data from the CSV file
    ifstream file("inventory.csv");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            string token;
            vector<string> tokens;
            while (getline(iss, token, ','))
            {
                tokens.push_back(token);
            }
            if (tokens.size() == 4)
            {
                Item item;
                try
                {
                    item.item_id = stoi(tokens[0]);
                    item.item_quantity = stoi(tokens[2]);
                }
                catch (const invalid_argument &e)
                {
                    cout << "\n==> Invalid data in the inventory file. Skipping the item.\n"
                         << endl;
                    continue;
                }
                item.item_name = tokens[1];
                item.item_registration_date = tokens[3];
                inventory.push_back(item);
            }
        }
        file.close();
    }
    string command;
    while (true)
    {
        cout << "Enter a command ('help' for commands list): ";
        getline(cin, command);
        istringstream iss(command);
        string commandName;
        iss >> commandName;
        commandName = toLowerCase(commandName);
        if (commandName == "itemadd")
        {
            string item_id_str, item_name, quantity_str, registration_date;
            iss >> item_id_str >> item_name >> quantity_str >> registration_date;
            // Check if exactly four arguments are provided
            if (iss.fail() || !iss.eof())
            {
                cout << "\n==> Invalid input. Please provide exactly four arguments: [item_id, item_name, quantity, registration_date].\n"
                     << endl;
                continue;
            }
            // Convert item_id and quantity to integers
            int item_id, quantity;
            try
            {
                item_id = stoi(item_id_str);
                quantity = stoi(quantity_str);
            }
            catch (const invalid_argument &e)
            {
                cout << "\n==>Invalid input. Item ID and Quantity should be integers.\n"
                     << endl;
                continue;
            }
            // Validate the date format
            if (!isValidDateFormat(registration_date))
            {
                cout << "\n==> Invalid date format. The registration_date should be in the format 'YYYY-MM-DD'.\n"
                     << endl;
                continue;
            }
            addItem(item_id, item_name, quantity, registration_date);
        }
        else if (commandName == "itemslist")
        {
            listItems();
        }
        else if (commandName == "help")
        {
            displayHelp();
        }
        else if (commandName == "exit")
        {
            cout << endl;
            cout << "****************************************************" << endl;
            cout << "*                                                  *" << endl;
            cout << "*         Thank you for using RCA Inventory        *" << endl;
            cout << "*                      Goodbye!                    *" << endl;
            cout << "*                                                  *" << endl;
            cout << "****************************************************" << endl;
            break;
        }
        else
        {
            cout << "Invalid command. Enter 'help' for commands list. \n"
                 << endl;
        }
    }
    return 0;
}