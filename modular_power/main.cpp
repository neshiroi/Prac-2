#include "modular_power.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    int64_t a;
    int64_t x;
    int64_t p;

    cout << "Введите a x p: ";
    cin >> a >> x >> p;

    cout << "\nПроверка p:\n";

    if (isPrime(p))
        cout << "p простое\n";
    else
        cout << "p не простое\n";

    cout << "\nБинарный алгоритм\n";

    int64_t r1 = modPowBinary(
        a,
        x,
        p,
        true
    );

    cout << "\nОтвет = " << r1 << endl;

    if (
        isPrime(p) &&
        gcd(modNormalize(a, p), p) == 1
    ) {

        cout << "\nАлгоритм Ферма\n";

        int64_t r2 = modPowFermat(
            a,
            x,
            p,
            true
        );

        cout << "\nОтвет = " << r2 << endl;
    }

    else {

        cout << "\nТеорема Ферма неприменима\n";
    }

    return 0;
}