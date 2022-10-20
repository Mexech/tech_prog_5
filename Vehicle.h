#include "Factory.h"

using namespace std;

class Vehicle: public Factory {
    private:
        string brand;
        string model;
        string plate;
    public:
        Vehicle();
        Vehicle(string brand, string model, string plate);
        Vehicle(const Vehicle &o);
        ~Vehicle();

        void setBrand(string s);
        string getBrand();
        void setModel(string s);
        string getModel();
        void setPlate(string s);
        string getPlate();

        string getFactoryType();
        string getParams();
        string getFormattedParams();
        void edit();

        friend istream& operator>>(istream &is, Vehicle &o);
};