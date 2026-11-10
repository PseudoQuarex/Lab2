#include <iostream>

//Определения: доступности атрибутов и методов
//Реализация: методов объектов, методов объектов в определении или после, конструкторов, деструкторов

class Point {
protected:
    int x, y;
public:
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

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void reset();
};

void Point::reset() {
    x = 0;
    y = 0;
}

int main () {

    Point *p = new Point(1,2);

    p->reset();
    p->move(10,10);

    delete p;

    return 0;
}