#include "Function.h"
#include <stdio.h>
#include <stdlib.h>

int would_capture(int player, int piece, int new_position, int position[4][4]) {
    for (int i = 0; i < 4; i++) {
        if (i != player) {
            for (int j = 0; j < 4; j++) {
                if (position[i][j] == new_position) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int can_enter_home_straight(int player, int piece, int position[4][4]) {
    
    return 1;
}

int red_player_behavior(int piece[4][4], int position[4][4], int dice, char color[4][5][3], int direction[4][4]) {
    int closest_capturable = -1;
    int closest_distance = 52;


    for (int i = 0; i < 4; i++) {
        if (piece[0][i] == 1) {  
            int new_position = (position[0][i] + dice) % 52;
            if (would_capture(0, i, new_position, position)) {
                int distance = (52 + new_position - position[0][i]) % 52;
                if (distance < closest_distance) {
                    closest_distance = distance;
                    closest_capturable = i;
                }
            }
        }
    }

    if (closest_capturable != -1) {
        return closest_capturable;
    }

    int pieces_on_board = 0;
    int last_piece_on_board = -1;
    for (int i = 0; i < 4; i++) {
        if (piece[0][i] == 1) {
            pieces_on_board++;
            last_piece_on_board = i;
        }
    }

    if (pieces_on_board == 1 && dice == 6) {
        for (int i = 0; i < 4; i++) {
            if (piece[0][i] == 0) {
                return i;
            }
        }
    }


    return last_piece_on_board != -1 ? last_piece_on_board : 0;
}

int green_player_behavior(int piece[4][4], int position[4][4], int dice, char color[4][5][3], int direction[4][4]) {
    
    int block_piece = -1;
    for (int i = 0; i < 4; i++) {
        if (piece[2][i] == 1) {  
            for (int j = i + 1; j < 4; j++) {
                if (piece[2][j] == 1 && position[2][i] == position[2][j]) {
                    block_piece = i;
                    break;
                }
            }
            if (block_piece != -1) break;
        }
    }

    
    if (block_piece != -1) {
        return block_piece;
    }

   
    if (dice == 6) {
        for (int i = 0; i < 4; i++) {
            if (piece[2][i] == 0) {
                return i;
            }
        }
    }

   
    int closest_to_home = -1;
    int closest_distance = 52;
    for (int i = 0; i < 4; i++) {
        if (piece[2][i] == 1) {
            int distance = (52 + position[2][i] - 13) % 52;  
            if (distance < closest_distance) {
                closest_distance = distance;
                closest_to_home = i;
            }
        }
    }

    return closest_to_home != -1 ? closest_to_home : 0;
}

int yellow_player_behavior(int piece[4][4], int position[4][4], int dice, char color[4][5][3], int direction[4][4]) {
    
    if (dice == 6) {
        for (int i = 0; i < 4; i++) {
            if (piece[3][i] == 0) {
                return i;
            }
        }
    }

    
    for (int i = 0; i < 4; i++) {
        if (piece[3][i] == 1 && !can_enter_home_straight(3, i, position)) {
            int new_position = (position[3][i] + dice) % 52;
            if (would_capture(3, i, new_position, position)) {
                return i;
            }
        }
    }

   
    int closest_to_home = -1;
    int closest_distance = 52;
    for (int i = 0; i < 4; i++) {
        if (piece[3][i] == 1) {
            int distance = (52 + position[3][i] - 26) % 52;  
            if (distance < closest_distance) {
                closest_distance = distance;
                closest_to_home = i;
            }
        }
    }

    return closest_to_home != -1 ? closest_to_home : 0;
}

int blue_player_behavior(int piece[4][4], int position[4][4], int dice, char color[4][5][3], int direction[4][4]) {
    static int last_moved = -1;

   
    for (int i = 1; i <= 4; i++) {
        int current = (last_moved + i) % 4;
        if (piece[1][current] == 1) {
            last_moved = current;
            return current;
        }
    }

    
    for (int i = 0; i < 4; i++) {
        if (piece[1][i] == 0 && dice == 6) {
            last_moved = i;
            return i;
        }
    }

    return 0;  
}