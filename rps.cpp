#include <iostream>

constexpr int kExit = 0;
constexpr int kRock = 1;
constexpr int kPaper = 2;
constexpr int kScissors = 3;

constexpr int kPossibleChoices = 3;

constexpr int kLose = 1;
constexpr int kWin = 2;
constexpr int kDraw = 3;

bool playing = true;

int matchesWon = 0;
int matchesDrawn = 0;
int matchesPlayed = 0;

void matchSummary()
{
    std::cout << "---Here's a match summary---\n";
    std::cout << "Your winrate is : " << ((matchesWon / (static_cast<double>(matchesPlayed) - matchesDrawn)) * 100.0) << "%\n";
    std::cout << "You played a total of " << matchesPlayed << " rounds (" << (matchesPlayed - matchesDrawn) << " excluding draws) and won " << matchesWon << " of them\n";
}

std::string convertToString(int response)
{
    if (response == kRock)
    {
        return "rock";
    }
    else if (response == kPaper)
    {
        return "paper";
    }
    // response == kScissors
    return "scissors";
}

void lose()
{
        std::cout << "You lose!\n";
}

void win()
{
    matchesWon++;
    std::cout << "You win!\n";
}

int evalUserWin(int userResponse, int genResponse)
{
    if (userResponse != kExit)
    {
        matchesPlayed++;
        std::cout << "You chose " << convertToString(userResponse) << "\nThe program chose " << convertToString(genResponse) << ".\n";

        if (userResponse == genResponse)
        {
            std::cout << "Draw!\n";
            matchesDrawn++;
            return kDraw;
        }
        else if (userResponse == kRock)
        {
            if (genResponse == kPaper)
            {
                lose();
                return kLose;
            }
            else
            {
                win();
                return kWin;
            }
        }
        else if (userResponse == kPaper)
        {
            if (genResponse == kScissors)
            {
                lose();
                return kLose;
            }
            else
            {
                win();
                return kWin;
            }
        }
        //userResponse == kScissors
        if (genResponse == kRock)
        {
            lose();
            return kLose;
        }
        win();
        return kWin;
    }
    return kExit;
}

int randomHand()
{
    return (std::rand() % kPossibleChoices + 1);
}

int getUserHand()
{
    while (playing)
    {
        std::string input;
        std::cout << "\nEnter a input : ";
        std::cin >> input;

        if (input == "c" || input == "cancel")
        {
            matchSummary();
            std::cout << "Quiting game...\n";
            playing = false;
        }
        else if (input == "r" || input == "rock")
        {
            return kRock;
        }
        else if (input == "p" || input == "paper")
        {
            return kPaper;
        }
        else if (input == "s" || input == "scissors")
        {
            return kScissors;
        }
        else
        {
            std::cout << "Invalid input.\n";
        }
    }
    return kExit;
}

void randomRPS()
{
    while (playing)
    {
        evalUserWin(getUserHand(), randomHand());
    }
}

//Start up introduction
void start()
{
    std::cout << "\nWelcome to RPS. When prompted, you can input \"rock\", \"paper\", \"scissors\", or \"cancel\" to make your move. \n"
                 "(You may also abbreviate inputs to \"r\", \"p\", and so on)\n";

    randomRPS();
}

int main()
{
    start();
}