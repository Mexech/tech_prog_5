#include "Furniture.h"

using namespace std;

Furniture::Furniture() {
    cout << "Constructor Furniture" << endl;
}

Furniture::Furniture(string type, float height, float width, float depth, string color, string material, float cost):
type(type), height(height), width(width), depth(depth), color(color), material(material), cost(cost)
{
    cout << "Constructor with params Furniture" << endl;
}

Furniture::Furniture(const Furniture &o):
type(o.type), height(o.height), width(o.width), depth(o.depth), color(o.color), material(o.material), cost(o.cost)
{
    cout << "Copy constructor Furniture" << endl;
}

Furniture::~Furniture() {
    cout << "Destructor Furniture" << endl;
}

void Furniture::setType(string s) {
    validateString(s);
    type = s;
}

string Furniture::getType() {
    return type;
}

void Furniture::setHeight(float n) {
    validateFloat(n);
    height = n;
}

float Furniture::getHeight() {
    return height;
}

void Furniture::setWidth(float n) {
    validateFloat(n);
    width = n;
}

float Furniture::getWidth() {
    return width;
}

void Furniture::setDepth(float n) {
    validateFloat(n);
    depth = n;
}

float Furniture::getDepth() {
    return depth;
}

void Furniture::setColor(string s) {
    validateString(s);
    color = s;
}

string Furniture::getColor() {
    return color;
}

void Furniture::setMaterial(string s) {
    validateString(s);
    material = s;
}

string Furniture::getMaterial() {
    return material;
}

void Furniture::setCost(float n) {
    validateFloat(n);
    cost = n;
}

float Furniture::getCost() {
    return cost;
}

string Furniture::getFactoryType() {
    return "furniture";
}

string Furniture::getParams() {
    return type + " " + to_string(height) + " " + to_string(width) + " " + to_string(depth) + " " + color + " " + material + " " + to_string(cost);
}

string Furniture::getFormattedParams() {
    return "type: " + type + ", " + "height: " + to_string(height) + ", " + "width: " + to_string(width) + ", " + "depth: " + to_string(depth) + ", " + "color: " + color + ", " + "material: " + material + ", " + "cost: " + to_string(cost) + ".\n";
}

void Furniture::edit() {
    while (1) {
        cout << "Type command number(1 - type, 2 - height, 3 - width, 4 - depth, 5 - color, 6 - material, 7 - cost, 8 - exit editing): " << endl;
        int num = 0; cin >> num;
        bool error = false;
        if (num == 1) {
            cout << "Type new type: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setType(value);
        } else if (num == 2) {
            cout << "Type new height: " << endl;
            float value;
            cin >> value;
            try {
                validateFloat(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setHeight(value);
        } else if (num == 3) {
            cout << "Type new width: " << endl;
            float value;
            cin >> value;
            try {
                validateFloat(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setWidth(value);
        } else if (num == 4) {
            cout << "Type new depth: " << endl;
            float value;
            cin >> value;
            try {
                validateFloat(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setDepth(value);
        } else if (num == 5) {
            cout << "Type new color: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setColor(value);
        } else if (num == 6) {
            cout << "Type new material: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setMaterial(value);
        } else if (num == 7) {
            cout << "Type new cost: " << endl;
            float value;
            cin >> value;
            try {
                validateFloat(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setCost(value);
        } else if (num == 8) {
            break;
        } else {
            cout << "Such property is not specified. Try again." << endl;
        }
    }
}

istream& operator>>(istream &is, Furniture &o) {
    float n; string s;
    cout << "type: "; cin >> s; o.setType(s);
    cout << "height: "; cin >> n; o.setHeight(n);
    cout << "width: "; cin >> n; o.setWidth(n);
    cout << "depth: "; cin >> n; o.setDepth(n);
    cout << "color: "; cin >> s; o.setColor(s);
    cout << "material: "; cin >> s; o.setMaterial(s);
    cout << "cost: "; cin >> n; o.setCost(n);
    return is;
}