#include <iostream>

int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    int gcd = gcd_recursive(num1, num2);
    std::cout << "GCD of " << num1 << " and " << num2 << " is " << gcd << std::endl;

    return 0;
}
