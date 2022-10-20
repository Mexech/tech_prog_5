#include "Factory.h"

using namespace std;

Factory::Factory() {
    cout << "Constructor Factory" << "\n";
}

Factory::~Factory() {
    cout << "Destructor Factory" << "\n";
};

void Factory::validateString(string s) {
    if (s.length() <= 0) 
        throw invalid_argument("empty string");
}

void Factory::validateFloat(float n) {
    if (n <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        throw invalid_argument("value cannot be negative or zero");
    }
}

ostream& operator<<(ostream &os, Factory &o) {
    os << o.getFactoryType() << endl << "\t" << o.getFormattedParams();
    return os;
}

ostream& operator<<(ostream &os, Factory *o) {
    os << o->getFactoryType() << endl << "\t" << o->getFormattedParams();
    return os;
}
