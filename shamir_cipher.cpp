#include "shamir_cipher.h"

using namespace std;

int64_t modPow(
    int64_t a,
    int64_t x,
    int64_t p
) {
    int64_t result = 1;
    a %= p;

    while (x > 0) {
        if (x % 2 == 1) {
            result = (result * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }

    return result;
}

int64_t inverseMod(
    int64_t c,
    int64_t m
) {
    int64_t a = c;
    int64_t b = m;

    int64_t u1 = 1;
    int64_t u2 = 0;

    while (b != 0) {
        int64_t q = a / b;
        int64_t r = a % b;

        a = b;
        b = r;

        int64_t temp = u1 - q * u2;
        u1 = u2;
        u2 = temp;
    }

    int64_t result = u1 % m;
    if (result < 0) result += m;

    return result;
}

void shamirEncryptFile(
    const string &inputFile,
    const string &encryptedFile,
    int64_t p,
    int64_t ca,
    int64_t cb
) {
    ifstream in(inputFile, ios::binary);
    if (!in) {
        cout << "Ошибка открытия входного файла\n";
        return;
    }

    ofstream out(encryptedFile);
    if (!out) {
        cout << "Ошибка создания файла шифртекста\n";
        return;
    }

    cout << "\nШифрование Шамира\n";

    char ch;
    int index = 0;

    while (in.get(ch)) {
        int64_t m = static_cast<unsigned char>(ch);

        int64_t x1 = modPow(m, ca, p);
        int64_t x2 = modPow(x1, cb, p);

        cout << "\nБайт " << index << endl;
        cout << "Исходный m = " << m << endl;
        cout << "1) A вычисляет x1 = m^ca mod p = " << x1 << endl;
        cout << "2) B вычисляет x2 = x1^cb mod p = " << x2 << endl;

        out << x2 << " ";
        ++index;
    }

    cout << "\nФайл зашифрован\n";
}

void shamirDecryptFile(
    const string &encryptedFile,
    const string &outputFile,
    int64_t p,
    int64_t da,
    int64_t db
) {
    ifstream in(encryptedFile);
    if (!in) {
        cout << "Ошибка открытия шифртекста\n";
        return;
    }

    ofstream out(outputFile, ios::binary);
    if (!out) {
        cout << "Ошибка создания выходного файла\n";
        return;
    }

    cout << "\nРасшифрование Шамира\n";

    int64_t x2;
    int index = 0;

    while (in >> x2) {
        int64_t x3 = modPow(x2, da, p);
        int64_t m = modPow(x3, db, p);

        cout << "\nБлок " << index << endl;
        cout << "Получено x2 = " << x2 << endl;
        cout << "1) A снимает свой ключ: x3 = x2^da mod p = " << x3 << endl;
        cout << "2) B снимает свой ключ: m = x3^db mod p = " << m << endl;

        out.put(static_cast<char>(m));
        ++index;
    }

    cout << "\nФайл расшифрован\n";
}