#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle() {
    cout << "Constructor Vehicle" << endl;
}

Vehicle::Vehicle(string brand, string model, string plate): brand(brand), model(model), plate(plate) {
    cout << "Constructor with params Vehicle" << endl;
}

Vehicle::Vehicle(const Vehicle &o): brand(o.brand), model(o.model), plate(o.plate) {
    cout << "Copy constructor Vehicle" << endl;
}

Vehicle::~Vehicle() {
    cout << "Destructor Vehicle" << endl;
}

void Vehicle::setBrand(string s) {
    validateString(s);
    brand = s;
}

string Vehicle::getBrand() {
    return brand;
}

void Vehicle::setModel(string s) {
    validateString(s);
    model = s;
}

string Vehicle::getModel() {
    return model;
}

void Vehicle::setPlate(string s) {
    validateString(s);
    plate = s;
}

string Vehicle::getPlate() {
    return plate;
}

string Vehicle::getFactoryType() {
    return "vehicle";
}

string Vehicle::getParams() {
    return brand + " " + model + " " + plate;
}

string Vehicle::getFormattedParams() {
    return "brand: " + brand + ", " + "model: " + model + ", " + "plate: " + plate + ".\n";
}

void Vehicle::edit() {
    while (1) {
        cout << "Type command number(1 - edit brand, 2 - edit model, 3 - edit plate, 4 - exit editing): " << endl;
        int num; cin >> num;
        bool error = false;
        if (num == 1) {
            cout << "Type new brand: " << endl;
            string value;
            cin >> value;
            try { 
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setBrand(value);
        } else if (num == 2) {
            cout << "Type new model: " << endl;
            string value;
            cin >> value;
            try { 
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setModel(value);
        } else if (num == 3) {
            cout << "Type new plate: " << endl;
            string value;
            cin >> value;
            try { 
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setPlate(value);
        } else if (num == 4) {
            break;
        } else
            cout << "Such property is not specified. Try again." << endl;
    }
}

istream& operator>>(istream &is, Vehicle &o) {
    float n; string s;
    cout << "brand: "; cin >> s; o.setBrand(s);
    cout << "model: "; cin >> s; o.setModel(s);
    cout << "plate: "; cin >> s; o.setPlate(s);
    return is;
}
