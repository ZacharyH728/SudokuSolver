#include <cstdlib> 
#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <set>
using namespace std;

int i;
int j;
int k;

vector<int> board{
1, 7, 0, 3, 0, 5, 6, 9, 0,
8, 0, 0, 0, 9, 0, 0, 0, 0,
0, 0, 6, 7, 4, 0, 5, 0, 0,
5, 4, 0, 2, 0, 0, 0, 0, 0,
2, 6, 3, 0, 0, 0, 4, 1, 9,
0, 0, 0, 0, 0, 6, 0, 5, 7,
0, 0, 9, 0, 8, 3, 0, 6, 0,
0, 0, 0, 0, 7, 0, 0, 0, 3,
0, 8, 4, 0, 0, 2, 0, 7, 5
};


void print(vector<int> board){
    for (int i = 0; i < board.size(); i++){   
        if (i % 3==0){
            cout << " ";
        }
        if (i % 9==0){
            cout << "\n"; 
        }
        if (i % 27 == 0)
        {
            cout << "\n";
        }
        if (board[i] <= 9){
            cout << " ";
        }
        cout << board[i] << " ";
    }
    cout << "\n";
    cout << "\n";
}
void checker(vector<int> board){
    int row = i / 9 + 1;
    int column = i - 10 * (i / 9) + (1 * i / 9) + 1;
    for (int i = 0; i < board.size(); i++){
        //i = 1;
        int row = i / 9 + 1;
        int column = i - 10 * (i / 9) + (1 * i / 9) + 1;
        //cout << board[i] << " " << i << "\n"; //prints out values of board in order and what number on the board
        //cout << row << " " << column << "\n";
        for (int j = column; j < 10 - column; j++){
            //cout << "(" << row << "," << column << ")" << " (" << row << "," << column + j << ")" << j << "\n";
            if (board[i] == board[i + j] && board[i] != 0){
                cout << "(" << row << "," << column << ")" <<" Number " << board[i] << " (" << row << "," << column + j <<") " << "Different Column" << "\n";  
            }
        }
        for (int j = 1; j < 81; j+=9){
            //cout << j << " :: " << row << "\n";
            if (board[i] == board[i + 9] && board[i] != 0){
                cout << "(" << row << "," << column << ")" <<" Number " << board[i] << " (" << row + (j / 9) << "," << column <<") " << "Different Row" << "\n";  
            }   
        }
    }
    set<int> s{board[0]};
    for (int i = 0; i <= 81;){
        int row = i / 9 + 1;
        int column = i - 10 * (i / 9) + (1 * i / 9) + 1;
        //cout << board[i] << " " << i << "\n";
        for (int j = row; j <= 9;  j++){   
            for (int k = column; k <= 9; k++){
                if (s.find(board[i]) != s.end()){
                    cout << i << " " << board[i] << "\n";
                }
                s.insert(k);
                /*for (std::set<int>::iterator it = s.begin(); it != s.end(); it++){
                    std::cout << *it << " " << k << std::endl;
                }*/
            }
            s.clear();
            //for (int k = row; k < 28; k+=9){
                /*
                for (std::set<int>::iterator it = previousNumbers.begin(); it != previousNumbers.end(); it++){
                    std::cout << *it << std::endl;
                }
                if (previousNumbers.find(board[i]) != previousNumbers.end()){
                    cout << "(" << row << "," << column << ")" <<" Number " << board[k] << " Different Box" << "\n";
                }
                previousNumbers.insert(board[k]);
                */
                //cout << k << " :: " << row << "\n";
                 
            //}
        }
        if(i / 6 && column == 7){
            i += 21;
        }else{
            i += 3;
        }
    }
    
}
int main(){
    print(board);
    checker(board);
    //system("PAUSE");
    return 0;
}