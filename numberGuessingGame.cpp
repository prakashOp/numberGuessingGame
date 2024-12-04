#include <iostream>
#include <random>
#include <chrono>

using namespace std;

auto randomNumGen()
{
    int min = 1, max = 25;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distriRandNum(min, max);

    int randomNum = distriRandNum(gen);

    return randomNum;
}

int main()
{
    int userInput;
    int intialChoise;
    int randomNum = randomNumGen();
    std::cout << "1 -> Play :: \n";
    std::cout << "2 -> Exit :: \n";
    std::cout << "Choise -> ";
    std::cin >> intialChoise;

    switch (intialChoise)
    {
    case 1:
        std::cout << "Random Number is between 1 to 25 \n";
        std::cout << "Good Luck\n";
        std::cout << "Enter First Guessing Number :: ";
        std::cin >> userInput;

        while (userInput != randomNum)
        {
            if (randomNum > userInput)
            {
                std::cout << "Enter Again But -> Higher\n";
                std::cin >> userInput;
            }
            if (randomNum < userInput)
            {
                std::cout << "Enter Again But -> Lower\n";
                std::cin >> userInput;
            }
            if (randomNum == userInput)
            {   
                std::cout << "\033[2J\033[1;1H"; 
                std::cout << "Winner -> Random Number was :: " << userInput << std::endl;
                main();
            }
        }
        break;
    case 2:
        return 0;
        break;

    default:
        std::cout << "Wrong Choise\n";
        std::cout << "Enter the Choise Again\n";
        main(); 
        break;
    }

    return 0;
}
