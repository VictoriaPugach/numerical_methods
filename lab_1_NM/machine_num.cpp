#include <iostream>
#include <limits>
#include <cmath>

int main() {
    for (auto type : {std::numeric_limits<float>::epsilon(), std::numeric_limits<double>::epsilon(), std::numeric_limits<long double>::epsilon()}) {
        std::cout << "\n";

        int k = 0;
        auto num = 1.0;

        while (num != 0) {
            num /= 2;
            k++;
        }
        std::cout << "zero is 2^-" << k << "\n";
        k = 0;
        num = 1.0;

        while (std::isfinite(num)) {
            num *= 2;
            k++;
        }
        std::cout << "infinity is 2^" << k << "\n";
        k = 0;
        num = 1.0;

        while (std::nextafter(1.0 + num, 2.0) > 1.0) {
            num /= 2;
            k++;
        }
        std::cout << "epsilon is 2^-" << k << "\n";
    }

    return 0;
}
