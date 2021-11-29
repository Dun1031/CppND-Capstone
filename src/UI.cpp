#include "Headers/UI.h"
#include "Headers/DataManager.h"

static DataManager _dm;

UI::UI()
{
    _dm = DataManager();
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

std::istream& validateInput( std::istream& i, int& n )
{
  n = 0;

  std::string s;

  if (std::getline(i, s))
  {
    s.erase(s.find_last_not_of(" \f\n\r\t\v") + 1);

    std::istringstream iss(s);

    iss >> n;

    if (!iss.eof())
    {
      i.setstate(std::ios::failbit);
    }
  }

  return i;
}

void UI::mainMenu()
{
    int choice;

   // UI::clear();

    _dm.loadInventory();
    
    std::cout << "What would you liked to do?\n"
                << "1) View Inventory\n"
                << "2) Update Vheicle\n"  
                << "3) Add Vehicle\n"
                << "4) Quit\n"; 

    while(!validateInput(std::cin, choice))
    {
        std::cin.clear();
        UI::mainMenu();
    }

    UI::handleInput(choice);
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
        return "Black";
    }
}

int selectColor()
{
    int c = 0;

    while(!validateInput(std::cin, c) || c > 4 || c <= 0)
    {
        UI::clear();

        std::cout << "Select Color:\n"
        << "1) Black\n"
        << "2) White\n"
        << "3) Blue\n"
        << "4) Yellow\n";

        std::cin.clear();
    }    

    return c;
}

int selectTrim()
{
    int t = 0;

    while(!validateInput(std::cin, t) || t > 4 || t <= 0)
    {
        UI::clear();

        std::cout << "Select Trim:\n"
                  << "1) Base\n"
                  << "2) Premium\n"
                  << "3) Limited\n"
                  << "4) Touring\n";

        std::cin.clear();
    }

    return t;
}

int selectStatus()
{

    int s = 0;

    while(!validateInput(std::cin, s) || s > 4 || s <= 0)
    {
        UI::clear();

        std::cout << "Select Status:\n"
                  << "1) On Lot\n"
                  << "2) Sold\n"
                  << "3) In Transit\n"
                  << "4) With Customer\n";

        std::cin.clear();
    }

    return s;
}

int enterPrice()
{
    int p = 0;

    while(!validateInput(std::cin, p) || p <= 0)
    {
        UI::clear();

        std::cout << "Enter Price (Whole numbers only):";

        std::cin.clear();
    }

    return p;
}

int selectConfirmation(std::string m, int p, int c, int t, int s)
{
    int o = 0;

    while(!validateInput(std::cin, o) || o > 2 || o <=0)
    {        
        UI::clear();
        
        std::cout << "Here is what you selected: \n"
                << m << ", "
                << p << ", "
                << displayColor(c) << ", "
                << displayTrim(t) << ", "
                << displayStatus(s) << "\n"
                << "Is this correct?\n"
                << "1) Yes\n"
                << "2) No\n";
        
        std::cin.clear();
    }

    return o;
}

void UI::addVehicle()
{
    std::string m;
    int p = 0;
    int c = 0;
    int t = 0;
    int s = 0;
    int o = 0;

    std::cout << "Enter model:";
    std::cin >> m;
    
    UI::clear();

    std::cout << "Enter Price (Whole numbers only):";
    p = enterPrice();

    UI::clear();

    std::cout << "Select Color:\n"
              << "1) Black\n"
              << "2) White\n"
              << "3) Blue\n"
              << "4) Yellow\n";

    c = selectColor();
    
    UI::clear();

    std::cout << "Select Trim:\n"
              << "1) Base\n"
              << "2) Premium\n"
              << "3) Limited\n"
              << "4) Touring\n"; 

    t = selectTrim();

    UI::clear();

    std::cout << "Select Status:\n"
              << "1) On Lot\n"
              << "2) Sold\n"
              << "3) In Transit\n"
              << "4) With Customer\n";

    s = selectStatus();
    
    UI::clear();

    std::cout << "Here is what you selected: \n"
            << m << ", "
            << p << ", "
            << displayColor(c) << ", "
            << displayTrim(t) << ", "
            << displayStatus(s) << "\n"
            << "Is this correct?\n"
            << "1) Yes\n"
            << "2) No\n";

    o = selectConfirmation(m, p, c, t, s);

    if(o == 2)
    {
        UI::clear();
        UI::addVehicle();
    }else
    {

        auto v = std::shared_ptr<Vehicle>(new Vehicle(m, p, s, c, t));

        _dm.addVehicles(std::move(v));

        UI::clear();

        std::cout << Trim(t) << "\n";

        UI::mainMenu();
    }

}

void UI::handleInput(int choice)
{
    UI::clear();

    switch(choice)
    {
        case 1:
        UI::viewInventory();
        break;
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
    auto v = _dm.getVehicles();

    std::cout << "Inventory: \n";
    
    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i]->getID() << ", " 
                  << v[i]->getModel() << ", " 
                  << displayColor(v[i]->getColor()) << ", "
                  << displayTrim(v[i]->getTrim()) << ", "
                  << v[i]->getPrice() << ", "                                            
                  << displayStatus(v[i]->getStatus()) << "\n";
    }

    std::cout << "Press Enter to continue...\n";

    std::cin.get();
}