#ifndef EXECUTABLE_ANALYSIS_FUNCTIONS_H
#define EXECUTABLE_ANALYSIS_FUNCTIONS_H

#include "cmath"
#include "climits"

typedef long double (*FUNCTION_N_)(long long int); //Type of function's address with natural argument
typedef long double (*FUNCTION_R_)(long double); //Type of function's address with real argument
typedef long double (*FUNCTION_C_)(/*TODO: make functionality for ComplexNumber*/); //Type of function's address with complex argument

const long double epsilon = 1e-20;

namespace analysis{

    class Function{
    private:
        FUNCTION_R_ func;
    public:
        explicit Function(FUNCTION_R_ f){
            func = f;
        }

        long  double call(long double x){
            return func(x);
        }


        FUNCTION_R_ getFunction(){
            return func;
        }

        void setFunction(FUNCTION_R_ function){
            func = function;
        }

        void operator=(Function f){(*this).setFunction(f.getFunction());}
        Function operator+(Function f){//TODO: check whether it can be done using lambda expressions

        }
        Function operator-(Function f);
        Function operator/(Function f);
        Function operator*(Function f);
        Function operator^(Function f);
    };

    /**
     * This class defines a function with natural argument
     */
    class nFunction{
    private:
        FUNCTION_N_ func;
        bool converge;
    public:
        explicit nFunction(FUNCTION_N_ f){
            func = f;
        }

        nFunction(){

        };

        long double call(long long int x){
            return func(x);
        }

        FUNCTION_N_ getFunction(){
            return func;
        }

        void setFunction(FUNCTION_N_ function){
            func = function;
        }

        /**
         * Very bad function to test convergence of a function.
         * @return
         */
        bool isConverge(){//TODO: Check whether there is another way to test functions on convergence!
            for(long long int i = LONG_LONG_MAX - 1000; i < LONG_LONG_MAX - 1; i++){
                if( abs(func(i + 1) - func(i)) > epsilon) return false;
            }
            return true;
        }

        void operator=(nFunction f){(*this).setFunction(f.getFunction());}
        nFunction operator+(nFunction f){

        }
        nFunction operator-(nFunction f);
        nFunction operator/(nFunction f);
        nFunction operator*(nFunction f);
        nFunction operator^(nFunction f);
    };

}
#endif //EXECUTABLE_ANALYSIS_FUNCTIONS_H
