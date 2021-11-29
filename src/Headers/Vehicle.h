#include <string>

enum Status{onLot, sold, inTransit, withCustomer};
enum Trim{base, premium, limited, touring};
enum Color{black, white, blue, yellow};

class Vehicle
{
private:
    void generateID();

    /* data */
    int _id;
    float _price;
    float _sellPrice;
    std::string _model;
    Status _status;
    Color _color;
    Trim _trim;

public:
    Vehicle(std::string model, float price, Status status, Color color, Trim trim);
    Vehicle(int id, std::string model, float price, float sPrice, Status status, Color color, Trim trim) : _id(id), _model(model), _price(price), 
                                                                                                           _sellPrice(sPrice), _status(status), 
                                                                                                           _color(color), _trim(trim) {};

    Vehicle();
    ~Vehicle();    
    
    int getID();

    float getPrice();
    float getSellPrice();
    
    std::string getTrim();
    std::string getModel();   
    std::string getColor();
    std::string getStatus();

    void setTrim(Trim t);
    void setColor(Color c);
    void setStatus(Status s);
    void setPrice(float p);
    void setSellPrice(float sp);                                                                                                        

};