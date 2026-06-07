#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

using namespace std;

int64_t modPow(
    int64_t a,
    int64_t x,
    int64_t p
);

int64_t inverseMod(
    int64_t c,
    int64_t m
);

void shamirEncryptFile(
    const string &inputFile,
    const string &encryptedFile,
    int64_t p,
    int64_t ca,
    int64_t cb
);

void shamirDecryptFile(
    const string &encryptedFile,
    const string &outputFile,
    int64_t p,
    int64_t da,
    int64_t db
);