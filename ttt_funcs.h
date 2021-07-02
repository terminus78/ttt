bool is_winner(std::vector<char> board, int player);

bool filled_up(std::vector<char> board);

void introduction();

void take_turn(int player);

std::vector<char> set_position(std::vector<char> board, int player);

std::vector<char> update_board(std::vector<char> board);

int change_player(int player);

void draw(std::vector<char> board);

void end_game(bool winner, int player = 0);

bool end_play();