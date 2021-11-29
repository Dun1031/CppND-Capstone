#ifndef DATAMANAGER
#define DATAMANAGER
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Vehicle.h"

class DataManager
{
    public:
    DataManager();
    ~DataManager();

    void loadInventory();
    void addVehicles(std::shared_ptr<Vehicle> p);
    std::vector<std::shared_ptr<Vehicle>> getVehicles() {return Vehicles;}

    private:
    std::vector<std::shared_ptr<Vehicle>> Vehicles;
};

DataManager::DataManager()
{

}

DataManager::~DataManager()
{

}

void DataManager::addVehicles(std::shared_ptr<Vehicle> p)
{
    Vehicles.emplace_back(std::move(p));
}

void DataManager::loadInventory()
{
    std::ifstream invFile;
    
    invFile.open("C:\\Users\\jsmith\\Documents\\GitHub\\CppND-Capstone\\Data\\inventory.inv");

    if(invFile.is_open())
    {
        std::string line;

        while(std::getline(invFile, line))
        {
            std::cout << line << "\n";
        }
    }else
    {
        std::cout << "File did not open\n";
    }
}

#endif // end of DataManager