#include <iostream>

//Создание: классов, атрибутов, конструкторов, статических объектов, динамических объектов, объектов с помощью различных конструкторов
//Уничтожение: статически созданных объектов, динамически созданных объектов

class Point {
public:
    int x, y;
    Point() {
        std::cout << "Point()\n";
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        std::cout << "Point(int x, int y)\n";
        this->x = x;
        this->y = y;
    }
    Point(const Point &p) {
        std::cout << "Point(const Point &p)\n";
        x = p.x;
        y = p.y;
    }
    ~Point() {
        std::cout << x << " " << y << std::endl;
        std::cout << "~Point\n";
    }
};

int main () {

    Point p;
    Point p2(10, 20);
    Point p3(p2);

    Point *d = new Point;
    Point *d2 = new Point(10, 20);
    Point *d3 = new Point(*d2);

    delete d;
    delete d2;
    delete d3;

    return 0;
}