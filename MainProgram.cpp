#include <iostream>
#include <string>
#include <cmath>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Rectangle; // forward declaration

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

    // Friend class declaration
    friend class Rectangle;
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
        return std::abs(bottomRight.x - topLeft.x);
    }

    // Height
    double getHeight() const {
        return std::abs(topLeft.y - bottomRight.y);
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
        std::cout << std::endl;
    }

    // Friend function
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// Friend function implementation
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getWidth() == r2.getWidth() &&
            r1.getHeight() == r2.getHeight());
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

    std::cout << "Area r1: " << r1.getArea() << std::endl;
    std::cout << "Area r2: " << r2.getArea() << std::endl;

    if (isSameSize(r1, r2)) {
        std::cout << "Rectangles are the same size.\n";
    } else {
        std::cout << "Rectangles are NOT the same size.\n";
    }

    // ConstDemo
    ConstDemo obj(10);
    std::cout << "Value: " << obj.getValue() << std::endl;
    std::cout << "Double (const): " << obj.constGetDouble() << std::endl;

    obj.doubleValue();
    std::cout << "After doubling: " << obj.getValue() << std::endl;

    return 0;
}
