#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Function.h"

int handle_mystery_cell(int i, int *ans, int piece[4][4], int position[4][4], int direction[4][4], char color[4][5][3], int max,int mystery_cell_position,int energized[4][4],int sick[4][4],int kotuwa[4][4]) {
    //static int mystery_cell_position = -2;
    //static int rounds_left = 0;
    int approach_cell;
    int temp=position[i][*ans],temp1,temp2;

    switch (max) {
        case 0: approach_cell = 38; break;
        case 1: approach_cell = 25; break;
        case 2: approach_cell = 12; break;
        case 3: approach_cell = 51; break;
    }

    if (position[i][*ans] == mystery_cell_position) {
        printf("[%s] player lands on a mystery cell and is teleported to ", color[i][*ans]);
        int teleport = rand() % 6;
        switch(teleport) {
            case 0: 
                printf("Bhawana.\n");
                position[i][*ans] = (approach_cell + 9) % 52; // Bhawana
                if (position[i][*ans] == 0) {
                position[i][*ans] = 52;
                }
                
                if (direction[i][*ans] == 0) { // Clockwise
                        if(position[i][*ans]==52){
                            piece[i][*ans]=0;
                        }
                        if(piece[i][*ans]>=0 && piece[i][*ans]<52){
                            temp1=position[i][*ans]-temp;
                            if(temp1<0){
                                temp2=52-temp+position[i][*ans]+piece[i][*ans];
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                            else{
                                temp2=piece[i][*ans]+temp1;
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                        }
                    } 
                    else { // Counterclockwise
                        if(piece[i][*ans]>0 && piece[i][*ans]<56){
                            temp1=temp-position[i][*ans];
                            if(temp1<0){
                                temp2=temp+piece[i][*ans]+52-position[i][*ans];
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                            else{
                                temp2=piece[i][*ans]+temp1;
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                        }
                    }  
                 if (rand() % 2 == 0) {
                    printf("[%s] piece feels energized, and movement speed doubles.\n", color[i][*ans]);
                    //piece[i][*ans] *= 2; // Double the piece value
                    energized[i][*ans]=1;
                } else {
                    printf("[%s] piece feels sick, and movement speed halves.\n", color[i][*ans]);
                    //piece[i][*ans] = (piece[i][*ans] + 1) / 2; // Halve the piece value (rounded up)
                    sick[i][*ans]=1;
                } 
                
                break;
            case 1: 
                printf("Kotuwa.\n");
                position[i][*ans] = (approach_cell + 27) % 52; // Kotuwa
                if (position[i][*ans] == 0) {
                position[i][*ans] = 52;
                }
                if (direction[i][*ans] == 0) { // Clockwise
                        if(position[i][*ans]==52){
                            piece[i][*ans]=0;
                        }
                        if(piece[i][*ans]>=0 && piece[i][*ans]<52){
                            temp1=position[i][*ans]-temp;
                            if(temp1<0){
                                temp2=52-temp+position[i][*ans]+piece[i][*ans];
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                            else{
                                temp2=piece[i][*ans]+temp1;
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                        }
                    } 
                    else { // Counterclockwise
                        if(piece[i][*ans]>0 && piece[i][*ans]<56){
                            temp1=temp-position[i][*ans];
                            if(temp1<0){
                                temp2=temp+piece[i][*ans]+52-position[i][*ans];
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                            else{
                                temp2=piece[i][*ans]+temp1;
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                        }
                    }      
                break;
                kotuwa[i][*ans]=1;
            case 2: 
                printf("Pita-Kotuwa.\n");
                position[i][*ans] = (approach_cell + 46) % 52; // Pita-Kotuwa
                if (position[i][*ans] == 0) {
                position[i][*ans] = 52;
                }

                if (direction[i][*ans] == 0) {
                    direction[i][*ans] = 1;
                    printf("The [%s] piece, which was moving clockwise, has changed to moving counterclockwise.\n",color[i][*ans]);
                } else {
                    position[i][*ans] = (approach_cell + 27) % 52; // Teleport to Kotuwa
                    printf("The [%s] piece is moving in a counterclockwise direction. Teleporting to Kotuwa from Pita-Kotuwa.\n", color[i][*ans]);
                    position[i][*ans] = (approach_cell + 27) % 52; // Kotuwa
                    if (position[i][*ans] == 0) {
                    position[i][*ans] = 52;
                    }
                }
                 if (direction[i][*ans] == 0) { // Clockwise
                        if(position[i][*ans]==52){
                            piece[i][*ans]=0;
                        }
                        if(piece[i][*ans]>=0 && piece[i][*ans]<52){
                            temp1=position[i][*ans]-temp;
                            if(temp1<0){
                                temp2=52-temp+position[i][*ans]+piece[i][*ans];
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                            else{
                                temp2=piece[i][*ans]+temp1;
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                        }
                    } 
                    else { // Counterclockwise
                        if(piece[i][*ans]>0 && piece[i][*ans]<56){
                            temp1=temp-position[i][*ans];
                            if(temp1<0){
                                temp2=temp+piece[i][*ans]+52-position[i][*ans];
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                            else{
                                temp2=piece[i][*ans]+temp1;
                                if(temp2>52){
                                    piece[i][*ans] =temp2%52;
                                }
                                else{piece[i][*ans] =temp2;}
                            }
                        }
                    }
                    
                break;
            case 3: 
                printf("Base.\n");
                piece[i][*ans] = 0;
                position[i][*ans] = 0;
                return 0; 
            case 4: 
                printf("X of the piece color.\n");
                piece[i][*ans] = 1;
                position[i][*ans] = i * 13 + 1;
                return 0;
            case 5: 
                printf("Approach of the piece color.\n");
                position[i][*ans] = (i * 13 + 51) % 52;
                if(direction[i][*ans]==0){
                    piece[i][*ans] = 51;
                }
                else{piece[i][*ans] = 55;}
                return 0; 
        }
        

    }

    return 0;
}
int summery(char player[4][10], char color[4][5][3], int piece[4][4], int position[4][4], int direction[4][4]) {
    int i, j, board, base;

    for (i = 0; i < 4; i++) {
        base = 0;
        board = 4;

        for (j = 0; j < 4; j++) {
            if (piece[i][j] == 0) {
                base++;
            } else if (piece[i][j] == -1 || piece[i][j] == 0) {
                board--;
            }
        }

        printf("[%s] player now has %d/4 on pieces on the board and %d/4 pieces on the base\n", player[i], board, base);
        printf("============================\n");
        printf("Location Of Each Piece Of [%s] Player\n", player[i]);
        printf("============================\n");
    
        for (j = 0; j < 4; j++) {
            if (piece[i][j] == 0) {
                printf("Piece %s= At Base\n", color[i][j]);
            } else if (piece[i][j] == -1) {
                printf("Piece %s= At Home\n", color[i][j]);
            } 
            else if(direction[i][j] ==0){
                if (piece[i][j] > 0 && piece[i][j] < 52) {
                    printf("Piece %s= %d and pi=%d\n", color[i][j], position[i][j],piece[i][j]);
                }
                else if(piece[i][j]<57 && piece[i][j]>=52){
                    printf("Piece %s= In Home Line \n", color[i][j]);
                }
            }
            else if(direction[i][j] ==1){
                if (piece[i][j] > 0 && piece[i][j] < 56) {
                    printf("Piece %s= %d and pi=%d\n", color[i][j], position[i][j],piece[i][j]);
                }
                else if(piece[i][j]<61 && piece[i][j]>=56){
                    printf("Piece %s= In Home Line \n", color[i][j]);
                }
            }


        }
        printf("\n");
    }

    return 0;
}
int order(int max, char player[4][10], char color[4][5][3], int piece[4][4]) {
    int i, count, j;
    char neworder[4][10];
    char newColorOrder[4][5][3];
    int newPieceOrder[4][4];
    
    count = max;
   
    for (i = 0; i < 4; i++) {
        strcpy(neworder[i], player[count]);
        count++;
        if (count >= 4) {
            count = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        strcpy(player[i], neworder[i]);
    }

    count = max;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            strcpy(newColorOrder[i][j], color[count][j]);
        }
        count++;
        if (count >= 4) {
            count = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            strcpy(color[i][j], newColorOrder[i][j]);
        }
    }

    count = max;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            newPieceOrder[i][j] = piece[count][j];
        }
        count++;
        if (count >= 4) {
            count = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            piece[i][j] = newPieceOrder[i][j];
        }
    }
    
    return 0; 
}


int dice_roll(char player[4][10], int dice[4], int i) {
    dice[i] = rand() % 6 + 1;
    
    printf("[%s] rolled %d\n", player[i],dice[i]);

    return dice[i];
}
int round_roll[4][4]={0},mark;
int round_kotuwa[4]={1};
int temp2=0;
int temp3=0;//for store round value

int pick_piece(int i, char color[4][5][3], int piece[4][4], int dice[4], int reach[4], int *ans, char home[4][5][3], char player[4][10], int direction[4][4],int position[4][4], int kotuwa[4][4], int energized[4][4], int sick[4][4],int round) {
    int j, count = 0, moveable[4] = {-1, -1, -1, -1};
    int all_pieces_home = 1;
    int coin;
    int temp[4][4]={0};

    switch(i) {
        case 0:  // Blue
            *ans = blue_player_behavior(piece, position, dice[i], color, direction);
            break;
        case 1:  // Red
            *ans = red_player_behavior(piece, position, dice[i], color, direction);
            break;
        case 2:  // Green
            *ans = green_player_behavior(piece, position, dice[i], color, direction);
            break;
        case 3:  // Yellow
            *ans = yellow_player_behavior(piece, position, dice[i], color, direction);
            break;
    }
    for (j = 0; j < 4; j++) {
        if (piece[i][j] != 0) {
            all_pieces_home = 0;
            break;
        }
    }

    if (all_pieces_home && dice[i] != 6) {
        printf("No moveable pieces for [%s]\n", player[i]);
        return 0;
    }

    for (j = 0; j < 4; j++) {
        if ((piece[i][j] > 0 && (piece[i][j] + dice[i]) <= 57) || (piece[i][j] == 0 && dice[i] == 6)) {
            moveable[count] = j;
            count++;
        }
    }

    if (count == 0) {
        printf("No moveable pieces for [%s]\n", player[i]);
        return 0;
    }

    int x=0;
    while(x==0){
        *ans = moveable[rand() % count];
        if(kotuwa[i][*ans] == 0){
            x=1;
            break;
        }
    }
    if (piece[i][*ans] == 0 && dice[i] == 6) {
        piece[i][*ans] = 1;
        printf("[%s] moved to starting square 'X'\n", color[i][*ans]);
        printf("Flip the coin to find direction\n");
        coin = rand() % 2;
        if (coin == 0) {
            printf("Coin flipped Head And Piece Can Move In Clockwise\n");
            direction[i][*ans] = 0;
            temp[i][*ans] = 0;
        } else {
            printf("Coin flipped Tail and Piece Can Move In Counterclockwise\n");
            direction[i][*ans] = 1;
            temp[i][*ans] = 1;
        }
    } else if (piece[i][*ans] > 0) {
        int new_position = piece[i][*ans] + dice[i];
        if (new_position == 57 && temp[i][*ans]==0 ) {
            piece[i][*ans] = -1;
            // mark it came to home in position  ignor captures in home
            if(i ==0){
                position[i][*ans]=100+j ;
            }
            if(i ==1){
                position[i][*ans]=150+j ;
            }
            if(i ==2){
                position[i][*ans]=200+j ;
            }
            if(i ==3){
                position[i][*ans]=250+j ;
            }
            strcpy(home[i][*ans], color[i][*ans]);
            reach[i]++;
            printf("[%s] piece reached home\n", color[i][*ans]);
        }
        else if (new_position == 61 && temp[i][*ans]==1 ) {
            piece[i][*ans] = -1;
            // mark it came to home in position  ignor captures in home
            if(i ==0){
                position[i][*ans]=100+j ;
            }
            if(i ==1){
                position[i][*ans]=150+j ;
            }
            if(i ==2){
                position[i][*ans]=200+j ;
            }
            if(i ==3){
                position[i][*ans]=250+j ;
            }
            strcpy(home[i][*ans], color[i][*ans]);
            reach[i]++;
            printf("[%s] piece reached home\n", color[i][*ans]);
        }
        
        else {
            int count_mystery=0;
            piece[i][*ans] = new_position;
            //int temp1=dice[i];
            static int previous_rolls[4] = {0};  // Array to store previous roll for each player
            if (previous_rolls[i] == 3 && dice[i] == 3 && mark== 1) {
                printf("[%s] rolled two consecutive 3s and %s piece move back kotuwa to base!\n", player[i],color[i][temp2]);
                piece[i][temp2]=0; 
                position[i][temp2]=0;
            
            }
            previous_rolls[i] = dice[i];

            for (int j = 0; j < 4; j++) {
                
                if (energized[i][j] == 1 && round_roll[i][j] <= 4) {
                    dice[i] = dice[i] * 2;
                    temp3=round-temp3;
                    if(temp3>0){
                        round_roll[i][j]++;
                    }
                    
                    if (round_roll[i][j] == 4) {
                        energized[i][j] = 0;
                        round_roll[i][j] = 0;
                       
                    }
                    count_mystery= 1;
                }
                if (sick[i][j] == 1 && round_roll[i][j] <= 4) {
                    dice[i] = dice[i] / 2;
                    temp3=round-temp3;
                    if(temp3>0){
                        round_roll[i][j]++;
                    }
                    if (round_roll[i][j] == 4) {
                        sick[i][j] = 0;
                        round_roll[i][j] = 0;
                        
                    }
                    count_mystery=2;
                }
                if (kotuwa[i][j] == 1 && round_roll[i][j] <= 4) {
                    dice[i] = 0;
                    mark = 1;  // mark if there is a piece in kotuwa
                    temp2 = j;
                    temp3=round-temp3;
                    if(temp3>0){
                        round_roll[i][j]++;
                    }
                    if (round_roll[i][j] == 4) {
                        kotuwa[i][j] = 0;
                        round_roll[i][j] = 0;
                        mark = 0;
                        
                    }
                    count_mystery=3;
                }
            }
            //printf("count mystery: %d\n", count_mystery); //for check corrections
            if (count_mystery== 1) {
                printf("[%s] piece energized and doubled roll value to %d\n", color[i][*ans], dice[i]/2);
                printf("[%s] piece moved %d blocks\n", color[i][*ans], dice[i]);
            } 
            else if (count_mystery==2) {
                printf("[%s]  piece sicked and halved roll value to %d\n", color[i][*ans],  dice[i]);
                printf("[%s] piece moved %d blocks\n", color[i][*ans], dice[i]);
            } 
            else if (count_mystery==3) {
                printf("[%s] the piece has to attend a briefing and cannot move\n", color[i][*ans]);
                printf("[%s] piece moved %d blocks\n", color[i][*ans], dice[i]);
            }
            else{
                printf("[%s] piece moved %d blocks\n", color[i][*ans], dice[i]);
            }
            
        }
    }

    return 0;
}

int piece_eliminate(int i, int ans, char color[4][5][3], int position[4][4], int piece[4][4],int *captured) {
    int j, x;
    

    for (j = 0; j < 4; j++) {
        if (j != i) {
            for (x = 0; x < 4; x++) {
                if (position[i][ans] == position[j][x] && position[i][ans] != 0 && piece[j][x]>0 && piece[j][x]<56) {
                    if (*captured==0) {
                        printf("[%s] piece captured by [%s]!\n", color[i][ans], color[j][x]);
                        piece[j][x] = 0;
                        position[j][x] = 0;
                        *captured = 1;
                        return 1; 
                    }
                }
            }
        }
        else{

        }
    }
    return 0;
}

int place(int piece[4][4], int i, int position[4][4], char color[4][5][3], char player[4][10], int direction[4][4], int ans){
    int j = ans;

    
    if (piece[i][ans] == 1) {
        position[i][ans] = (i * 13) + 1;
        //printf("%d\n", position[i][j]);
    } 
    else if(direction[i][j] == 0) {
        if (piece[i][j] > 1 && piece[i][j] < 52) {
            position[i][j] = ((i * 13)+1 + piece[i][j]-1 ) % 52;;
            //printf("%d\n", position[i][j]);
            if (position[i][j] == 0) {
                position[i][j] = 52;
            }
        }
    //put random position numbers to ignor capture in home lines
        else if (piece[i][j] <57 && piece[i][j]>=52) {
            if(i ==0){
                position[i][j]=100+j+i;
            }
            if(i ==1){
                position[i][j]=150+j+i ;
            }
            if(i ==2){
                position[i][j]=200+j+i;
            }
            if(i ==3){
                position[i][j]=250+j+i ;
            }
            
        }
    }
    else if(direction[i][j] == 1) {
        if (piece[i][j] > 1 && piece[i][j] < 56) {
            int temp2;
            temp2 = ((i*13)+1- piece[i][j] +1) ;
            if(temp2<=0){
                position[i][j]= ((i * 13)+1- piece[i][j]+1 +52) ;
            }
            else{
                position[i][j]= ((i * 13)+1- piece[i][j]+1 ) ;
            }
            //printf("%d\n", position[i][j]);
        }
        else if (piece[i][j] <61 && piece[i][j]>=56) {
            //put random position numbers to ignor capture in home lines
            if(i ==0){
                position[i][j]=100+j+i;
            }
            if(i ==1){
                position[i][j]=150+j+i ;
            }
            if(i ==2){
                position[i][j]=200+j+i;
            }
            if(i ==3){
                position[i][j]=250+j+i ;
            }
            
        }
    }
    
    return 0; 
}
int select_winner(char player[4][10], int piece[4][4], int winners[4], int *numwinners) {
    int i, j;
    for (i = 0; i < 4; i++) {
        if (winners[i] == 0) {  
            int allhome = 1;
            for (j = 0; j < 4; j++) {
                if (piece[i][j] != -1) {
                    allhome = 0;
                    break;
                }
            }
            if (allhome) {
                winners[i] = *numwinners + 1;  
                (*numwinners)++;  

                printf("\n****************************************\n");
                printf("[%s] is the ", player[i]);
                
                switch (*numwinners) {
                    case 1: printf("%dst", winners[i]); break;
                    case 2: printf("%dnd", winners[i]); break;
                    case 3: printf("%drd", winners[i]); break;
                    default: printf("%dth", winners[i]); break;
                }
                
                printf(" winner! ⭐\n");
                printf("****************************************\n");
            }
        }
    }
    return (*numwinners == 4);  
}

