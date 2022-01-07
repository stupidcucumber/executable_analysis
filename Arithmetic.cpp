#include "Arithmetic.h"

namespace analysis{
    long double Summation::sum(long long first_index, long long last_index) {
        long double s = 0;
        for(long long i = first_index; i <= last_index; i++){
            s += function.call(i);
        }

        return s;
    }

    long double Summation::infSum(long long int first_index) {
        long double s;
        if(function.isConverge()){
            s = 0;
            long double term;
            for(long long i = first_index; i < LONG_LONG_MAX; i++){
                term = function.call(i);
                if(abs(term) < epsilon) break;
                s += term;
            }
        }else{
            s = std::numeric_limits<long double>::infinity();
        }

        return s;
    }

    long double Multiplication::product(long long int first_index, long long int last_index) {
        long double p = 1;
        for(long long i = first_index; i <= last_index; i++){
            if(function.call(i) != 0)
                p *= function.call(i);
            else return 0;
        }
        return p;
    }
}
