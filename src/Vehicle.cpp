#include "Headers/Vehicle.h"


Vehicle::Vehicle(std::string model, int price, int status, int color, int trim)
{
    generateID(); 
    _model = model;
    _price = price;
    _status = (Status)status;
    _color = (Color)color;
    _trim = (Trim)trim;
}

Vehicle::~Vehicle()
{
}

Trim Vehicle::getTrim()
{
    return _trim;
}

Color Vehicle::getColor()
{
    return _color;
}

Status Vehicle::getStatus()
{
    return _status;
}

int Vehicle::getPrice()
{
    return _price;
}

int Vehicle::getSellPrice()
{
    return _sellPrice;
}

std::string Vehicle::getModel()
{
    return _model;
}

void Vehicle::generateID()
{
    int i = 0;

    _id = i;
}

int Vehicle::getID()
{
    return _id;
}

