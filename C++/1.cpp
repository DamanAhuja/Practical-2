#include <iostream>
#include <cmath>

double seriessum(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {      //initaiating a loop till n
        double term = pow(-1, i + 1) * (1.0 / pow(i, i));          // pow(+1,i+1) regulates the sign of the term alternatively
        sum += term;
    }
    return sum;
}

int main() {
    int n;
    std::cout << "Enter the number of terms: ";
    std::cin >> n;      // taking input 

    double series_sum = seriessum(n);
    std::cout << "Sum of the first " << n << " terms of the series: " << series_sum << std::endl;

    return 0;
}
