#include <iostream>
#include "Factory.h"
#include "Furniture.h"
#include "Vehicle.h"
#include "Worker.h"

class Keeper {
    public:
        int amount = 0;
        struct Node {
            Factory *data;
            struct Node *next;
        };
        Keeper();
        ~Keeper();
        
        void push(Factory *val);
        void pop(int num);
        Factory *get(int num);
        void display();
        void save();
        void load();
        void free();

        bool isEmpty();
        Node *getHead();

        void checkEmptiness();
    private:
        Node *head, *tail;
};