#include "Arithmetic.h"
#include "CONSTANTS.h"

namespace analysis{
    long double Summation::sum(long long first_index, long long last_index) {
        long double s = 0;
        for(long long i = first_index; i <= last_index - 1; i++){
            s += function.call(i);
        }

        return s;
    }
    /*
     * x -> 0: f(x) ~ b + o(x), b є R
     */

    long double Summation::infSum(long long int first_index) {//TODO: rework by using Limit
        long double s;
        if(true){
            s = 0;
            long double term;
            for(long long i = first_index; i < LONG_LONG_MAX - 1; i++){
                term = function.call(i);
                if(abs(term) < epsilon) break;
                s += term;
            }
        }else{
            s = std::numeric_limits<long double>::infinity();
        }

        return s;
     }

    bool Summation::isConverge() {
        if( abs(sum(LONG_LONG_MAX - rangeElements, LONG_LONG_MAX)) < epsilon )
            return true;
        return false;
    }


    bool Multiplication::isConverge() {
        if(abs(product(0,LONG_LONG_MAX-rangeElements)-product(0,LONG_LONG_MAX)<epsilon))  return true;
        else return false;
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

    long long Multiplication::factorial(long long int input, bool d){
        long long result =1;
        if(!d){
            for(int i=1;i<=input;i++){
                result*=i;
            }
        }else{
            if(input%2){
                for(int i=1;i<=input;i+=2){
                    result*=i;
                }
            }else{
                for(int i=2;i<=input;i+=2){
                    result*=i;
                }
            }
        }
        return result;
    }

    long double Multiplication::infProduct(long long int first_index) {//TODO: rework by using Limit
        long double p = 1;
        long double a = function.call(first_index);
        if(isConverge()){
            for(long long int i = first_index + 1; abs(a) >= 1; i++){
                if(a < epsilon){
                    return 0;
                }
                p *= a;
                a = function.call(i);
            }
        }else{
            p = std::numeric_limits<long double>::infinity();
        }

        return p;
    }
}
