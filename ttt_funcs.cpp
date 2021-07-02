#include <iostream>
#include <vector>

void introduction()
{
	std::cout << "Welcome to Tic-Tac-Toe\n";
	std::cout << "======================\n";
}

void draw(std::vector<char> board)
{
	std::cout << "     |     |     \n";
	std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
	std::cout << "     |     |     \n";
}

void take_turn(int player)
{
	std::cout << "Player " << player << " choose your position.\n";
}

bool verify_input(std::vector<char> board, int index)
{
	if (board[index] == 'X' || board[index] == 'O')
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::vector<char> set_position(std::vector<char> board, int player)
{
	bool not_ready = true;
	int row = 0;
	int col = 0;
	char token;
	int board_index;

	while (not_ready)
	{
		char y_n;
		bool ready = false;

		while (!ready)
		{
			std::cout << "Row # (from top): ";
			std::cin >> row;
			std::cout << "Column # (from left): ";
			std::cin >> col;
			std::cout << "You selected row " << row << ", column " << col << ". Is this correct? (y/n) ";
			std::cin >> y_n;

			if (y_n == 'y' && row > 0 && row <= 9 && col > 0 && col <= 9)
			{
				ready = true;
			}
		}

		board_index = (col + (row - 1) * 3) - 1;

		if (player == 1)
		{
			token = 'X';
		}
		else
		{
			token = 'O';
		}

		if (verify_input(board, board_index))
		{
			not_ready = false;
		}
		else
		{
			std::cout << "This position is taken. Please try again.\n";
		}
	}

	board[board_index] = token;

	return board;
}

int change_player(int player)
{
	if (player == 1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

bool is_winner(std::vector<char> board, int player)
{
	char token_to_check;
	if (player == 1)
	{
		token_to_check = 'X';
	}
	else
	{
		token_to_check = 'O';
	}

	// Win conditions
	// Row 1
	if (board[0] == token_to_check && board[1] == token_to_check && board[2] == token_to_check)
	{
		return true;
	}
	// Row 2
	else if (board[3] == token_to_check && board[4] == token_to_check && board[5] == token_to_check)
	{
		return true;
	}
	// Row 3
	else if (board[6] == token_to_check && board[7] == token_to_check && board[8] == token_to_check)
	{
		return true;
	}
	// Column 1
	else if (board[0] == token_to_check && board[3] == token_to_check && board[6] == token_to_check)
	{
		return true;
	}
	// Column 2
	else if (board[1] == token_to_check && board[4] == token_to_check && board[7] == token_to_check)
	{
		return true;
	}
	// Column 3
	else if (board[2] == token_to_check && board[5] == token_to_check && board[8] == token_to_check)
	{
		return true;
	}
	// Diagonal down
	else if (board[0] == token_to_check && board[4] == token_to_check && board[8] == token_to_check)
	{
		return true;
	}
	// Diagonal up
	else if (board[2] == token_to_check && board[4] == token_to_check && board[6] == token_to_check)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool filled_up(std::vector<char> board)
{
	bool check_val = true;

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i] != 'X' && board[i] != 'O')
		{
			check_val = false;
		}
	}

	return check_val;
}

void end_game(bool winner, int player = 0)
{
	if (winner)
	{
		std::cout << "Player " << player << " wins!!!\n";
	}
	else
	{
		std::cout << "Game is a tie.\n";
	}
}

bool end_play()
{
	char end;
	bool not_y_n = true;

	std::cout << "Play again? (y/n) ";
	std::cin >> end;

	if (end == 'y')
	{
		return false;
	}
	else
	{
		std::cout << "Thanks for playing!\n\n";
		return true;
	}
}

std::vector<char> update_board(std::vector<char> board)
{
	for (int i = 0; i < board.size(); i++)
	{
		board[i] = ' ';
	}

	return board;
}