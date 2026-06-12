#include <iostream>
#include <clocale>
#include "modular_power.h"      // isPrime, modNormalize, modPowBinary, modPowFermat
#include "extended_euclid.h"    // extendedEuclid
#include "modular_inverse.h"    // inverseMod
#include "shamir_cipher.h"      // shamirEncryptFile, shamirDecryptFile

using namespace std;

enum class MenuChoice {
    EXIT = 0,
    MOD_POWER = 1,          // задание 1 – возведение в степень по модулю
    EXTENDED_EUCLID = 2,    // задание 2 – расширенный алгоритм Евклида
    INVERSE_MOD = 3,        // задание 3 – обратный элемент по модулю
    SHAMIR = 4              // задание 4 – протокол Шамира
};

int main() {
    setlocale(LC_ALL, "Russian");
    int rawChoice;
    MenuChoice choice;

    do {
        cout << "\n=====================================\n";
        cout << "   Практическая работа №2\n";
        cout << "=====================================\n";
        cout << "1. Задание 1 – a^x mod p (бинарное возведение + Ферма)\n";
        cout << "2. Задание 2 – Расширенный алгоритм Евклида\n";
        cout << "3. Задание 3 – Обратный элемент c⁻¹ mod m\n";
        cout << "4. Задание 4 – Протокол Шамира (шифрование файлов)\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> rawChoice;

        choice = static_cast<MenuChoice>(rawChoice);

        switch (choice) {
            case MenuChoice::MOD_POWER: {
                int64_t a, x, p;
                cout << "\nЗадание 1: вычисление a^x mod p\n";
                cout << "Введите a, x, p (p должно быть простым): ";
                cin >> a >> x >> p;

                if (!isPrime(p)) {
                    cout << "Ошибка: p не является простым.\n";
                    break;
                }

                // Приведение a в диапазон [0, p-1]
                a = modNormalize(a, p);

                if (a == 0) {
                    cout << "a кратно p → a^x ≡ 0 (mod p).\n";
                    break;
                }

                // Проверка теоремы Ферма
                cout << "\nПроверка теоремы Ферма: a^(p-1) mod p = ";
                int64_t fermat = modPowBinary(a, p - 1, p, true);
                cout << " (должно быть 1)\n";

                // Сокращение показателя по модулю p-1
                int64_t reducedExp = x % (p - 1);
                cout << "Сокращаем степень: " << x << " mod " << p - 1 << " = " << reducedExp << "\n";
                cout << "Вычисляем a^" << reducedExp << " mod " << p << ":\n";
                int64_t result = modPowBinary(a, reducedExp, p, true);
                cout << "\nРезультат: " << a << "^" << x << " mod " << p << " = " << result << "\n";
                break;
            }

            case MenuChoice::EXTENDED_EUCLID: {
                cout << "\nЗадание 2: расширенный алгоритм Евклида\n";
                int64_t a, b, d, u, v;
                cout << "Введите два числа a и b: ";
                cin >> a >> b;

                extendedEuclid(a, b, d, u, v, true);  // true – показать таблицу

                cout << "\nРезультат:\n";
                cout << "НОД(" << a << ", " << b << ") = " << d << endl;
                cout << "Коэффициенты: u = " << u << ", v = " << v << endl;
                cout << "Проверка: " << a << "*" << u << " + " << b << "*" << v << " = " << a*u + b*v << endl;
                break;
            }

            case MenuChoice::INVERSE_MOD: {
                int64_t c, m;
                cout << "\nЗадание 3: вычислить c⁻¹ mod m\n";
                cout << "Введите c и m: ";
                cin >> c >> m;

                int64_t inv = inverseMod(c, m, true);   // true – показать ход вычислений
                if (inv == -1)
                    cout << "Обратного элемента не существует (НОД(c, m) != 1).\n";
                else
                    cout << "Ответ: " << c << "⁻¹ mod " << m << " = " << inv << "\n";
                break;
            }

            case MenuChoice::SHAMIR: {
                cout << "\nЗадание 4: протокол Шамира\n";
                int64_t p, ca, cb;
                cout << "Введите простое число p: ";
                cin >> p;

                if (!isPrime(p)) {
                    cout << "Ошибка: p не является простым.\n";
                    break;
                }

                cout << "Введите секретный ключ A (ca), 1 < ca < p-1, НОД(ca, p-1)=1: ";
                cin >> ca;
                cout << "Введите секретный ключ B (cb), 1 < cb < p-1, НОД(cb, p-1)=1: ";
                cin >> cb;

                // Вычисляем обратные ключи по модулю p-1
                int64_t da = inverseMod(ca, p - 1, false);
                int64_t db = inverseMod(cb, p - 1, false);

                if (da == -1 || db == -1) {
                    cout << "Ошибка: один из ключей не обратим по модулю p-1.\n";
                    break;
                }

                cout << "\nОткрытое простое число: p = " << p << endl;
                cout << "Ключи A: ca = " << ca << ", da = " << da << endl;
                cout << "Ключи B: cb = " << cb << ", db = " << db << endl;

                string inputFile, encryptedFile, outputFile;
                cout << "\nВведите имя входного файла для шифрования: ";
                cin >> inputFile;
                cout << "Введите имя файла для сохранения шифртекста: ";
                cin >> encryptedFile;
                cout << "Введите имя выходного файла после расшифрования: ";
                cin >> outputFile;

                // Шифрование
                shamirEncryptFile(inputFile, encryptedFile, p, ca, cb);
                // Расшифрование
                shamirDecryptFile(encryptedFile, outputFile, p, da, db);

                cout << "\nПроверка: сравните исходный файл \"" << inputFile
                     << "\" и расшифрованный \"" << outputFile << "\".\n";
                break;
            }

            case MenuChoice::EXIT:
                cout << "Выход из программы.\n";
                break;

            default:
                cout << "Неверный ввод. Повторите.\n";
                break;
        }
    } while (choice != MenuChoice::EXIT);

    return 0;
}