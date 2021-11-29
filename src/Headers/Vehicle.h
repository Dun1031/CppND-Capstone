#ifndef VEHICLE
#define VEHICLE

#include <string>

enum Status{onLot = 0, sold, inTransit, withCustomer};
enum Trim{base = 0, premium, limited, touring};
enum Color{black = 0, white, blue, yellow};

class Vehicle
{
private:
    void generateID();

    int _id;
    int _price;
    int _sellPrice;
    std::string _model;
    Status _status;
    Color _color;
    Trim _trim;

public:
    Vehicle(std::string model, int price, int status, int color, int trim);
    Vehicle(int id, std::string model, int price, int sPrice, Status status, Color color, Trim trim) : _id(id), _model(model), _price(price), 
                                                                                                           _sellPrice(sPrice), _status(status), 
                                                                                                           _color(color), _trim(trim) {};

    Vehicle();
    ~Vehicle();    
    
    int getID();

    int getPrice();
    int getSellPrice();
    
    Trim getTrim();
    std::string getModel();   
    Color getColor();
    Status getStatus();

    void setTrim(Trim t);
    void setColor(Color c);
    void setStatus(Status s);
    void setPrice(int p);
    void setSellPrice(int sp);                                                                                                        

};
#endif //END OF VEHICLE