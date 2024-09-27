#include <stdio.h>

void ball_m();
void frame();
void press_but();

int row = 25;  // Oc y
int col = 80;  // Oc x
int ball_x = 11;
int ball_y = 40;
int dvizh_x = 1;
int dvizh_y = 1;
char click_button_player;

int x_button1 = 13;
int y_button1 = 1;
int x_button2 = 13;
int y_button2 = 78;

int score_1_p = 00;
int score_2_p = 00;
int count = 1;

int value;

int main(void) {
    while (1) {
        ball_m();
        if ((score_1_p >= 21) || (score_2_p >= 21)) {
            if (score_1_p > 20) {
                printf("                                  GAME over\n\n");
                printf("                               Player 1 WINNER\n\n");
                printf("                               Score:  %d : %d\n\n", score_1_p, score_2_p);
                break;
            }
            if (score_2_p > 20) {
                printf("                                  GAME over\n\n");
                printf("                               Player 2 WINNER\n");
                printf("                               Score:  %d : %d\n\n", score_1_p, score_2_p);
                break;
            }
        }
        printf("                                     Score\n\n");
        printf("                         Player 1 = %d : Player 2 = %d\n", score_1_p, score_2_p);

        frame(ball_x, ball_y, x_button1, y_button1, x_button2, y_button2);

        press_but();
    }
    return 0;
}

void frame(int ball_x, int ball_y, int x_button1, int y_button1, int x_button2, int y_button2) {
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            if (x == 0 || x == row - 1) {
                putchar('-');
            } else if (y == 0 || y == col - 1) {
                putchar('|');
            } else if (((x_button1 == x) && (y_button1 == y)) || ((x_button1 == x + 1) && (y_button1 == y)) ||
                       ((x_button1 == x + 2) && (y_button1 == y))) {
                putchar('[');
            } else if (((x_button2 == x) && (y_button2 == y)) || ((x_button2 == x + 1) && (y_button2 == y)) ||
                       ((x_button2 == x + 2) && (y_button2 == y))) {
                putchar(']');
            } else if ((ball_x == x) && (ball_y == y)) {
                putchar('o');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

void press_but() {
    while ((click_button_player = getchar()) != '\n') {
        if (click_button_player == 'z') {
            if (x_button1 <= row - 3) {
                x_button1++;
            }
        } else if (click_button_player == 'a') {
            if (x_button1 >= 4) {
                x_button1--;
            }
        } else if (click_button_player == 'm') {
            if (x_button2 <= row - 3) {
                x_button2++;
            }
        } else if (click_button_player == 'k') {
            if (x_button2 >= 4) {
                x_button2--;
            }
        } else if (click_button_player == ' ') {
            continue;
        }
    }
}

void ball_m() {
    if (ball_y == 0 || ball_y == col - 1) {
        dvizh_y = -(dvizh_y);
    }
    if (ball_x == 1 || ball_x == row - 2) {
        dvizh_x = -(dvizh_x);
    }

    if (ball_y == 0) {
        score_2_p += 1;
    }
    if (ball_y == 79) {
        score_1_p += 1;
    }

    if (((ball_x == x_button1) || (ball_x == (x_button1 - 1)) || (ball_x == (x_button1 - 2))) &&
        ((ball_y == 2))) {
        dvizh_y = -(dvizh_y);
    }
    if (((ball_x == x_button2) || (ball_x == (x_button2 - 1)) || (ball_x == (x_button2 - 2))) &&
        ((ball_y == 77))) {
        dvizh_y = -(dvizh_y);
    }

    ball_x += dvizh_x;
    ball_y += dvizh_y;
}
