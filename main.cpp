#include <iostream>
#include <string>
#include <iomanip>

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


int main(){
    int topScore = 4;
    int bottomScore = 4;
    int topRow[] = {14, 4, 4, 4, 4, 4};
    int bottomRow[] = {4, 4, 14, 4, 4, 4};

    DisplayBoard(topScore, bottomScore, topRow, bottomRow);

    return 0;

}