#include <stdio.h>
#include <stdlib.h>

#define Y 25
#define X 80
void scan(int array[Y][X]);
int sost(int a[Y][X], int i, int j);
int functionlife(int a, int b);
void output(int arraynew[Y][X]);
void output_array(int array[Y][X]);
void new_generation (int arraynew[Y][X], int array[Y][X]);
void overwrite(int arraynew[Y][X], int array[Y][X], int comparative[Y][X], int *t, int *schet);
void game();
int main() {
    game();
    return 0;
}
void game(){
    int array[Y][X];
    int arraynew[Y][X];
    int comparative[Y][X];
    int t = 1;
    int c;
    int schet = 0;
    int counter = 0;
    scan(array);
    freopen("/dev/tty","r",stdin);
    printf("Введите скорость анимации: 1 - быстрая, 2 - обычная, 3 -медленная \n");
    if(scanf("%d", &c) != 1 ||( c != 1 && c != 2 && c != 3)) {
        printf("n/a");
        counter += 1;
    }
    output_array(array);
    if (counter == 0){
    while (t == 1) {
        system("clear");
        new_generation(arraynew, array);
        output(arraynew);
        overwrite(arraynew, array, comparative, &t, &schet);
        if (c == 1){
            system("sleep 0.001");
        } else if (c == 2) {
            system("sleep 0.01");
        } else if (c == 3) {
            system("sleep 0.1");
        }
        
        }
    }
    printf("Конец игры!");
}
void output_array(int array[Y][X]) {
    for (int i = 0; i < Y; i++) {
        printf("\n");
        for (int j = 0; j < X; j++) {
            if (array[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
    }
    printf("\n");
}
void overwrite(int arraynew[Y][X], int array[Y][X], int comparative[Y][X], int *t, int *schet) {
    int count = 0;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (comparative[i][j] == arraynew[i][j]) {
                count++;
            } else if(array[i][j] == arraynew[i][j]){
                count++;
            }
        }
    }
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            comparative[i][j] = array[i][j];
            array[i][j] = arraynew[i][j];
        }
    }
    *schet += 1;
    if (count == 2000 || *schet == 1500){
        *t += 1;
    }

}
void new_generation (int arraynew[Y][X], int array[Y][X]){
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            arraynew[i][j] = functionlife(array[i][j], sost(array, i, j));
        }
    }
   
}
void output(int arraynew[Y][X]){
    for (int i = 0; i < Y; i++) {
        printf("\n");
        for (int j = 0; j < X; j++) {
            if (arraynew[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
    }
    printf("\n");
}
void scan(int array[Y][X]) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            scanf("%d", &array[i][j]);
        }
    }
}
int functionlife(int a, int b) {
    char cell;
    if (a == 1) {
        if (b < 2 || b > 3) {
            cell = 0;
        } else {
            cell = 1;
        }
    } else {
        if (b == 3) {
            cell = 1;
        } else {
            cell = 0;
        }
    }
    return cell;
}
    


int sost(int a[Y][X], int i, int j) {
    int sost = 0;
    if (i == 0 && j == 0) {
        sost = a[Y - 1][X - 1] + a[Y - 1][j] + a[Y - 1][j + 1] + a[i][X - 1] +
                a[i][j + 1] + a[i + 1][X - 1] + a[i + 1][j] + a[i + 1][j + 1];
    } else if (i == 0 && j == X - 1) {
        sost = a[Y - 1][j - 1] + a[Y - 1][j] + a[Y - 1][0] + a[i][j - 1] +
                a[i][0] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][0];
    } else if (i == 0 && j == X - 1) {
        sost = a[i - 1][X - 1] + a[i - 1][j] + a[i - 1][0] + a[i][X - 1] +
                a[i][j + 1] + a[0][X - 1] + a[0][j] + a[0][j + 1];
    } else if (i == Y - 1 && j == X - 1) {
        sost = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][0] + a[i][j - 1] + a[i][0] +
                a[0][j - 1] + a[0][j] + a[0][0];
    } else if (i == 0) {
        sost = a[Y - 1][j - 1] + a[Y - 1][j] + a[Y - 1][j + 1] + a[i][j - 1] +
                a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
    } else if (i == Y - 1) {
        sost = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] +
                a[i][j + 1] + a[0][j - 1] + a[0][j] + a[0][j + 1];
    } else if (j == 0) {
        sost = a[i - 1][X - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][X - 1] +
        a[i][j + 1] + a[i + 1][X - 1] + a[i + 1][j] + a[i + 1][j + 1];
    } else if (j == X - 1) {
        sost = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][0] + a[i][j - 1] +
                a[i][0] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][0];
    } else {
        sost = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] +
                a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
    }
    return sost;
}
