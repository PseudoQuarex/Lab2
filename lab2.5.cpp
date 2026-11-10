#include <iostream>

// Присваивание: помещение объектов в переменные различных типов

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

class ColoredPoint: public Point {
protected:
    int color;
public:
    ColoredPoint() : Point() {
        std::cout << "ColoredPoint()\n";
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x, y) {
        std::cout << "ColoredPoint(int x, int y, int color)\n";
        this->color = color;
    }
    ColoredPoint(const ColoredPoint &p) {
        std::cout << "ColoredPoint(const Point &p)\n";
        color = p.color;
    }
    ~ColoredPoint() {
        std::cout << x << " " << y << " color: " << color << std::endl;
        std::cout << "~ColoredPoint\n";
    }
    void change_color(int new_color) {
        color = new_color;
    }
    void reset();
};

int main () {

    Point *p1 = new ColoredPoint(1, 2, 42);
    ColoredPoint *p2 = new ColoredPoint(1, 2, 42);

    delete p1;
    delete p2;

    return 0;
}