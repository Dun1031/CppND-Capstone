#include <iostream>
#include "Headers/UI.h"
#include "Headers/Vehicle.h"

UI::UI()
{

}

UI::~UI()
{

}

void UI::clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void UI::mainMenu()
{
    int choice;

    std::cout << "What would you liked to do?\n"
              << "1) View Inventory\n"
              << "2) Update Vheicle\n"  
              << "3) Add Vehicle\n"
              << "4) Quit\n"; 
    std::cin >> choice;

    UI::handleInput(choice);
}

bool checkIfNumber(std::string input)
{
    for(int i = 0; i < input.length(); i++)
    {
        if(!std::isdigit(input[i]))
        {
            return false;
        }        
    }

    return true;
}

std::string displayTrim(int t)
{
    switch(t)
    {
        case 4:
        return "Touring";
        break;
        case 2:
        return "Premium";
        break;
        case 3:
        return "Limited";
        break;
        default:
        return "Base";
    }
}

std::string displayStatus(int s)
{
    switch(s)
    {
        case 2:
        return "Sold";
        break;
        case 3:
        return "In Transit";
        break;
        case 4:
        return "With Customer";
        break;
        default:
        return "On Lot";
    }
}

std::string displayColor(int c)
{
    switch(c)
    {
        case 2:
        return "White";
        break;
        case 3:
        return "Blue";
        break;
        case 4:
        return "Yellow";
        break;
        default:
        return "Base";
    }
}

void UI::addVehicle()
{
    std::string m;
    float p = 0.0f;
    int c = 0;
    int t = 0;
    int s = 0;
    int o = 0;

    std::cout << "Enter model:";
    std::cin >> m;
    
    UI::clear();

    std::cout << "Enter Price:";
    std::cin >> p;
         
    while(c > 4 || c <= 0)
    {
        UI::clear();

        std::cout << "Select Color:\n"
                    << "1) Black\n"
                    << "2) White\n"
                    << "3) Blue\n"
                    << "4) Yellow\n";

        std::cin >> c;
    }
 
    while(t > 4 || t <= 0 )
    {        
        UI::clear();

        std::cout << "Select Trim:\n"
                  << "1) Base\n"
                  << "2) Premium\n"
                  << "3) Limited\n"
                  << "4) Touring\n";

        std::cin >> t;
    }

    while(s > 4 || s <= 0 )
    {
        UI::clear();

        std::cout << "Select Status:\n"
                  << "1) On Lot\n"
                  << "2) Sold\n"
                  << "3) In Transit\n"
                  << "4) With Customer\n";

        std::cin >> s;
    }

    std::cout << "Here is what you selected: \n"
              << m << ", "
              << p << ", "
              << displayColor(c) << ", "
              << displayTrim(t) << ", "
              << displayStatus(s) << "\n"
              << "Is this correct?\n"
              << "1) Yes\n"
              << "2) No\n";

    std::cin >> o;

    if(o == 2)
    {
        UI::clear();
        UI::addVehicle();
    }else
    {
        UI::clear();
        UI::mainMenu();
    }

}

void UI::handleInput(int choice)
{
    UI::clear();

    switch(choice)
    {
        case 1:
        //break;
        case 2:
        //break;
        case 3:
        UI::addVehicle();
        break;
        case 4:
        exit(0);
        break;
        default:
        UI::mainMenu();
        break;
    }
}

void UI::viewInventory()
{

}