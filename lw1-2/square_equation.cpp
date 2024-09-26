#include <cmath>
#include <iostream>


int main()
{
    float a, b, c, d, x1, x2;

    std::cout << "Введите коэффициенты квадратного уравнения: " << std::endl;
    std::cout << "a = ";
    std::cin >> a;

    std::cout << "b = ";
    std::cin >> b;

    std::cout << "c = ";
    std::cin >> c;
    d = b * b - 4 * a * c;
    if (d < 0)
    {
        std::cout << "D < 0, корней нет" << std::endl;
    }
    else
    {
        x1 = (- b + std::sqrt(d)) / (2 * a);
        x2 = (- b - std::sqrt(d)) / (2 * a);

        std::cout << "Корни квадратного уравнения " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
        std::cout << "x1 = " << x1 << std::endl;
        std::cout << "x2 = " << x2 << std::endl;
    }

    return 0;
}