#include <iostream>
#include <string>
#include <iomanip>

class Mancala
{
    public:
    Mancala()
    {
        // TODO: overload Mancala(int playerFirst) overloaded constructor to choose player going first
        this->topScore = 0;
        this->bottomScore = 0;
    }

    void Move()
    {
        /* 
         * main gameplay handler function for taking turns
         * handles game logic for each player as well as allocating points around the board
         */
        bool moveValid = false;
        bool updateTurnPlayer = true;
        int numMoves;
        int position;

        if(this->player == 0)
        {
            std::cout << "Top row player input position 1 - 6 to move: ";
            std::cin >> position;
        }
        else
        {
            std::cout << "Bottom row player input position 1 - 6 to move: ";
            std::cin >> position;
            // when player == 1
        }
        position--; // subtract one from player input to go from 1-6 board space notation to 0-5 array notation

        do
         {
            if(!(position >= 0 and position <= 5))
            {
                std::cout << "Invalid move. Please enter a position 1 - 6 to move that space on your row: ";
                std::cin >> position;
                position--; // subtract one from player input to go from 1-6 board space notation to 0-5 array notation
            }
            else
            {
                moveValid = true;
            }
        }while(!moveValid);

        this->y = player;
        this->x = position;

        numMoves = this->board[this->y][this->x];
        this->board[this->y][this->x] = 0;
        if(this->x == 0 && this->y == 0)
        {
            this->y = 1;
            if(player == 0)
            {
                numMoves--; // player scored a point, subtract a move before going into the for-loop move handler
                topScore++; // the right goal / bottom score player scores on this side of the board
            }
        }
        else if(this->x == 5 && this->y == 1)
        {
            this->y = 0;
            if (player == 1)
            {
                numMoves--; // player scored a point, subtract a move before going into the for-loop move handler
                bottomScore++; // the left goal / top score player scores on this side of the board
            }
        }
        else if (y == 0)
        {
            this->x--;
        }
        else if(y == 1)
        {
            this->x++;
        }


        for(int i = 0; i < numMoves; i++)
        {
            this->board[this->y][this->x]++;
            
            if(this->x == 0 && this->y == 0)
            {
                this->y = 1;
                if(player == 0)
                {
                    i++; // player scored a point, subtract a move before going into the for-loop move handler
                    topScore++; // the right goal / bottom score player scores on this side of the board
                }
            }
            else if(this->x == 5 && this->y == 1)
            {
                this->y = 0;
                if (player == 1)
                {
                    i++; // player scored a point, subtract a move before going into the for-loop move handler
                    bottomScore++; // the left goal / top score player scores on this side of the board
                }
            }

            if(i == numMoves)
            {
                updateTurnPlayer = false;
                std::cout << "TPU off\n";
                // we may have incremented i in the previous if-else block, so check if we reached out loop limit here
                // if we did, the turn player ended their turn in their goal and therefore should not move horizontally along their row
            }
            else
            {
                // update board position horizontally
                if (y == 0)
                {
                    this->x--;
                }
                else if(y == 1)
                {
                    this->x++;
                }
            }
        }
        if(updateTurnPlayer)
        {
            this->player = ++this->player % 2;
        }
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
    int topRow[6] = {4, 4, 4, 4, 4, 4};
    int bottomRow[6] = {4, 4, 4, 4, 4, 4};
    int* board[2] = {topRow, bottomRow};
    bool gameInProgress = true;
};

int main(){
    Mancala gameBoard;
    int testMoves = 10;
    for(int i = 0; i < testMoves; i++)
    {
        gameBoard.DisplayBoard();
        gameBoard.Move();
    }
    return 0;

}