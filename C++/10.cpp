#include <iostream>
#include <cmath>
#include <stdexcept>

class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
            throw std::invalid_argument("All sides must be greater than 0");
        }
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            throw std::invalid_argument("Sum of any two sides must be greater than the third side");
        }
    }

    double area() const {
        double s = (side1 + side2 + side3) / 2.0;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double area(double base, double height) const {
        if (base <= 0 || height <= 0) {
            throw std::invalid_argument("Base and height must be greater than 0.");
        }
        return 0.5 * base * height;
    }
};

int main() {
    try {
        // Creating a triangle
        double side1, side2, side3;
        std::cout << "Enter the lengths of the three sides of the triangle: ";
        std::cin >> side1 >> side2 >> side3;

        Triangle triangle(side1, side2, side3);

        // If the triangle is a right-angled triangle, calculate and display its area
        if (side1 * side1 + side2 * side2 == side3 * side3) {
            std::cout << "The triangle is a right-angled triangle." << std::endl;
            std::cout << "Area of the triangle using base and height: " << triangle.area(side1, side2) << std::endl;
        }
        else if (side1 * side1 + side3 * side3 == side2 * side2) {
            std::cout << "The triangle is a right-angled triangle." << std::endl;
            std::cout << "Area of the triangle using base and height: " << triangle.area(side1, side3) << std::endl;
        }
        else if (side2 * side2 + side3 * side3 == side1 * side1) {
            std::cout << "The triangle is a right-angled triangle." << std::endl;
            std::cout << "Area of the triangle using base and height: " << triangle.area(side2, side3) << std::endl;
        }
        else {
            std::cout << "Area of the triangle using Heron's formula: " << triangle.area() << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid triangle: " << e.what() << std::endl;
    }

    return 0;
}
