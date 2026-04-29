#include <iostream>
#include <cmath>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
    double x;
    double y;

public:
    // Constructor
    Point(double x, double y) : x(x), y(y) {}

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }

    // Display
    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};


class Rectangle {
private:
    Point topLeft;
    Point bottomRight;

public:
    // Constructor
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // Width
    double getWidth() const {
        return std::abs(bottomRight.getX() - topLeft.getX());
    }

    // Height
    double getHeight() const {
        return std::abs(topLeft.getY() - bottomRight.getY());
    }

    // Area
    double getArea() const {
        return getWidth() * getHeight();
    }

    // Display
    void display() const {
        std::cout << "Top Left: ";
        topLeft.display();
        std::cout << ", Bottom Right: ";
        bottomRight.display();
        std::cout << '\n';
    }

    // Friend function
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// Friend function implementation (FIXED: double comparison)
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    const double EPSILON = 1e-9;

    return (std::abs(r1.getWidth() - r2.getWidth()) < EPSILON &&
            std::abs(r1.getHeight() - r2.getHeight()) < EPSILON);
}


class ConstDemo {
private:
    int value;

public:
    // Constructor
    ConstDemo(int v) : value(v) {}

    // Const getter
    int getValue() const { return value; }

    // Non-const modifier
    void doubleValue() {
        value *= 2;
    }

    // Const function
    int constGetDouble() const {
        return value * 2;
    }
};


// ============================================================
// MAIN
// ============================================================

int main() {
    // Rectangle demo
    Rectangle r1(0, 10, 5, 0);
    Rectangle r2(2, 8, 7, 0);

    r1.display();
    r2.display();

    std::cout << "Area r1: " << r1.getArea() << '\n';
    std::cout << "Area r2: " << r2.getArea() << '\n';

    if (isSameSize(r1, r2)) {
        std::cout << "Rectangles are the same size.\n";
    } else {
        std::cout << "Rectangles are NOT the same size.\n";
    }

    // ConstDemo
    ConstDemo obj(10);

    std::cout << "Value: " << obj.getValue() << '\n';
    std::cout << "Double (const): " << obj.constGetDouble() << '\n';

    obj.doubleValue();

    std::cout << "After doubling: " << obj.getValue() << '\n';

    return 0;
}
