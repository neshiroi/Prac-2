#include "task6.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    cout << "Задание 6\n";
    cout << "Представление числа в виде цепной дроби\n";
    cout << "и решение диофантова уравнения\n\n";

    cout << "Вариант 2:\n";
    cout << "275a + 145b = 10\n";

    continuedFraction(
        275,
        145
    );

    solveEquation(
        275,
        145,
        10
    );

    return 0;
}