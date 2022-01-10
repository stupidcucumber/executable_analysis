#include <iostream>
#include "Functions.h"
#include "Arithmetic.h"
#include "Limit.h"

using namespace std;
using namespace analysis;

long double f(long long x){
    return x;
}

long double g(long long x){
    nFunction rec(f);
    Multiplication k(rec);
    return 1.0/k.factorial(x);
}

// Sigma 1/k! -> e, n -> inf

long double h(long long a){
    return pow(1 + 1.0/a, a);
} // (1 + 1/n)^n

int main() {
    nFunction test(g);
    cout << findLimit(test) << endl;
}
