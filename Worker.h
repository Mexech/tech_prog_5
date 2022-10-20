#include "Factory.h"

using namespace std;

class Worker: public Factory {
    private:
        string name;
        string surname;
        string patronymic;
        string job;
        float wage;
        string address;
        string phone;
    public:
        Worker();
        Worker(string name, string surname, string patronymic, string job, float wage, string address, string phone);
        Worker(const Worker &o);
        ~Worker();

        void setName(string s);
        string getName();
        void setSurname(string s);
        string getSurname();
        void setPatro(string s);
        string getPatro();
        void setJob(string s);
        string getJob();
        void setWage(float n);
        float getWage();
        void setAddress(string s);
        string getAddress();
        void setPhone(string s);
        string getPhone();

        string getFactoryType();
        string getParams();
        string getFormattedParams();
        void edit();

        friend istream& operator>>(istream &is, Worker &o);
};