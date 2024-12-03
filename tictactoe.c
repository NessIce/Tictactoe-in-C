#include<stdio.h>

int checkWin(char ttt[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (ttt[i][0] != ' ' && ttt[i][0] == ttt[i][1] && ttt[i][1] == ttt[i][2]) {
            return (ttt[i][0] == 'x') ? 1 : 2;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (ttt[0][j] != ' ' && ttt[0][j] == ttt[1][j] && ttt[1][j] == ttt[2][j]) {
            return (ttt[0][j] == 'x') ? 1 : 2;
        }
    }

    if (ttt[0][0] != ' ' && ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2]) {
        return (ttt[0][0] == 'x') ? 1 : 2;
    }
    
    if (ttt[0][2] != ' ' && ttt[0][2] == ttt[1][1] && ttt[1][1] == ttt[2][0]) {
        return (ttt[0][2] == 'x') ? 1 : 2;
    }

    return 0;
}

int main() {

    char ttt[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    int player;
    do {
        printf("  1  2  3\n");
        for(int i = 0; i<3; i++) {
            printf("%d", i+1);
            for(int j=0; j<3; j++) {
                printf(" %c ", ttt[i][j]);
            }
            printf("\n");
        }
        int x,y;
        printf("Jogador %d: insira sua jogada (x y)-> ", player+1);
        scanf("%d %d", &x, &y);
        if(x<0||x>3||y<0||y>3||ttt[x-1][y-1]!=' ') {
            printf("Ops. jogada invalida, tente novamente!\n");
        } else {
            ttt[x-1][y-1] = (player==0?'x':'o');
        }
        int win = checkWin(ttt);
        if(win==1) {
            printf("  1  2  3\n");
            for(int i = 0; i<3; i++) {
                printf("%d", i+1);
                for(int j=0; j<3; j++) {
                    printf(" %c ", ttt[i][j]);
                }
                printf("\n");
            }
            printf("Parabéns jogador %d, você venceu a partida!", player+1);
            break;
        }
        player = (player==0?1:0);
    } while(1);
}
