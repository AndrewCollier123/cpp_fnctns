#include <iostream>
#include <cmath>
#include <string>   // lets us use "string"

int main()
{
    //numeric functions
    std::cout << sqrt(25) << std::endl;    // invalid outputs return "nan", extremely large outpus return "inf" or "-inf"
    // std::cout << 10 % 3.25 << "\n";     // returns error since modulus operator does not handle floating point numbers
    std::cout << remainder(10, 3.25) << "\n";   // remainder function resolves this issue. an alternative would be to use the fmod() function
    std::cout << fmax(10, 3.25) << std::endl;   // returns max num of arguments passed
    std::cout << fmin(10, 3.25) << std::endl;   // returns min num of args passed
    std::cout << ceil(fmax(10.1, 3.25)) << std::endl;   // returns the rounded up num from the fmax() function 
    std::cout << floor(fmin(10, 3.25)) << std::endl;    // returns the rounded down num from the fmin() function. alternative would be to use trunc() function
    std::cout << trunc(-1.5) << std::endl;     // truncates the 0.5 and returns -1, where as the floor func would return -2
    std::cout << round(1.49) << std::endl;      // rounds the num

    // string class
    std::string greeting = "hello";    // creates an object(greeting) of type: string. If no string is given to the object, it defeaults to an empty string
    std::string greet_world = greeting + " world";
    greet_world += "!";
    std::cout << greet_world << std::endl;
    std::cout << greet_world.length() << std::endl;     // function call "length()" is a member of string class, so it can be called by using dot operator at the end of an object
    // method == member function == functions attached to objects. i.e. the ".length()" function on greet_world object
    
    // how to get line from user
    std::string hello;
    std::cin >> hello;  // if you input "hello there!", the input for the string object hello stops once it reaches a whitespace so it equals "hello"
    std::string left_over;
    std::cin >> left_over;  // this grabs the next string after the whitespace from the previous cin call, so left_over = "there!"
    std::cout << hello << std::endl;
    std::cout << left_over << std::endl;
    
    //to get full line you need to use getline() function
    std::cout << "please enter the phrase: 'hello there!': ";
    std::string hello_again;
    getline(std::cin >> std::ws, hello_again);  // need to pass std::ws to cin to extract all white space after previous cin calls.
    std::cout << hello_again << std::endl;

    //string modifier methods
    hello_again.append(" hows it going?");  // altenative to use "+="
    std::cout << hello_again << std::endl;
    hello_again.insert(16, " i");   //inserts string into index provided
    std::cout << hello_again << "\n";
    hello_again.erase(16, 2);    // removes number of characters(2) from index(16)
    std::cout << hello_again << std::endl;
    hello_again.replace(5, hello_again.length() - 5, " everyone");    // (starting index, amount of characters to replace, new string to replace it with)
    std::cout << hello_again << std::endl;

    // string operation methods
    hello_again.replace(hello_again.find("everyone"), 8, "********");
    std::cout << hello_again << std::endl;
    std::cout << hello_again.substr(4,1) << std::endl;  // extracts any char or string of char 
    std::cout << hello_again.find_first_of("aeiou") << std::endl;   //returns index of first instance
    if(hello_again.find_first_of("%") == -1) std::cout << "NOT FOUND" << std::endl;     // no matching char in string results in return value of -1
    if(hello_again.compare("hello ********") == 0) std::cout << "strings are equal" << std::endl;   // .compare() function returns 0 if strings match
    

    //literals
    auto x = 5U;    // auto identifies the datatype of the variable 'x' by the value it is given (unsigned integer). must compile with -std=c++11

    //Hex and octal
    int number = 30;
    int hex_number = 0x30;  // 48, hex number is prefaced with 0x
    int octal_number = 030;  // 24, octal number is prefaced with a 0
    std::cout << hex_number << "\t" << octal_number << std::endl;
    std::cout << "decimal value 30 to octal is: " << std::oct << number << std::endl;
    std::cout << "decimal value 30 to hexidecimal is: " << std::hex << number << std::endl;

    // operator precedence and associativity
    int y = 5 + 5;  // "=" is the assignment operator. y is equal to the expression "5 + 5"
    std::cout << std::dec << y << "\n";
    y = 10 / 4;  // integer division will not return a floating point number. this will return 2 instead of 2.5
    std::cout << y << std::endl;
    double z = 10.0 / 4;   // you must make one of the values a floating point number and the variable set to a float, double, or long double to maintain that decimal value.
    std::cout << z << std::endl;
    int w = 10 % 4;    // mod operator(%) returns the remainder. i.e. 2
    std::cout << w << std::endl;
    return 0;
}