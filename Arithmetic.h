#ifndef EXECUTABLE_ANALYSIS_ARITHMETIC_H
#define EXECUTABLE_ANALYSIS_ARITHMETIC_H

#include "Functions.h"

namespace analysis{

    class Summation{
    private:
        nFunction function;
    public:
        explicit Summation(nFunction f){
           function = f;
        }

        /**
         * Takes first_index as the first argument, last_index as the last argument to a function and sums up.
         * @return the sum of function's values between first and las argument.
         */
        long double sum(long long int first_index, long long int last_index);
        long double infSum(long long int first_index);
    };

    class Multiplication{
    private:
        nFunction function;
    public:
        explicit Multiplication(nFunction f){
            function = f;
        }

        /**
         * Takes first_index as the first argument, last_index as the last argument to a function and sums up.
         * @return the sum of function's values between first and las argument.
         */
        long double product(long long int first_index, long long int last_index);
    };
}

#endif //EXECUTABLE_ANALYSIS_ARITHMETIC_H