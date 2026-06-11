#include "shamir_cipher.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    string inputFile;
    string encryptedFile;
    string outputFile;

    cout << "Протокол Шамира\n";
    cout << "Шифрование и расшифрование файла\n\n";

    cout << "Введите имя входного файла: ";
    cin >> inputFile;

    cout << "Введите имя файла шифртекста: ";
    cin >> encryptedFile;

    cout << "Введите имя файла расшифровки: ";
    cin >> outputFile;

    int64_t p = 257;

    int64_t ca = 3;
    int64_t cb = 5;

    int64_t da = inverseMod(
        ca,
        p - 1
    );

    int64_t db = inverseMod(
        cb,
        p - 1
    );

    cout << "\nПараметры протокола\n";

    cout << "p = " << p << endl;
    cout << "ca = " << ca << endl;
    cout << "cb = " << cb << endl;
    cout << "da = " << da << endl;
    cout << "db = " << db << endl;

    cout << "\nНачало шифрования...\n";

    shamirEncryptFile(
        inputFile,
        encryptedFile,
        p,
        ca,
        cb
    );

    cout << "\nНачало расшифрования...\n";

    shamirDecryptFile(
        encryptedFile,
        outputFile,
        p,
        da,
        db
    );

    cout << "\nРабота программы завершена\n";

    return 0;
}