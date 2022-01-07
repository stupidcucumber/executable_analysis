#include <iostream>
#include "Functions.h"

using namespace std;
using namespace analysis;

long double f(long double x){
    return x * 2;
}

int main() {
    Function test(f);
    cout<<test.call(2);
}
