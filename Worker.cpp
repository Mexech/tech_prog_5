#include "Worker.h"

using namespace std;

Worker::Worker() {
    cout << "Constructor Worker" << endl;
}

Worker::Worker(string name, string surname, string patronymic, string job, float wage, string address, string phone):
name(name), surname(surname), patronymic(patronymic), job(job), wage(wage), address(address), phone(phone)
{
    cout << "Constructor with params Worker" << endl;
}

Worker::Worker(const Worker &o):
name(o.name), surname(o.surname), patronymic(o.patronymic), job(o.job), wage(o.wage), address(o.address), phone(o.phone)
{
    cout << "Copy constructor Worker" << endl;
}

Worker::~Worker() {
    cout << "Destructor Worker" << endl;
}

void Worker::setName(string s) {
    validateString(s);
    name = s;
}

string Worker::getName() {
    return name;
}

void Worker::setSurname(string s) {
    validateString(s);
    surname = s;
}

string Worker::getSurname() {
    return surname;
}

void Worker::setPatro(string s) {
    validateString(s);
    patronymic = s;
}

string Worker::getPatro() {
    return patronymic;
}

void Worker::setJob(string s) {
    validateString(s);
    job = s;
}

string Worker::getJob() {
    return job;
}

void Worker::setWage(float n) {
    validateFloat(n);
    wage = n;
}

float Worker::getWage() {
    return wage;
}

void Worker::setAddress(string s) {
    validateString(s);
    address = s;
}

string Worker::getAddress() {
    return address;
}

void Worker::setPhone(string s) {
    validateString(s);
    phone = s;
}

string Worker::getPhone() {
    return phone;
}

string Worker::getFactoryType() {
    return "worker";
}

string Worker::getParams() {
    return name + " " + surname + " " + patronymic + " " + job + " " + to_string(wage) + " " + address + " " + phone;
}

string Worker::getFormattedParams() {
    return "name: " + name + ", " + "surname: " + surname + ", " + "patronymic: " + patronymic + ", " + "job: " + job + ", " + "wage: " + to_string(wage) + ", " + "address: " + address + ", " + "phone: " + phone + ".\n";
}

void Worker::edit() {
    while (1) {
        cout << "Type command number(1 - edit name, 2 - edit surname, 3 - edit patronymic, 4 - edit job, 5 - edit wage, 6 - edit address, 7 - edit phone, 8 - exit editing): " << endl;
        int num; cin >> num;
        bool error = false;
        if (num == 1) {
            cout << "Type new name: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setName(value);
        } else if (num == 2) {
            cout << "Type new surname: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setSurname(value);
        } else if (num == 3) {
            cout << "Type new patronymic: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setPatro(value);
        } else if (num == 4) {
            cout << "Type new job: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setJob(value);
        } else if (num == 5) {
            cout << "Type new wage: " << endl;
            float value;
            cin >> value;
            try {
                validateFloat(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setWage(value);
        } else if (num == 6) {
            cout << "Type new address: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setAddress(value);
        } else if (num == 7) {
            cout << "Type new phone: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error)
                setPhone(value);
        } else if (num == 8) {
            break;
        } else {
            cout << "Such property is not specified. Try again." << endl;
        }
    }
}

istream& operator>>(istream &is, Worker &o) {
    float n; string s;
    cout << "name: "; cin >> s; o.setName(s);
    cout << "surname: "; cin >> s; o.setSurname(s);
    cout << "patronymic: "; cin >> s; o.setPatro(s);
    cout << "job: "; cin >> s; o.setJob(s);
    cout << "wage: "; cin >> n; o.setWage(n);
    cout << "address: "; cin >> s; o.setAddress(s);
    cout << "phone: "; cin >> s; o.setPhone(s);
    return is;
}