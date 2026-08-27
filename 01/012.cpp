#include <iostream>
#include <iomanip>

int main() {
    float a, b;
    std::cin >> a >> b;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << a << " + " << b << " = " << a+b << std::endl;
    std::cout << a << " - " << b << " = " << a-b << std::endl;
    std::cout << a << " * " << b << " = " << a*b << std::endl;
    std::cout << a << " / " << b << " = " << a/b << std::endl;
    return 0;
}
