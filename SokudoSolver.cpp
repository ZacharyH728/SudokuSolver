#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>

#define N 10
using namespace std;

int (*makethemagic())[N]
{

    int(*table)[N] = new int[N][N];
    int k=0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            table[i][j] = rand() % 10;

     return table;
}

bool colchecker(int(*magic)[N], int col, int num){
    for (int row = 0; row < 9; row++){
        if (magic[row][col]){
            return true;
        }
    }
    return false;
}

bool rowchecker(int(*magic)[N], int row, int num){
    for (int col = 0; col < 9; col++){
        if (magic[row][col] == num){
            return true;
        }
    }
    return false;
}


bool box(int(*magic)[N],int firstrow, int firstcol, int num){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (magic[row + firstrow][col + firstcol] == num){
                return true;
            }
        }
    }
    return false;
}


void printout(int(*magic)[N]){
    cout << "\n";
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            if (col == 3 || col == 6){
                cout << " ";
            }
            if (magic[row][col] <= 9){
                cout << " " << magic[row][col] << " ";
            }else{
                cout << magic[row][col] << " ";
            }
        }
        if (row == 2 || row == 5){
            cout << "\n";
        }
        cout << "\n";
    }
    cout << "\n"; 
}
bool arewedoneyet(int (*magic)[N],int &row, int &col){
    for (row = 0; row < 9; row++){
        for (col = 0; col < 9; col++){
            if (magic[row][col] == 0){
                return true;
            }
        }
    }
    return false;
}
bool isGoodorNah(int(*magic)[N], int row, int col, int num){
    return !colchecker(magic, col, num) && !rowchecker(magic, row, num) && !box(magic, row - row % 3, col - col % 3, num);
}

bool isitSolved(int(*magic)[N]){
    int row, col;
    if (!arewedoneyet(magic, row, col)){
        return true;
    }
    cout << row << "\n";
    for (int num = 1; num <= 9; num++){
        //cout << num << "\n";
        if (isGoodorNah(magic, row, col, num)){
            magic[row][col] = num;
            if (isitSolved(magic)){
                return true;
            }
            magic[row][col] = 0;
        }
    }
    return false;
}

int main(int argc, char **argv){
    srand((unsigned int)time(NULL));
    int t[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    //int(*t)[N] = makethemagic();
    printout(t);
    if (isitSolved(t)){
        printout(t);
        delete[] t;
    }else{
        cout << "Cant do it";
    }

    //cleanup time because the stackoverflow person said so
    //system("PAUSE");
}