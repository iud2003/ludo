#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Function.h"
//#include "constants.h"


int main() {
    int i, count, max, maximum;
    int dice[4] = {0};
    int piece[4][4] = {0}, position[4][4] = {0};
    char color[4][5][3] = {{"B1", "B2", "B3", "B4"}, {"R1", "R2", "R3", "R4"}, {"G1", "G2", "G3", "G4"}, {"Y1", "Y2", "Y3", "Y4"}};
    char home[4][5][3] = {};
    char player[4][10] = {"Blue", "Red", "Green", "Yellow"};
    int energized[4][4]={0},sick[4][4]={0},kotuwa[4][4]={0};
    int round=0;
    srand(48);  

    while (1) {
        count = 0;
        max = 0;
        maximum = 0;

        for (i = 0; i < 4; i++) {
            dice_roll(player, dice, i);
            if (dice[i] > maximum) {
                maximum = dice[i];
                max = i;
            }
        }

        for (i = 0; i < 4; i++) {
            if (maximum == dice[i]) {
                count++;
            }
        }

        if (count == 1) {
            break;
        }
        printf("All roll the dice again\n\n");
    }
    printf("\n%s Starts The Game First\n", player[max]);

    // Find new order
    order(max, player, color, piece);

    int reach[4] = {0, 0, 0, 0};
    int ans = 0;
    int winners[4] = {0};  // Tracks which players have won
    int numwinners = 0;   // Counts how many players have finished
    int direction[4][4]={0};
    int mystery_cell_position=-2;
    
while (numwinners < 4) {
        round++;
        
        if (round%4==0) {
            mystery_cell_position = rand() % 52 + 1;
            printf("A mystery cell has spawned in location %d and will be at this location for the next four rounds.\n", mystery_cell_position);
        }
        for (i = 0; i < 4; i++) {
            if (winners[i] != 0) continue;  // Skip if player has already won
            int captured = 0; 
            dice_roll(player, dice, i);
            if (dice[i] == 6) {
                pick_piece(i, color, piece, dice, reach, &ans, home,player,direction,position,kotuwa,energized,sick,round);
                place(piece, i, position, color, player,direction,ans);
                handle_mystery_cell(i, &ans, piece, position, direction, color,max,mystery_cell_position,energized,sick,kotuwa);
                piece_eliminate(i, ans, color, position, piece,&captured);
                if (select_winner(player, piece, winners, &numwinners)) {
                   // printf("%s wins the game!\n", player[i]);
                    winners[i] = 1;  // Mark player as a winner
                    numwinners++;
                    continue;

                }
                printf("# Roll Again #\n");
                dice_roll(player, dice, i);
                if (dice[i] == 6) {
                    pick_piece(i, color, piece, dice, reach, &ans, home,player,direction,position,kotuwa,energized,sick,round);
                    place(piece, i, position, color, player,direction,ans);
                    handle_mystery_cell(i, &ans, piece, position, direction, color,max,mystery_cell_position,energized,sick,kotuwa);
                    piece_eliminate(i, ans, color, position, piece,&captured);
                    if (select_winner(player, piece, winners, &numwinners)) {
                        //printf("%s wins the game!\n", player[i]);
                        winners[i] = 1;  // Mark player as a winner
                        numwinners++;
                        continue;
                    }
                    printf("# Roll Again #\n");
                    dice_roll(player, dice, i);
                    if (dice[i] == 6) {
                        pick_piece(i, color, piece, dice, reach, &ans, home,player,direction,position,kotuwa,energized,sick,round);
                        place(piece, i, position, color, player,direction,ans);
                        handle_mystery_cell(i, &ans, piece, position, direction, color,max,mystery_cell_position,energized,sick,kotuwa);
                        piece_eliminate(i, ans, color, position, piece,&captured);
                        if (select_winner(player, piece, winners, &numwinners)) {
                           // printf("%s wins the game!\n", player[i]);
                            winners[i] = 1;  // Mark player as a winner
                            numwinners++;
                            continue;
                        }
                    } else {
                        pick_piece(i, color, piece, dice, reach, &ans, home,player,direction,position,kotuwa,energized,sick,round);
                        place(piece, i, position, color, player,direction,ans);
                        handle_mystery_cell(i, &ans, piece, position, direction, color,max,mystery_cell_position,energized,sick,kotuwa);
                        piece_eliminate(i, ans, color, position, piece,&captured);
                        if (select_winner(player, piece, winners, &numwinners)) {
                           // printf("%s wins the game!\n", player[i]);
                            winners[i] = 1;  // Mark player as a winner
                            numwinners++;
                            continue;
                        }
                    }
                } else {
                    pick_piece(i, color, piece, dice, reach, &ans, home,player,direction,position,kotuwa,energized,sick,round);
                    place(piece, i, position, color, player,direction,ans);
                    handle_mystery_cell(i, &ans, piece, position, direction, color,max,mystery_cell_position,energized,sick,kotuwa);
                    piece_eliminate(i, ans, color, position, piece,&captured);
                    if (select_winner(player, piece, winners, &numwinners)) {
                        //printf("%s wins the game!\n", player[i]);
                        winners[i] = 1;  // Mark player as a winner
                        numwinners++;
                        continue;
                    }
                }
            } else {
                pick_piece(i, color, piece, dice, reach, &ans, home,player,direction,position,kotuwa,energized,sick,round);
                place(piece, i, position, color, player,direction,ans);
                handle_mystery_cell(i, &ans, piece, position, direction, color,max,mystery_cell_position,energized,sick,kotuwa);
                piece_eliminate(i, ans, color, position, piece,&captured);
                if (select_winner(player, piece, winners, &numwinners)) {
                    //printf("%s wins the game!\n", player[i]);
                    winners[i] = 1;  // Mark player as a winner
                    numwinners++;
                    continue;
                }
            }
            if(captured==1){
                i--;
                printf("Player Can Roll Dices Again\n");
            }
            printf("\n");
        }
        summery( player,color,piece,position,direction);
        printf("\n");
    }

    return 0;
}
