#include "modular_inverse.h"

using namespace std;

void extendedEuclid(
    int64_t a,
    int64_t b,
    int64_t &d,
    int64_t &u,
    int64_t &v
) {
    int64_t old_r = a;
    int64_t r = b;

    int64_t old_u = 1;
    int64_t cur_u = 0;

    int64_t old_v = 0;
    int64_t cur_v = 1;

    cout << "\nРасширенный алгоритм Евклида\n";
    cout << "r1\t\tr2\t\tq\t\tu\t\tv\n";
    cout << old_r << "\t\t" << r << "\t\t-\t\t" << old_u << "\t\t" << old_v << endl;

    while (r != 0) {
        int64_t q = old_r / r;

        int64_t temp_r = old_r - q * r;
        int64_t temp_u = old_u - q * cur_u;
        int64_t temp_v = old_v - q * cur_v;

        old_r = r;
        r = temp_r;

        old_u = cur_u;
        cur_u = temp_u;

        old_v = cur_v;
        cur_v = temp_v;

        cout << old_r << "\t\t" << r << "\t\t" << q << "\t\t" << old_u << "\t\t" << old_v << endl;
    }

    d = old_r;
    u = old_u;
    v = old_v;

    cout << "\nНОД = " << d << endl;
    cout << "u = " << u << endl;
    cout << "v = " << v << endl;
    cout << "Проверка: " << a << " * " << u << " + " << b << " * " << v << " = " << a * u + b * v << endl;
}