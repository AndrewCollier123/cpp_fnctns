#include <iostream>
#include <string>

int main()
{
    // if statement
    int age;
    std::cout << "How old are you? ";
    std::cin >> age;
    if (age < 18)
    {
        std::cout << "You can NOT purchase alcohol" << std::endl;
        // return -1; this ends the main function completely and does not call anything after this if statement
    }
    else if(18 < age && age < 21)
    {
        std::cout << "You can purchase alcohol everywhere except the US\n";
    }
    else
    {
        std::cout << "You CAN purchase alcohol everywhere\n";
    }

    //logical and comparison operators
    //logical: and(&&), or(||), not(!)       comparison: equal(==), not equal(!=), less than(<), greater than(>), less than or equal to(<=), greater than or equal to(>=)
    std::string wordle = "boats";
    std::string guess;
    std::cout << "guess a five letter word: ";
    std::cin >> guess;
    int age_answer = 63;
    int age_guess;
    std::cout << "guess my age: ";
    std::cin >> age_guess;
    // if ( !(guess == wordle) && !(age_guess == age_answer))   //this if statement checks if both guess are NOT correct. Can also use '!=' as the comparison operator instead
    if (guess == wordle && age_guess == age_answer)    // could also use the 'or' operator: ||
    {
        std::cout << "CONGRATULATIONS, YOU GOT IT RIGHT!" << std::endl;
    }

    //switch statements and enum
    int legal_age;  
    std::cout << "how old are you? ";
    std::cin >> legal_age;
    switch(legal_age)   // the data type must be an integer. 
    {
        case 16:
            std::cout << "you can drink in Germany\n";
            break;
        case 18:
            std::cout << "you can drink everywhere in the world except the US\n";
            break;
        case 21:
            std::cout << "you can drink anywhere in the world legally\n";
            break;
        default:
            std::cout << "catch all\n";
            break;
    }
    // enum season{summer, spring, fall, winter};   when not using a class
    enum class Season{summer, spring, fall, winter};
    Season now = Season::spring;
    //season now = spring;  // when not using a class
    switch(now)
    {
        case Season::summer:    // when not using a class: case summer:
            break;
        case Season::spring:
            std::cout << "It is spring time\n";
            break;
        case Season::fall:
            break;
        case Season::winter:
            break;
    }

    //for loops
    int factorial = 5;
    for (int i = factorial - 1; i > 0; i--)
    {
        factorial = factorial * i;
    }
    std::cout << "factorial of 5 is: " << factorial << std::endl;

    //while loop
    int while_factorial = 5;
    int j = while_factorial - 1;
    while(j > 0)
    {
        while_factorial = while_factorial * j;
        j--;
    }
    std::cout << "factorial of 5 is: " << while_factorial << std::endl;

    //do while
    std::string password = "hellotacos123";     // make sure to define these outside of the 'do while' loop
    std::string pwguess;
    do
    {
        std::cout << "Guess my password: ";
        std::cin >> pwguess;
    } while(pwguess != password);
    std::cout << "correct!" << std::endl;

    //break and continue
    std::string sentence = "This is a random sentence";
    for(int i = 0; i < sentence.size(); i++)
    {
        if(sentence[i] == 'm')
        {
            continue;   //skips any function after this call and continues with the iteration of the loop
        }
        std::cout << sentence[i] << std::endl;
        if(sentence[i] == 'r')
        {
            std::cout << "found r!\n";
            //break;      // breaks out of any loop we are currently in
        }
    }
    std::cout << "broke out of for loop using 'break'" << std::endl;

    //conditional operator (ternary operator)
    int game_answer = 11;
    int game_guess;
    std::cout << "guess my number: ";
    std::cin >> game_guess;
    int points = game_guess == game_answer ? 10 : 0;
    game_guess == game_answer ? std::cout << "correct!\n" : std::cout << "incorrect\n";
    std::cout << "You have this many points: " << points << std::endl;
    return 0;
}