#include <iostream>     // to use the cout and cin function
#include <cmath>    // to use the "pow" function
#include <climits>  // to use function to show the sizes of each integral data types
#include <float.h>  // to use std::fixed function to show the amount of digits we can trust for a 'float' value
#define G 10    // another option for creating a const variable that cannot be changed that can be used in the entire program

// could use: using namespace std;
// could also use: using std::cout;
//                 using std::cin;

// convention to put declaration above main function and put definition below main function

//declarations:
double power(double, int);

void print_pow(double, int);


int main()
{
    std::cout << "Hello World\n";

    int slices;
    std::cout << "How many slices of pizza do you want? ";
    std::cin >> slices;
    std::cout << "You have " << slices << " slices of pizza." << std::endl; // alternatively put '\n' instead of "<< std::endl"
    printf("You have %i slices of pizza.\n", slices); // the C alternative to printing

    double base; 
    int exponent;
    std::cout << "What is the base value? ";
    std::cin >> base;
    std::cout << "What is the exponent value? ";
    std::cin >> exponent;
    print_pow(base, exponent);

    // signed integral data types can contain negative values
    short a;
    int b;
    long c;
    long long d;
    // unsigned integral data types can only contain positive values
    unsigned short aa;
    unsigned int bb;
    unsigned long cc;
    unsigned long long dd;
    std::cout << "size of 'short' data type in bytes is: " << sizeof(short) << "\n";
    // using the <climit> library preprocessor
    // the data types using this lbrary function are: SHRT_MIN, INT_MIN, LONG_MIN, LLONG_MIN.
    // to see the max, just swap the MIN to MAX. And to see the unsigned version just prefix with a captial 'U'. i.e. USHRT_MIN
    std::cout << "minimum value of the 'short' data type is: " << SHRT_MIN << ". max value is: " << SHRT_MAX << std::endl;

    char x = 'A';
    std::cout << x << std::endl;
    std::cout << (int) x << std::endl;  // decimal value of 'A' on ascii table(65)

    bool found = false;  // is also equal to 0, true is equal to any other number but defaults to 1
    std::cout << found << std::endl;    // prints 0
    std::cout << std::boolalpha << found << std::endl;   // changes return value from 0 to 'false' using "std::boolalpha" <- a manipulator

    // floating point numbers: float, double, long double. (all decimal numbers)
    float e = 100.0;
    e = e * 33333333333;
    std::cout << e << "\n";
    std::cout << std::fixed << e << std::endl;   // changes number from scientific notation if it is very large
    std::cout << FLT_DIG << std::endl;  // shows the amount of digits we can trust for a float value (6)
    double f;
    std::cout << DBL_DIG << std::endl;  // shows the amount of digits we can trust for a double value (15)
    f = 100.0 * 33333333333;
    std::cout << std::fixed << f << std::endl;
    long double g;
    std::cout << LDBL_DIG << std::endl;    // shows the amount of digits we can trust for a long double value (18)
    
    // constants: const, enum, and macro (#define G 10)
    const int h = 5;  // this variable 'g' cannot be changed when using const
    enum { i = 100 };    //another option for making a constant, using enum
    return 0;
}

// definitions:
double power(double base, int exponent)
{
    double result = 1;
    for(int i = 0; i < exponent; i++)
    {
        result = result * base;
    }
    return result;
}

void print_pow(double base, int exponent)
{
    double myPower = power(base, exponent);
    std::cout << base << " to the power of " << exponent << " = " << myPower << '\n';
}