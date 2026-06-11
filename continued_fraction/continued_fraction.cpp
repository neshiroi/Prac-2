#include "continued_fraction.h"

using namespace std;

void continuedFraction(
    int64_t a,
    int64_t b
) {
    vector<int64_t> q;

    cout << "\nЦепная дробь\n";

    while (b != 0) {
        int64_t div = a / b;
        int64_t r = a % b;

        q.push_back(div);

        cout << a << " = " << b << " * " << div << " + " << r << endl;

        a = b;
        b = r;
    }

    cout << "\n[ ";
    for (size_t i = 0; i < q.size(); ++i) {
        cout << q[i];
        if (i + 1 != q.size()) cout << ", ";
    }
    cout << " ]\n";
}

void solveEquation(
    int64_t A,
    int64_t B,
    int64_t D
) {
    int64_t old_r = A;
    int64_t r = B;

    int64_t old_u = 1;
    int64_t cur_u = 0;

    int64_t old_v = 0;
    int64_t cur_v = 1;

    cout << "\nРешение уравнения расширенным алгоритмом Евклида\n";
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

    int64_t gcd = old_r;

    cout << "\nНОД = " << gcd << endl;

    if (D % gcd != 0) {
        cout << "Решений нет\n";
        return;
    }

    int64_t mult = D / gcd;
    int64_t a = old_u * mult;
    int64_t b = old_v * mult;

    cout << "\nЧастное решение\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "\nПроверка:\n";
    cout << A << " * " << a << " + " << B << " * " << b << " = " << A * a + B * b << endl;

    cout << "\nОбщее решение\n";
    cout << "a = " << a << " + " << B / gcd << " * t\n";
    cout << "b = " << b << " - " << A / gcd << " * t\n";
}