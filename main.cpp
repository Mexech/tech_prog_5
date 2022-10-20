/*
● Реализовать полное пользовательское меню согласно заданию. Не должно
быть аргументов, которые явно задаются в исходном коде, пользователь
имеет максимальные возможности при работе с программой, все параметры,
которые могут быть введены пользователем, вводятся с клавиатуры.
● У пользователя должен быть доступ для взаимодействия с каждым из
объектов-наследников: добавлять, удалять, выводить на экран, изменять
данные и пр.
● Создать все конструкторы (с параметрами, без параметров и копирования) и
деструктор, использовать переопределение операторов. Каждый вызов
конструктора и деструктора должен сопровождаться выводом этой
информации пользователю (какой объект, какой конструктор или деструктор
вызван).
● Определить в классе методы для просмотра и установки значений (set и get
функции).
● Определить исключения (exceptions) и применить в программе. Каждое
исключение должно сопровождаться текстом, поясняющим возникшую
исключительную ситуацию.
● Классы-наследники от базового класса должны определять свою сущность по
переменным и методам для работы с ними. Например, у животного есть тип,
пол, возраст, имя, хозяин, описание и т.д. В задании определено некоторое
описание характеристик.

Разработать класс Keeper, который реализует контейнер для хранения и обработки
объектов. Класс Keeper должен обеспечивать следующие функции:
▪ добавление и удаление производных объектов абстрактного класса Base (базовый
класс определяется согласно варианту задания);
▪ полное сохранение себя в файле;
▪ полное восстановление себя из файла.

Класс Фабрика хранит данные о мебели, работниках и машинах.Для мебели
определено: тип мебели, габариты (высота, ширина, глубина), цвет, материал,
стоимость. Для работника определено: ФИО, должность, заработная плата,
адрес проживания, телефон. Для машины определено: марка, модель,
гос.номер.
*/
#include <iostream>
#include "Keeper.h"

using namespace std;

void dispMenu() {
    cout << "1 - add new Factory\n2 - display factories\n3 - edit factory\n4 - remove Factory\n5 - load factories\n6 - save factories\n7 - exit\n";
}

int main() {
    Keeper k;
    while (1) {
        dispMenu();
        int num; cin >> num;
        if (num == 1) {
            cout << "Specify factory type(1 - furniture, 2 - vehicle, 3 - worker)" << endl;
            int val; cin >> val;
            if (val == 1) {
                Furniture *f = new Furniture;
                cin >> *f;
                k.push(f);
            } else if (val == 2) {
                Vehicle *f = new Vehicle;
                cin >> *f;
                k.push(f);
            } else if (val == 3) {
                Worker *f = new Worker;
                cin >> *f;
                k.push(f);
            } else {
                cout << "Such type doesn't exist. Try again" << endl;
            }
        } else if (num == 2) {
            try {
                k.display();
            } catch (const exception &e) {
                cout << "Keeper is empty." << endl;
            }
        } else if (num == 3) {
            cout << "Specify factory number to edit:" << endl;
            int val; cin >> val;
            if (val < 0 || val >= k.amount)
                cout << "Out of bounds. Try again." << endl;
            else 
                k.get(val)->edit();
        } else if (num == 4) {
            cout << "Specify factory number to remove:" << endl;
            int val; cin >> val;
            if (val < 0 || val >= k.amount)
                cout << "Out of bounds. Try again." << endl;
            else 
                k.pop(val);
        } else if (num == 5) {
            k.load();
        } else if (num == 6) {
            try {
                k.save();
            } catch (const exception &e) {
                cout << "Keeper is empty. Not saved." << endl;
            }
        } else if (num == 7) {
            break;
        } else {
            cout << "No such command. Try again." << endl;
        }
    }
}