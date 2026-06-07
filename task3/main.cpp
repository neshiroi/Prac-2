#include "task3.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    int64_t c;
    int64_t m;

    cout << "Вычисление обратного элемента c^-1 mod m\n\n";

    cout << "Введите c: ";
    cin >> c;

    cout << "Введите m: ";
    cin >> m;

    int64_t d;
    int64_t u;
    int64_t v;

    extendedEuclid(
        c,
        m,
        d,
        u,
        v
    );

    if (d != 1) {

        cout << "\nОбратного элемента не существует,\n";
        cout << "так как gcd(c, m) != 1\n";

        return 0;
    }

    int64_t result = u % m;

    if (result < 0)
        result += m;

    cout << "\nОбратный элемент:\n";

    cout << c
         << "^-1 mod "
         << m
         << " = "
         << result
         << endl;

    cout << "\nПроверка:\n";

    cout << "("
         << c
         << " * "
         << result
         << ") mod "
         << m
         << " = "
         << (c * result) % m
         << endl;

    return 0;
}