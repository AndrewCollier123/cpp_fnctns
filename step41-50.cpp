#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <array>


void print_vector(std::vector<int> vector)
{
    std::cout << "Your array of integers: ";
    for(int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << "\t";
    }
    std::cout << std::endl;
}

void print_STLarray(std::array<int, 251> stl_array, int count)
{
    std::cout << "Your array of integers: ";
    for(int i = 0; i < count; i++)
    {
        std::cout << stl_array[i] << "\t";
    }
    std::cout << std::endl;
}

void play_game()
{
    // std::vector<int> game_guesses;
    std::array<int, 251> game_guesses;
    int count = 0;
    int random = rand() % 251;      // this gives a random number between 0-250
    std::cout << random << std::endl;
    std::cout << "guess a number: ";
    while(true)
    {
        int guess;
        std::cin >> guess;
        game_guesses[count++] = guess;
        //game_guesses.push_back(guess);  //add guess to array of guess one index at a time
        if(guess == random)
        {
            std::cout << "YOU WIN!" << std::endl;
            break;
        }
        else if(guess < random)
        {
            std::cout << "TOO LOW\ntry again: ";
        }
        else
        {
            std::cout << "TOO HIGH\ntry again: ";
        }
    }
    //print_vector(game_guesses);
    print_STLarray(game_guesses, count);
}

int main()
{   
    
    srand(time(NULL));
    int choice;
    do
    {
        std::cout << "0. Quit" << std::endl << "1. Play Game" << std::endl;
        std::cin >> choice;
        switch(choice)
        {   
            case 0:
                std::cout << "You selected to quit game, thanks for playing!" << std::endl;
                break;
            case 1:
                play_game();
                break;
        }  
    } while (choice != 0);
    
    /*
    int guesses[20];    // can make it guesses[] = {3, 5, 34, 11}. the arrays size depends on the amount of values put in the array
    std::cout << "what would you like the value of the first index to be? ";
    std::cin >> guesses[0];
    std::cout << guesses[0] << '\n';

    int other_guesses[] = {4, 55, 61, 73};
    int size = sizeof(other_guesses) / sizeof(int);
    for(int i = 0; i < size; i++)
    {
        std::cout << other_guesses[i] << std::endl;
    }
    
    const int ARR_SIZE = 100;   // generally initialize array size to a larger number than expected
    int arr_to_print[ARR_SIZE];
    // int arr_size = sizeof(arr_to_print) / sizeof(int);
    int count = 0;  //this count helps when calling print_array function so if we get an invalid number from the user, it only passes the count as the array size for valid integers

    std::cout << "enter up to 100 integers: ";
    for(int i = 0; i < ARR_SIZE; i++)
    {
        if(std::cin >> arr_to_print[i])
        {
            //input is valid. valid inputs are integers since thats what the arr_to_print array is initialized as.
            count++;    //
        }
        else
        {
            //invalid character. Anything that is not an integer
            break;
        }
    }
    print_array(arr_to_print, count);
    std::cin.clear();   // clears the state of input that contained an invalid input (a non integer value)
    // std::cin.ignore(10000, '\n');  // manually removes the invalid inputs from the number of characters up until the newline
    // the above ignore() function call only covers the first 10,000 possible extra characters. but what if someone inputs 10,001?
    // the line below is an alternative that resolves that issue:
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // requires #include <limits>

    std::string input_overflow_test;
    std::cin >> input_overflow_test;
    std::cout << input_overflow_test << std::endl;  // notice how this string does not have overflow of invalid character still remaining in "cin"
    */
    return 0;
}