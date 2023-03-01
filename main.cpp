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

    void Move(int position)
    {
        /* 
         * main gameplay handler function for taking turns
         * handles game logic for each player as well as allocating points around the board
         */
         bool moveValid = false;
         int numMoves;
         do
         {
            if(player == 0 && (position >= 6 && position <= 11))
            {
                std::cout << "Invalid move entered. The top row player may only enter positions 0 - 5 to move.\n";
            }
            else if(player == 1 && (position >= 0 && position <= 5))
            {
                std::cout << "Invalid move entered. The bottom row player may only enter positions 6 - 11 to move.\n";
            }
            else
            {
                moveValid = true;
            }
         }while(!moveValid);

         if(player == 0)
         {
            this->y = 0;
            this->x = position;
         }
         else if (player == 1)
         {
            this->y = 1;
            this->x = position - 6;
         }


        numMoves = board[this->y][this->x];
        board[this->y][this->x] = 0;
         for(int i = 0; i < numMoves)
         {
            if(this->x == 0 && this->y == 0)
            {
                this->y = 1;
            }
            else if(this->x == 5 && this->y == 1)
            {
                this->y = 0;
            }

            if(this->y == 0)
            {
            
            }
            else if (this->y == 1)
            {

            }
         }
    }

    private:
    int currentPlayer = 0 ; // 0 for top player, 1 for bottom player
    int x = 0;
    int y = 0;
    int topScore;
    int bottomScore;
    int topRow[6] = {14, 4, 4, 4, 4, 4};
    int bottomRow[6] = {14, 4, 4, 4, 4, 4};
    int* board[2] = {topRow, bottomRow};
    bool gameInProgress = true;
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

int main(){
    Mancala gameBoard;
    //gameBoard.Move();

    return 0;

}