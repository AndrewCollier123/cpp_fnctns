#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

void save_score(int guess_count)
{
    std::ifstream input("best_score.txt");

   int best_score;
   input >> best_score;

   std::ofstream output("best_score.txt");
   if(guess_count < best_score)      // if you want to reset number in "best_score.txt" make sure to manually change the value in the file and save it
   {
        output << guess_count;
   }
   else
   {
        output << best_score;
   }
}

void print_vector(std::vector<int> vector)
{
    for(int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << "\t";        
    }
    std::cout << std::endl;
}

void play_game()
{
    std::vector<int> guesses;
    int count = 0;

    int random = rand() % 251;
    std::cout << random << std::endl;
    std::cout << "Guess a number between 1 and 250: ";
    while(true)
    {
        int guess;
        std::cin >> guess;
        //count++;

        guesses.push_back(guess);
        
        if(guess == random)
        {
            std::cout << "Correct!\n";
            break;
        } else if (guess < random)
        {
            std::cout << "Too low, try again: ";
        } else
        {
            std::cout << "Too high, try again: ";
        }
    }

    save_score(guesses.size());

    print_vector(guesses);
}

int main()
{
    srand(time(NULL));
    int choice;
    do
    {
        std::cout << "Enter: 0. to quit    OR     1. to play game" << std::endl;
        std::cin >> choice;
        switch(choice)
        {
            case 0:
                std::cout << "Thanks for playing!" << std::endl;
                break;
            case 1:
                play_game();
                break;
        }
    } while (choice != 0);
    return 0;
}
