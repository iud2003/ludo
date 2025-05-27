int handle_mystery_cell(int i, int *ans, int piece[4][4], int position[4][4], int direction[4][4], char color[4][5][3], int max, int mystery_cell_position, int energized[4][4], int sick[4][4], int kotuwa[4][4]);
int summery(char player[4][10], char color[4][5][3], int piece[4][4], int position[4][4], int direction[4][4]);
int order(int max, char player[4][10], char color[4][5][3], int piece[4][4]);
int dice_roll(char player[4][10], int dice[4], int i);
int pick_piece(int i, char color[4][5][3], int piece[4][4], int dice[4], int reach[4], int *ans, char home[4][5][3], char player[4][10], int direction[4][4], int position[4][4], int kotuwa[4][4], int energized[4][4], int sick[4][4], int round);
int piece_eliminate(int i, int ans, char color[4][5][3], int position[4][4], int piece[4][4], int *capture);
int place(int piece[4][4], int i, int position[4][4], char color[4][5][3], char player[4][10], int direction[4][4], int ans);
int select_winner(char player[4][10], int piece[4][4], int winners[4], int *num_winners);

// player behaviors
int red_player_behavior(int piece[4][4], int position[4][4], int dice, char color[4][5][3], int direction[4][4]);
int green_player_behavior(int piece[4][4], int position[4][4], int dice, char color[4][5][3], int direction[4][4]);
int yellow_player_behavior(int piece[4][4], int position[4][4], int dice, char color[4][5][3], int direction[4][4]);
int blue_player_behavior(int piece[4][4], int position[4][4], int dice, char color[4][5][3], int direction[4][4]);