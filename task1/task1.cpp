#include "task1.h"

using namespace std;

bool isPrime(int64_t n) {

    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int64_t i = 3; i <= n / i; i += 2) {

        if (n % i == 0)
            return false;
    }

    return true;
}

int64_t modNormalize(
    int64_t a,
    int64_t m
) {

    int64_t r = a % m;

    if (r < 0)
        r += m;

    return r;
}

int64_t modPowBinary(
    int64_t a,
    int64_t x,
    int64_t p,
    bool show
) {

    a = modNormalize(a, p);

    int64_t result = 1;

    if (show) {

        cout << "\nБинарное возведение в степень\n";
        cout << "a = " << a << ", x = " << x << ", p = " << p << endl;
    }

    int step = 0;

    while (x > 0) {

        if (show) {

            cout << "Шаг "
                 << step
                 << ": a = "
                 << a
                 << ", x = "
                 << x
                 << ", result = "
                 << result
                 << endl;
        }

        if (x % 2 == 1) {

            result = (result * a) % p;
        }

        a = (a * a) % p;

        x /= 2;

        step++;
    }

    return result;
}

int64_t modPowFermat(
    int64_t a,
    int64_t x,
    int64_t p,
    bool show
) {

    if (!isPrime(p)) {

        cout << "p не является простым\n";
        return 0;
    }

    if (gcd(a, p) != 1) {

        cout << "gcd(a, p) != 1\n";
        return 0;
    }

    int64_t reduced = x % (p - 1);

    if (show) {

        cout << "\nТеорема Ферма\n";
        cout << "x mod (p - 1) = " << reduced << endl;
    }

    return modPowBinary(
        a,
        reduced,
        p,
        show
    );
}