#pragma once

#include <iostream>
#include <cstdint>
#include <numeric>

using namespace std;

bool isPrime(int64_t n);

int64_t modNormalize(
    int64_t a,
    int64_t m
);

int64_t modPowBinary(
    int64_t a,
    int64_t x,
    int64_t p,
    bool show 
);

int64_t modPowFermat(
    int64_t a,
    int64_t x,
    int64_t p,
    bool show
);