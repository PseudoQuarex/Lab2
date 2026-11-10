#include <iostream>

// Инициализация полей класса в списке инициализации конструктора, композиция

class Point {
    protected:
    int x, y;
public:
    Point() {
        std::cout << "Point()\n";
        x = 0;
        y = 0;
    }
    Point(int _x, int _y) : x(_x), y(_y) {
        std::cout << "Point(int x, int y)\n";
    }
    Point(const Point &p) {
        std::cout << "Point(const Point &p)\n";
        x = p.x;
        y = p.y;
    }
    ~Point() {
        // std::cout << x << " " << y << std::endl;
        std::cout << "~Point\n";
    }
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    void reset();

    void getter() {
        std::cout << x << " " << y << std::endl;
    };
};

void Point::reset() {
    x = 0;
    y = 0;
}

class ColoredPoint: public Point {
protected:
    int color;
public:
    ColoredPoint() : Point(), color(0) {
        std::cout << "ColoredPoint()\n";
    }
    ColoredPoint(int x, int y, int color) : Point(x, y), color(color) {
        std::cout << "ColoredPoint(int x, int y, int color)\n";
    }
    ColoredPoint(const ColoredPoint &p) : color(p.color) {
        std::cout << "ColoredPoint(const Point &p)\n";
    }
    ~ColoredPoint() {
        // std::cout << x << " " << y << " color: " << color << std::endl;
        std::cout << "~ColoredPoint\n";
    }
    void change_color(int new_color) {
        color = new_color;
    }
    void getter() {
        std::cout << x << " " << y << " " << color << std::endl;
    };
};

class Section {
protected:
    Point *p1;
    Point *p2;
public:
    Section() {
        std::cout << "Section()\n";
        p1 = new Point;
        p2 = new Point;
    }
    Section(int x1, int y1, int x2, int y2) {
        std::cout << "Section(int x, int y)\n";
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }
    Section(const Section &s) {
        std::cout << "Section(const Section &s)\n";
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
    }
    ~Section() {
        // std::cout << x << " " << y << std::endl;
        delete p1;
        delete p2;
        std::cout << "~Section\n";
    }
};

class Triangle {
protected:
    Point p1;
    Point p2;
    Point p3;
public:
    Triangle() : p1(Point()), p2(Point()), p3(Point()) {
        std::cout << "Triangle()" << std::endl; 
    }
    ~Triangle() {
        std::cout << "~Triangle()" << std::endl; 
    }
};

int main () {

    Section *s1 = new Section();
    Section *s2 = new Section(*s1);

    Triangle *t1 = new Triangle(); // Сначала создаются объекты класса Point, потом Triangle. Удаление: Triangle, потом Point

    delete s1;
    delete s2;
    delete t1;

    return 0;
}