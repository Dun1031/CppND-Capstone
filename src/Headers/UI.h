#include <iostream>
#include <sstream>
#include <memory>

#include "Vehicle.h"

class UI
{
private:

public:
    UI();
    ~UI();

    static void clear();
    static void mainMenu();
    static void addVehicle();
    static void handleInput(int choice);
    static void viewInventory();
};

