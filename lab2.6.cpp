#include <iostream>

// Копирование: объектов в объекты, указателей в указатели

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
        std::cout << x << " " << y << std::endl;
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
        Point::getter();
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

    // Копирование объекта в объект
    Point *p1 = new Point();
    Point *p2 = new Point(2,5);

    *p1 = *p2;

    p2->move(4,4);

    delete p1;
    delete p2;


    // Копирование указателя в указатель
    Point *p3 = new Point();
    Point *p4 = p3;

    p3->move(4,4);
    p4->move(1,1);

    std::cout << "p3: ";
    p3->getter();
    std::cout << "p4: ";
    p4->getter();

    delete p3;
    p4 = nullptr;

    return 0;
}