// ttt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "ttt_funcs.h"

int main()
{
    int p1_score = 0;
    int p2_score = 0;
    int curr_player = 1;
    int round = 0;
    bool in_play = true;
    bool in_game = true;
    std::vector<char> board;

    for (int i = 0; i < 9; i++)
    {
        board.push_back(' ');   
    }

    while (in_play && round < 10)
    {
        introduction();
        draw(board);
        int inner_count = 0;
        while (in_game && inner_count < 9)
        {
            take_turn(curr_player);
            board = set_position(board, curr_player);
            draw(board);
            if (is_winner(board, curr_player))
            {
                end_game(true, curr_player);
                in_game = false;
            }
            else if (filled_up(board))
            {
                end_game(false);
                in_game = false;
            }
            else
            {
                curr_player = change_player(curr_player);
            }
            inner_count++;
        }

        bool check_over = end_play();
        if (check_over)
        {
            in_play = false;
        }
        else
        {
            in_game = true;
        }

        board = update_board(board);
        round++;
        if (round == 9)
        {
            std::cout << "Thanks for playing!\n\n";
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
