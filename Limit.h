#ifndef EXECUTABLE_ANALYSIS_LIMIT_H
#define EXECUTABLE_ANALYSIS_LIMIT_H
#include <iostream>
#include "Functions.h"
#include "Arithmetic.h"

namespace analysis{
    /**
     * This function finds the infinity limit of the given function
     * @tparam T
     * @return
     */
    long double findLimit(nFunction function, long long int accuracy = INT_MAX){
        return function.call(accuracy);
    }

    /*
    long double findLimit(nFunction function){
        long double sum;
        for(long long int i = 1; i < LONG_LONG_MAX; i++){
            sum += function.call(i);
        }
        return sum / LONG_LONG_MAX;
    }*/
    /*//TODO: Make limits for complex functions
    long double findLimit(cFunction function){
        long double sum;
        for(long long int i = 1; i < LONG_LONG_MAX; i++){
            sum += function.call(i);
        }
        return sum / LONG_LONG_MAX;
    }*/

    /**
     * This function finds the limit of the given function
     * @tparam T
     * @return
     */

    long double findLimit(Function function, long double arg){
        long double plus_e = function.call((arg + epsilon));
        long double minus_e = function.call((arg - epsilon));
        if(abs(plus_e-minus_e)<epsilon) return (plus_e+minus_e)/2;
        else throw std::logic_error("Limit does not exist");
    }

    long double findRightLimit(Function function, long double arg){
        return function.call(arg + epsilon);
    }

    long double findLeftLimit(Function function, long double arg){
        return function.call(arg - epsilon);
    }
}


#endif //EXECUTABLE_ANALYSIS_LIMIT_H
