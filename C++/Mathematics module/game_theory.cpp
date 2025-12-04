//#include <iostream>

//using namespace std;

struct chess_board{
    std::string board[256][256];
    std::string colour_of_piece[256][256];
};

class game_theory{
    public:
        chess_board chess_board1;

        bool populate_chess_board (chess_board chess_board2)
        {
            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    chess_board1.board[i][j] = chess_board2.board[i][j];
                    chess_board1.colour_of_piece[i][j] = chess_board2.colour_of_piece[i][j];
                }
            }

            return true;
        }

        bool move_chess_piece(int row, int column, bool move_straight, bool move_crossways, bool move_sideways, char direction_to_move)
        {
            bool moved = false;

            if (chess_board1.board[row][column] == "Solidier")
            {
                if (move_straight == true)
                {
                    if (chess_board1.board[row++][column] == "Solider" || chess_board1.board [row++][column] == "Rook" || chess_board1.board[row++][column] == "Bishop" || chess_board1.board[row++][column] == "Knight" || chess_board1.board[row++][column] == "Queen" || chess_board1.board[row++][column] == "King")
                        std::cout << "Cannot move piece" << std::endl;

                    else
                    {
                        chess_board1.board[row++][column] = "Soldier";
                        chess_board1.colour_of_piece[row++][column] = chess_board1.colour_of_piece[row][column];
                        chess_board1.board[row][column] = " ";
                        moved = true;
                    }
                }

                else if (move_crossways == true)
                {
                    if (chess_board1.board[row++][column++] == "Soldier")
                        std::cout << "Soldier takes soldier" << std::endl;
                    else if (chess_board1.board[row++][column++] == "Rook")
                        std::cout << "Soldier takes rook" << std::endl;
                    else if (chess_board1.board[row++][column++] == "Knight")
                        std::cout << "Soldier takes knight" << std::endl;
                    else if (chess_board1.board[row++][column++] == "Bishop")
                        std::cout << "Soldier takes bishop" << std::endl;
                    else if (chess_board1.board[row++][column++] == "Queen")
                        std::cout << "Soldier takes queen" << std::endl;
                    else if (chess_board1.board[row++][column++] == "King")
                        std::cout << "Soldier takes king" << std::endl;
                    else if (chess_board1.board[row++][column++] == "Soldier")
                        std::cout << "Soldier takes soldier" << std::endl;

                    chess_board1.board[row++][column++] = "Soldier";
                    chess_board1.colour_of_piece[row++][column++] = chess_board1.colour_of_piece[row][column];
                    chess_board1.colour_of_piece[row][column] = " ";
                    chess_board1.board[row][column] = "";
                    moved = true;
                }

                if (move_sideways == true)
                    std::cout << "Not possible" << std::endl;
            }

            else if (chess_board1.board[row][column] == "Rook")
            {
                if (move_straight == true)
                {
                    if (chess_board1.board[row++][column] == "Soldier")
                        std::cout << "Rook takes soldier" << std::endl;
                    else if (chess_board1.board[row++][column] == "Knight")
                        std::cout << "Rook takes knight" << std::endl;
                    else if (chess_board1.board[row++][column] == "Bishop")
                        std::cout << "Rook takes bishop" << std::endl;
                    else if (chess_board1.board[row++][column] == "Queen")
                        std::cout << "Rook takes queen" << std::endl;
                    else if (chess_board1.board[row++][column] == "King")
                        std::cout << "Rook takes King" << std::endl;
                    else if (chess_board1.board[row++][column] == "Rook")
                        std::cout << "Rook takes rook" << std::endl;

                    chess_board1.board[row++][column] = chess_board1.board[row][column];
                    chess_board1.colour_of_piece[row++][column] = chess_board1.board[row][column];
                    chess_board1.board[row][column] = " ";
                    chess_board1.colour_of_piece[row][column] = " ";
                    moved = true;
                }

                else if (move_crossways == true)
                    std::cout << "Not possible to move rook in such a direction" << std::endl;

                else if (move_sideways == true)
                {
                    if (direction_to_move == 'r')
                    {
                        if (chess_board1.board[row][column++] == "Soldier")
                            std::cout << "Rook takes soldier" << std::endl;
                        else if (chess_board1.board[row][column++] == "Knight")
                            std::cout << "Rook takes knight" << std::endl;
                        else if (chess_board1.board[row][column++] == "Bishop")
                            std::cout << "Rook takes bishop" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Queen")
                            std::cout << "Rook takes queen" << std::endl;
                        else if (chess_board1.board[row++][column++] == "King")
                            std::cout << "Rook takes King" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Rook")
                            std::cout << "Rook takes rook" << std::endl;

                        chess_board1.board[row++][column] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row++][column] = chess_board1.board[row][column];
                        chess_board1.board[row][column] = " ";
                        chess_board1.colour_of_piece[row][column] = " ";
                        moved = true;
                    }

                    if (direction_to_move == 'l')
                    {
                        if (chess_board1.board[row][column--] == "Soldier")
                            std::cout << "Rook takes soldier" << std::endl;
                        else if (chess_board1.board[row][column--] == "Knight")
                            std::cout << "Rook takes knight" << std::endl;
                        else if (chess_board1.board[row][column--] == "Bishop")
                            std::cout << "Rook takes bishop" << std::endl;
                        else if (chess_board1.board[row][column--] == "Queen")
                            std::cout << "Rook takes queen" << std::endl;
                        else if (chess_board1.board[row][column--] == "King")
                            std::cout << "Rook takes King" << std::endl;
                        else if (chess_board1.board[row][column--] == "Rook")
                            std::cout << "Rook takes rook" << std::endl;

                        chess_board1.board[row][column--] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row][column--] = chess_board1.board[row][column];
                        chess_board1.board[row][column] = " ";
                        chess_board1.colour_of_piece[row][column] = " ";
                        moved = true;
                    }
                }
            }

            else if (chess_board1.board[row][column] == "Knight")
            {
                if (move_straight == true)
                    std::cout << "Not possible" << std::endl;
                else if (move_sideways == true)
                    std::cout << "Not possible" << std::endl;
                else if (move_crossways == true)
                {
                    if (direction_to_move == 'r')
                    {
                        if (chess_board1.board[row+2][column++] == "Soldier")
                            std::cout << "Knight takes soldier" << std::endl;
                        else if (chess_board1.board[row+2][column++] == "Rook")
                            std::cout << "Knight takes rook" << std::endl;
                        else if (chess_board1.board[row+2][column++] == "Knight")
                            std::cout << "Knight takes knight" << std::endl;
                        else if (chess_board1.board[row+2][column++] == "Bishop")
                            std::cout << "Knight takes bishop" << std::endl;
                        else if (chess_board1.board[row+2][column++] == "Queen")
                            std::cout << "Knight takes queen" << std::endl;
                        else if (chess_board1.board[row+2][column++] == "King")
                            std::cout << "Knight takes king" << std::endl;
                        
                        chess_board1.board[row+2][column++] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row+2][column++] = chess_board1.board[row][column];
                        chess_board1.board[row+2][column++] = " ";
                        chess_board1.colour_of_piece[row+2][column++] = " ";
                        moved = true;
                    }

                    if (direction_to_move == 'l')
                    {
                        if (chess_board1.board[row++][column--] == "Soldier")
                            std::cout << "Knight takes soldier" << std::endl;
                        else if (chess_board1.board[row++][column--] == "Rook")
                            std::cout << "Knight takes rook" << std::endl;
                        else if (chess_board1.board[row++][column--] == "Knight")
                            std::cout << "Knight takes knight" << std::endl;
                        else if (chess_board1.board[row++][column--] == "Bishop")
                            std::cout << "Knight takes bishop" << std::endl;
                        else if (chess_board1.board[row++][column--] == "Queen")
                            std::cout << "Knight takes queen" << std::endl;
                        else if (chess_board1.board[row++][column--] == "King")
                            std::cout << "Knight takes king" << std::endl;

                        chess_board1.board[row++][column--] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row++][column--] = chess_board1.board[row][column];
                        chess_board1.board[row++][column--] = " ";
                        chess_board1.colour_of_piece[row++][column--] = " ";
                        moved = true;
                    }
                }
            }

            else if (chess_board1.board[row][column] == "Bishop")
            {
                if (move_sideways == true)
                    std::cout << "Not possible" << std::endl;
                else if (move_straight == true)
                    std::cout << "Not possible" << std::endl;
                else if (move_crossways == true)
                {
                    if (direction_to_move == 'l')
                    {
                        if (chess_board1.board[row--][column--] == "Soldier")
                            std::cout << "Bishop takes soldier" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Rook")
                            std::cout << "Bishop takes rook" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Knight")
                            std::cout << "Bishop takes knight" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Bishop")
                            std::cout << "Bishop takes bishop" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Queen")
                            std::cout << "Bishop takes queen" << std::endl;
                        else if (chess_board1.board[row--][column--] == "King")
                            std::cout << "Bishop takes king" << std::endl;

                        chess_board1.board[row--][column--] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row--][column--] = chess_board1.board[row][column];
                        chess_board1.board[row--][column--] = " ";
                        chess_board1.colour_of_piece[row--][column--] = " ";
                        moved = true;
                    }

                    if (direction_to_move == 'r')
                    {
                        if (chess_board1.board[row++][column++] == "Soldier")
                            std::cout << "Knight takes soldier" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Rook")
                            std::cout << "Knight takes rook" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Knight")
                            std::cout << "Knight takes knight" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Bishop")
                            std::cout << "Knight takes bishop" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Queen")
                            std::cout << "Knight takes queen" << std::endl;
                        else if (chess_board1.board[row++][column++] == "King")
                            std::cout << "Knight takes king" << std::endl;

                        chess_board1.board[row++][column++] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row++][column++] = chess_board1.board[row][column];
                        chess_board1.board[row++][column++] = " ";
                        chess_board1.colour_of_piece[row++][column++] = " ";
                        moved = true;
                    }
                }
            }

            else if (chess_board1.board[row][column] == "Queen")
            {
                if (move_sideways == true)
                {
                    if (direction_to_move == 'l')
                    {
                        if (chess_board1.board[row][column--] == "Soldier")
                            std::cout << "Queen takes soldier" << std::endl;
                        else if (chess_board1.board[row][column--] == "Rook")
                            std::cout << "Queen takes rook" << std::endl;
                        else if (chess_board1.board[row][column--] == "Knight")
                            std::cout << "Queen takes knight" << std::endl;
                        else if (chess_board1.board[row][column--] == "Bishop")
                            std::cout << "Queen takes bishop" << std::endl;
                        else if (chess_board1.board[row][column--] == "Queen")
                            std::cout << "Queen takes queen" << std::endl;
                        else if (chess_board1.board[row][column--] == "King")
                            std::cout << "Queen takes king" << std::endl;

                        chess_board1.board[row][column--] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row][column--] = chess_board1.board[row][column];
                        chess_board1.board[row][column--] = " ";
                        chess_board1.colour_of_piece[row][column--] = " ";
                        moved = true;
                    }

                    else if (direction_to_move == 'r')
                    {
                        if (chess_board1.board[row][column++] == "Soldier")
                            std::cout << "Queen takes soldier" << std::endl;
                        else if (chess_board1.board[row][column++] == "Rook")
                            std::cout << "Queen takes rook" << std::endl;
                        else if (chess_board1.board[row][column++] == "Knight")
                            std::cout << "Queen takes knight" << std::endl;
                        else if (chess_board1.board[row][column++] == "Bishop")
                            std::cout << "Queen takes bishop" << std::endl;
                        else if (chess_board1.board[row][column++] == "Queen")
                            std::cout << "Queen takes queen" << std::endl;
                        else if (chess_board1.board[row][column++] == "King")
                            std::cout << "Queen takes king" << std::endl;

                        chess_board1.board[row][column++] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row][column++] = chess_board1.board[row][column];
                        chess_board1.board[row][column++] = " ";
                        chess_board1.colour_of_piece[row][column++] = " ";
                        moved = true;
                    }
                }

                else if (move_straight == true)
                {
                    if (direction_to_move == 'l')
                    {
                        if (chess_board1.board[row][column--] == "Soldier")
                            std::cout << "Queen takes soldier" << std::endl;
                        else if (chess_board1.board[row][column--] == "Rook")
                            std::cout << "Queen takes rook" << std::endl;
                        else if (chess_board1.board[row][column--] == "Knight")
                            std::cout << "Queen takes knight" << std::endl;
                        else if (chess_board1.board[row][column--] == "Bishop")
                            std::cout << "Queen takes bishop" << std::endl;
                        else if (chess_board1.board[row][column--] == "Queen")
                            std::cout << "Queen takes queen" << std::endl;
                        else if (chess_board1.board[row][column--] == "King")
                            std::cout << "Queen takes king" << std::endl;

                        chess_board1.board[row][column--] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row][column--] = chess_board1.board[row][column];
                        chess_board1.board[row][column--] = " ";
                        chess_board1.colour_of_piece[row][column--] = " ";
                        moved = true;
                    }

                    else if (direction_to_move == 'r')
                    {
                        if (chess_board1.board[row][column++] == "Soldier")
                            std::cout << "Queen takes soldier" << std::endl;
                        else if (chess_board1.board[row][column++] == "Rook")
                            std::cout << "Queen takes rook" << std::endl;
                        else if (chess_board1.board[row][column++] == "Knight")
                            std::cout << "Queen takes knight" << std::endl;
                        else if (chess_board1.board[row][column++] == "Bishop")
                            std::cout << "Queen takes bishop" << std::endl;
                        else if (chess_board1.board[row][column++] == "Queen")
                            std::cout << "Queen takes queen" << std::endl;
                        else if (chess_board1.board[row][column++] == "King")
                            std::cout << "Queen takes king" << std::endl;

                        chess_board1.board[row][column++] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row][column++] = chess_board1.board[row][column];
                        chess_board1.board[row][column++] = " ";
                        chess_board1.colour_of_piece[row][column++] = " ";
                        moved = true;
                    }
                }

                else if (move_crossways == true)
                {
                    if (direction_to_move == 'l')
                    {
                        if (chess_board1.board[row--][column--] == "Soldier")
                            std::cout << "Queen takes soldier" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Rook")
                            std::cout << "Queen takes rook" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Knight")
                            std::cout << "Queen takes knight" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Bishop")
                            std::cout << "Queen takes bishop" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Queen")
                            std::cout << "Queen takes queen" << std::endl;
                        else if (chess_board1.board[row--][column--] == "King")
                            std::cout << "Queen takes king" << std::endl;

                        chess_board1.board[row--][column--] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row--][column--] = chess_board1.board[row][column];
                        chess_board1.board[row--][column--] = " ";
                        chess_board1.colour_of_piece[row--][column--] = " ";
                        moved = true;
                    }

                    if (direction_to_move == 'r')
                    {
                        if (chess_board1.board[row++][column++] == "Soldier")
                            std::cout << "Queen takes soldier" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Rook")
                            std::cout << "Queen takes rook" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Knight")
                            std::cout << "Queen takes knight" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Bishop")
                            std::cout << "Queen takes bishop" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Queen")
                            std::cout << "Queen takes queen" << std::endl;
                        else if (chess_board1.board[row++][column++] == "King")
                            std::cout << "Queen takes king" << std::endl;

                        chess_board1.board[row++][column++] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row++][column++] = chess_board1.board[row][column];
                        chess_board1.board[row++][column++] = " ";
                        chess_board1.colour_of_piece[row++][column++] = " ";
                        moved = true;
                    }
                }
            }

            else if (chess_board1.board[row][column] == "King")
            {
                if (move_sideways == true)
                {
                    if (direction_to_move == 'l')
                    {
                        if (chess_board1.board[row][column--] == "Soldier")
                            std::cout << "King takes soldier" << std::endl;
                        else if (chess_board1.board[row][column--] == "Rook")
                            std::cout << "King takes rook" << std::endl;
                        else if (chess_board1.board[row][column--] == "Knight")
                            std::cout << "King takes knight" << std::endl;
                        else if (chess_board1.board[row][column--] == "Bishop")
                            std::cout << "King takes bishop" << std::endl;
                        else if (chess_board1.board[row][column--] == "Queen")
                            std::cout << "King takes queen" << std::endl;
                        else if (chess_board1.board[row][column--] == "King")
                            std::cout << "King takes king" << std::endl;

                        chess_board1.board[row][column--] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row][column--] = chess_board1.board[row][column];
                        chess_board1.board[row][column--] = " ";
                        chess_board1.colour_of_piece[row][column--] = " ";
                        moved = true;
                    }

                    else if (direction_to_move == 'r')
                    {
                        if (chess_board1.board[row][column++] == "Soldier")
                            std::cout << "King takes soldier" << std::endl;
                        else if (chess_board1.board[row][column++] == "Rook")
                            std::cout << "King takes rook" << std::endl;
                        else if (chess_board1.board[row][column++] == "Knight")
                            std::cout << "King takes knight" << std::endl;
                        else if (chess_board1.board[row][column++] == "Bishop")
                            std::cout << "King takes bishop" << std::endl;
                        else if (chess_board1.board[row][column++] == "Queen")
                            std::cout << "King takes queen" << std::endl;
                        else if (chess_board1.board[row][column++] == "King")
                            std::cout << "King takes king" << std::endl;

                        chess_board1.board[row][column++] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row][column++] = chess_board1.board[row][column];
                        chess_board1.board[row][column++] = " ";
                        chess_board1.colour_of_piece[row][column++] = " ";
                        moved = true;
                    }
                }

                else if (move_straight == true)
                {
                    if (direction_to_move == 'u')
                    {
                        if (chess_board1.board[row++][column] == "Soldier")
                            std::cout << "King takes soldier" << std::endl;
                        else if (chess_board1.board[row++][column] == "Rook")
                            std::cout << "King takes rook" << std::endl;
                        else if (chess_board1.board[row++][column] == "Knight")
                            std::cout << "King takes knight" << std::endl;
                        else if (chess_board1.board[row++][column] == "Bishop")
                            std::cout << "King takes bishop" << std::endl;
                        else if (chess_board1.board[row++][column] == "Queen")
                            std::cout << "King takes queen" << std::endl;
                        else if (chess_board1.board[row++][column] == "King")
                            std::cout << "King takes king" << std::endl;

                        chess_board1.board[row++][column] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row++][column] = chess_board1.board[row][column];
                        chess_board1.board[row++][column] = " ";
                        chess_board1.colour_of_piece[row++][column] = " ";
                        moved = true;
                    }

                    if (direction_to_move == 'd')
                    {
                        if (chess_board1.board[row++][column++] == "Soldier")
                            std::cout << "King takes soldier" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Rook")
                            std::cout << "King takes rook" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Knight")
                            std::cout << "King takes knight" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Bishop")
                            std::cout << "King takes bishop" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Queen")
                            std::cout << "King takes queen" << std::endl;
                        else if (chess_board1.board[row++][column++] == "King")
                            std::cout << "King takes king" << std::endl;

                        chess_board1.board[row--][column] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row--][column] = chess_board1.board[row][column];
                        chess_board1.board[row--][column] = " ";
                        chess_board1.colour_of_piece[row--][column] = " ";
                        moved = true;
                    }
                }

                else if (move_crossways == true)
                {
                    if (direction_to_move == 'l')
                    {
                        if (chess_board1.board[row--][column--] == "Soldier")
                            std::cout << "King takes soldier" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Rook")
                            std::cout << "King takes rook" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Knight")
                            std::cout << "King takes knight" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Bishop")
                            std::cout << "King takes bishop" << std::endl;
                        else if (chess_board1.board[row--][column--] == "Queen")
                            std::cout << "King takes queen" << std::endl;
                        else if (chess_board1.board[row--][column--] == "King")
                            std::cout << "King takes king" << std::endl;

                        chess_board1.board[row--][column--] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row--][column--] = chess_board1.board[row][column];
                        chess_board1.board[row--][column--] = " ";
                        chess_board1.colour_of_piece[row--][column--] = " ";
                        moved = true;
                    }

                    if (direction_to_move == 'r')
                    {
                        if (chess_board1.board[row++][column++] == "Soldier")
                            std::cout << "King takes soldier" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Rook")
                            std::cout << "King takes rook" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Knight")
                            std::cout << "King takes knight" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Bishop")
                            std::cout << "King takes bishop" << std::endl;
                        else if (chess_board1.board[row++][column++] == "Queen")
                            std::cout << "King takes queen" << std::endl;
                        else if (chess_board1.board[row++][column++] == "King")
                            std::cout << "King takes king" << std::endl;

                        chess_board1.board[row++][column++] = chess_board1.board[row][column];
                        chess_board1.colour_of_piece[row++][column++] = chess_board1.board[row][column];
                        chess_board1.board[row++][column++] = " ";
                        chess_board1.colour_of_piece[row++][column++] = " ";
                        moved = true;
                    }
                }
            }

            return moved;
        }
};

//int main()
//{
//
//}