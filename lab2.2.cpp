#include <iostream>

//Создание: динамических объектов, объектов с помощью различных конструкторов
//Уничтожение: динамических объектов

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

    Point *p = new Point;
    Point *p2 = new Point(10, 20);
    Point *p3 = new Point(*p2);

    delete p;
    delete p2;
    delete p3;

    return 0;
}