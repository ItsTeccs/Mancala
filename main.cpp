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
        /* 
         * main gameplay handler function for taking turns
         * handles game logic for each player as well as allocating points around the board
         */
        bool moveValid = false;
        int numMoves;
        int position;
        if(this->player == 0)
        {
            std::cout << "Top row player input position 0 - 5 to move.";
            std::cin >> position;
        }
        else
        {
            std::cout << "Top row player input position 0 - 5 to move.";
            std::cin >> position;
            // when player == 1
        }

        do
         {
            if(this->player == 0 && (position >= 6 && position <= 11))
            {
                std::cout << "Invalid move entered. The top row player may only enter positions 0 - 5 to move.\n";
                std::cin >> position;

            }
            else if(this->player == 1 && (position >= 0 && position <= 5))
            {
                std::cout << "Invalid move entered. The bottom row player may only enter positions 6 - 11 to move.\n";
                std::cin >> position;
            }
            else
            {
                moveValid = true;
            }
        }while(!moveValid);

        if(this->player == 0)
         {
            this->y = 0;
            this->x = position;
         }
        else if (player == 1)
         {
            this->y = 1;
            this->x = position - 6;
         }


        numMoves = this->board[this->y][this->x];
        this->board[this->y][this->x] = 0;
        if(this->x == 5 && this->y == 0)
        {
            this->y = 1;
        }
        else if(this->x == 0 && this->y == 1)
        {
            this->y = 0;
        }

        if(y == 0)
        {
            this->x++;
        }
        else
        {
            this->x--;
        }


        for(int i = 0; i < numMoves; i++)
        {
            this->board[this->y][this->x]++;
            
            if(this->x == 5 && this->y == 0)
            {
                this->y = 1;
            }
            else if(this->x == 5 && this->y == 1)
            {
                this->y = 0;
            }

            if(y == 0)
            {
                this->x++;
            }
            else
            {
                this->x--;
            }
        }
        this->player = ++this->player % 2;
    }

    void DisplayBoard()
    {
        std::string spacing = " ";
        std::string middle_spacing(31, ' ');

        std::cout 
        << "[    ] "
        << '[' << std::setw(2) << this->topRow[0] <<  ']' << spacing
        << '[' << std::setw(2) << this->topRow[1] <<  ']' << spacing
        << '[' << std::setw(2) << this->topRow[2] <<  ']' << spacing
        << '[' << std::setw(2) << this->topRow[3] <<  ']' << spacing
        << '[' << std::setw(2) << this->topRow[4] <<  ']' << spacing
        << '[' << std::setw(2) << this->topRow[5] <<  ']' << spacing
        << "[    ] "  << '\n';
        
        std::cout 
        << '[' << std::setw(3) << this->topScore << ' ' << ']'
        << middle_spacing
        << '[' << std::setw(3) << this->bottomScore << ' ' << ']'
        << '\n';

        std::cout 
        << "[    ] " 
        << '[' << std::setw(2) << this->bottomRow[0] <<  ']' << spacing
        << '[' << std::setw(2) << this->bottomRow[1] <<  ']' << spacing
        << '[' << std::setw(2) << this->bottomRow[2] <<  ']' << spacing
        << '[' << std::setw(2) << this->bottomRow[3] <<  ']' << spacing
        << '[' << std::setw(2) << this->bottomRow[4] <<  ']' << spacing
        << '[' << std::setw(2) << this->bottomRow[5] <<  ']' << spacing
        << "[    ] "  << '\n';
    }

    private:
    int player = 0 ; // 0 for top player, 1 for bottom player
    int x = 0;
    int y = 0;
    int topScore;
    int bottomScore;
    int topRow[6] = {14, 4, 4, 4, 4, 4};
    int bottomRow[6] = {14, 4, 4, 4, 4, 4};
    int* board[2] = {topRow, bottomRow};
    bool gameInProgress = true;
};

int main(){
    Mancala gameBoard;
    gameBoard.DisplayBoard();
    gameBoard.Move();
    gameBoard.DisplayBoard();

    return 0;

}