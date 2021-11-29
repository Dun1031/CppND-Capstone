#include "Headers/Vehicle.h"


Vehicle::Vehicle(std::string model, float price, Status status, Color color, Trim trim)
{
    generateID(); 
    _model = model;
    _price = price;
    _status = status;
    _color = color;
    _trim = trim;
}

Vehicle::~Vehicle()
{
}

std::string Vehicle::getTrim()
{
    switch(_trim)
    {
        case touring:
        return "Touring";
        break;
        case premium:
        return "Premium";
        break;
        case limited:
        return "Limited";
        break;
        default:
        return "Base";
    }

    return "";
}

std::string Vehicle::getColor()
{
   switch(_color)
    {
        case black:
        return "Black";
        break;
        case yellow:
        return "Yellow";
        break;
        case blue:
        return "Blue";
        break;
        default:
        return "White";
    }    

    return "";
}

std::string Vehicle::getStatus()
{
   switch(_status)
    {
        case sold:
        return "Sold";
        break;
        case inTransit:
        return "In Transit";
        break;
        case withCustomer:
        return "With Customer";
        break;
        default:
        return "On Lot";
    }    

    return "";
}

float Vehicle::getPrice()
{
    return _price;
}

float Vehicle::getSellPrice()
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

