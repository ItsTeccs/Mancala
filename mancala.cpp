#include <iostream>
#include <string>
#include <iomanip>

class Mancala
{
    public:
    Mancala()
    {
        this->topScore = 4;
        this->bottomScore = 4;
    }

    void Move()
    {
        DisplayBoard(this->topScore, this->bottomScore, this->topRow, this->bottomRow);
    }

    private:
    int topScore;
    int bottomScore;
    int topRow[6] = {14, 4, 4, 4, 4, 4};
    int bottomRow[6] = {14, 4, 4, 4, 4, 4};

    void DisplayBoard(int topScore, int bottomScore, int topRow[], int bottomRow[])
    {
        std::string spacing = " ";
        std::string middle_spacing(31, ' ');

        std::cout 
        << "[    ] "
        << '[' << std::setw(2) << topRow[0] <<  ']' << spacing
        << '[' << std::setw(2) << topRow[1] <<  ']' << spacing
        << '[' << std::setw(2) << topRow[2] <<  ']' << spacing
        << '[' << std::setw(2) << topRow[3] <<  ']' << spacing
        << '[' << std::setw(2) << topRow[4] <<  ']' << spacing
        << '[' << std::setw(2) << topRow[5] <<  ']' << spacing
        << "[    ] "  << '\n';
        
        std::cout 
        << '[' << std::setw(3) << topScore << ' ' << ']'
        << middle_spacing
        << '[' << std::setw(3) << bottomScore << ' ' << ']'
        << '\n';

        std::cout 
        << "[    ] " 
        << '[' << std::setw(2) << bottomRow[0] <<  ']' << spacing
        << '[' << std::setw(2) << bottomRow[1] <<  ']' << spacing
        << '[' << std::setw(2) << bottomRow[2] <<  ']' << spacing
        << '[' << std::setw(2) << bottomRow[3] <<  ']' << spacing
        << '[' << std::setw(2) << bottomRow[4] <<  ']' << spacing
        << '[' << std::setw(2) << bottomRow[5] <<  ']' << spacing
        << "[    ] "  << '\n';
    }
};