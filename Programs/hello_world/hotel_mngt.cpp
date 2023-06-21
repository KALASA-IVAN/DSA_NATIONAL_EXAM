#include <iostream>

using namespace std;

int main()
{
    int quant;
    int choice;
    // Quantity
    int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshake = 0, Qchicken = 0;
    // food items sold
    int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshake = 0, Schicken = 0;
    // Total price of items
    int Total_rooms = 0, Total_pasta = 0, Total_burger = 0, Total_noodles = 0, Total_shake = 0, Total_chicken = 0;

    cout << "\n\t Quantity of items we have";
    cout << "\n Rooms available: ";
    cin >> Qrooms;
    cout << "\n Quantity of pasta: ";
    cin >> Qpasta;
    cout << "\n Quantity of burger: ";
    cin >> Qburger;
    cout << "\n Quantity of noodles: ";
    cin >> Qnoodles;
    cout << "\n Quantity of shake: ";
    cin >> Qshake;
    cout << "\n Quantity of chicken-roll: ";
    cin >> Qchicken;

    m:
    cout << "\n\t\t\t Please select from the menu options";
    cout << "\n\n1) Rooms";
    cout << "\n\n2) Pasta";
    cout << "\n\n3) Burger";
    cout << "\n\n4) Noodles";
    cout << "\n\n5) Shake";
    cout << "\n\n6) Chicken-roll";
    cout << "\n\n7) Information regarding sales and collection";
    cout << "\n\n8) Exit";

    cout << "\n\n Please Enter your choice!: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\n Enter the number of rooms you want: ";

        cin >> quant;
        if (Qrooms - Srooms >= quant)
        {
            Srooms = Srooms + quant;
            Total_rooms = Total_rooms * 1200;
            cout << "\n\n\t\t" << quant << "room/rooms have been alloted to you";
        }
        else
        {
            cout << "\n\tOnly" << Qrooms - Srooms << "Rooms remaining in the hotel";
        }
        break;

    case 2:
        cout << "\n\n Enter pasta quantity: ";

        cin >> quant;
        if (Qpasta - Spasta >= quant)
        {
            Spasta = Spasta + quant;
            Total_pasta = Total_pasta * 250;
            cout << "\n\n\t\t" << quant << "pasta is the order";
        }
        else
        {
            cout << "\n\tOnly" << Qpasta - Spasta << "Pasta remaining in the hotel";
        }
        break;

    case 3:
        cout << "\n\n Enter burger quantity: ";

        cin >> quant;
        if (Qburger - Sburger >= quant)
        {
            Sburger = Sburger + quant;
            Total_burger = Total_burger * 120;
            cout << "\n\n\t\t" << quant << "burger is the order";
        }
        else
        {
            cout << "\n\tOnly" << Qburger - Sburger << "burger remaining in the hotel";
        }
        break;

    case 4:
        cout << "\n\n Enter Noodles quantity: ";

        cin >> quant;
        if (Qnoodles - Snoodles >= quant)
        {
            Snoodles = Snoodles + quant;
            Total_noodles = Total_noodles * 250;
            cout << "\n\n\t\t" << quant << "noodles is the order";
        }
        else
        {
            cout << "\n\tOnly" << Qnoodles - Snoodles << "noodles remaining in the hotel";
        }
        break;

    case 5:
        cout << "\n\n Enter shake quantity: ";

        cin >> quant;
        if (Qshake - Sshake >= quant)
        {
            Sshake = Sshake + quant;
            Total_shake = Total_shake * 120;
            cout << "\n\n\t\t" << quant << "shake is the order";
        }
        else
        {
            cout << "\n\tOnly" << Qshake - Sshake << "shake remaining in the hotel";
        }
        break;

    case 6:
        cout << "\n\n Enter chicken-roll quantity: ";

        cin >> quant;
        if (Qchicken - Schicken >= quant)
        {
            Schicken = Schicken + quant;
            Total_chicken = Total_chicken * 150;
            cout << "\n\n\t\t" << quant << "chicken-roll is the order";
        }
        else
        {
            cout << "\n\tOnly" << Qchicken - Schicken << "chicken-roll remaining in the hotel";
        }
        break;

        case 7:

        cout << "\n\t\t Details of sales and collection ";
        cout << "\n\n Number of rooms we had : " << Qrooms;
        cout << "\n\n Number of rooms we gave for rent " << Srooms;
        cout << "\n\n Remaining rooms " << Qrooms - Srooms;
        cout << "\n\n Total rooms collection for the day : " << Total_rooms;
    
        cout << "\n\n Number of pasta we had : " << Qpasta;
        cout << "\n\n Number of pasta we gave for rent " << Spasta;
        cout << "\n\n Remaining pasta " << Qpasta - Spasta;
        cout << "\n\n Total pasta collection for the day : " << Total_pasta;
    
        cout << "\n\n Number of burger we had : " << Qburger;
        cout << "\n\n Number of burger we gave for rent " << Sburger;
        cout << "\n\n Remaining burger " << Qburger - Sburger;
        cout << "\n\n Total burger collection for the day : " << Total_burger;
    
        cout << "\n\n Number of noodles we had : " << Qnoodles;
        cout << "\n\n Number of noodles we gave for rent " << Snoodles;
        cout << "\n\n Remaining noodles " << Qnoodles - Snoodles;
        cout << "\n\n Total noodles collection for the day : " << Total_noodles;
    
        cout << "\n\n Number of shake we had : " << Qshake;
        cout << "\n\n Number of shake we gave for rent " << Sshake;
        cout << "\n\n Remaining shake " << Qshake - Sshake;
        cout << "\n\n Total shake collection for the day : " << Total_shake;
    
        cout << "\n\n Number of chicken-roll we had : " << Qchicken;
        cout << "\n\n Number of chicken-roll we gave for rent " << Schicken;
        cout << "\n\n Remaining chicken-roll " << Qchicken - Schicken;
        cout << "\n\n Total chicken-roll collection for the day : " << Total_chicken;

        cout << "\n\n\n Total collection of the day: " << Total_rooms + Total_pasta + Total_noodles + Total_shake + Total_burger + Total_chicken;
        break;

        case 8:
        exit(0);

        default:
        cout << "\n Please select the numbers mentioned above!";
    }
    goto m;
}