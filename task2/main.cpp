#include "task2.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    int64_t c;
    int64_t m;

    cout << "Введите c и m: ";
    cin >> c >> m;

    int64_t d;
    int64_t u;
    int64_t v;

    extendedEuclid(
        c,
        m,
        d,
        u,
        v,
        true
    );

    if (d != 1) {

        cout << "\nОбратного элемента нет\n";
        return 0;
    }

    int64_t result = u % m;

    if (result < 0)
        result += m;

    cout << "\nОтвет d = " << result << endl;

    cout << "Проверка: ("
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