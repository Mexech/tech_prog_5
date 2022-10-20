#pragma once
#include <iostream>

using namespace std;

class Factory {
    public:
        Factory();
        ~Factory();

        void validateString(string s);
        void validateFloat(float n);

        friend ostream& operator<<(ostream &os, Factory &o);
        friend ostream& operator<<(ostream &os, Factory *o);

        virtual string getFactoryType() = 0;
        virtual string getParams() = 0;
        virtual string getFormattedParams() = 0;
        
        virtual void edit() = 0;
};