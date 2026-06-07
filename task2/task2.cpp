#include "task2.h"

using namespace std;

void extendedEuclid(
    int64_t a,
    int64_t b,
    int64_t &d,
    int64_t &u,
    int64_t &v,
    bool show
) {

    int64_t old_r = a;
    int64_t r = b;

    int64_t old_u = 1;
    int64_t cur_u = 0;

    int64_t old_v = 0;
    int64_t cur_v = 1;

    if (show) {

        cout << "\nРасширенный алгоритм Евклида\n";
        cout << "r1\t r2\t q\t u\t v\n";
    }

    while (r != 0) {

        int64_t q = old_r / r;

        int64_t temp_r = old_r - q * r;
        old_r = r;
        r = temp_r;

        int64_t temp_u = old_u - q * cur_u;
        old_u = cur_u;
        cur_u = temp_u;

        int64_t temp_v = old_v - q * cur_v;
        old_v = cur_v;
        cur_v = temp_v;

        if (show) {

            cout << old_r
                 << "\t "
                 << r
                 << "\t "
                 << q
                 << "\t "
                 << old_u
                 << "\t "
                 << old_v
                 << endl;
        }
    }

    d = old_r;
    u = old_u;
    v = old_v;
}