#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Hash set approach

bool isValidSudoku1(vector<vector<char>>& board){

    // Check rows and columns
    for(int i = 0; i < 9; ++i){
        unordered_set<char> sr;
        unordered_set<char> sc;
        for(int j = 0; j < 9; ++j){
            if(board[i][j] != '.'){
                if(sr.find(board[i][j]) != sr.end()) return false;
                else sr.insert(board[i][j]);
            }
            if(board[j][i] != '.'){
                if(sc.find(board[j][i]) != sc.end()) return false;
                else sc.insert(board[j][i]);
            }
        }
    }

    // Check 3x3 sub-boxes
    for(int i = 0; i < 9; i += 3){
        for(int j = 0; j < 9; j += 3){
            unordered_set<char> sb;
            for(int k = i; k < i + 3; ++k){
                for(int l = j; l < j + 3; ++l){
                    if(board[k][l] != '.'){
                        if(sb.find(board[k][l]) != sb.end()) return false;
                        else sb.insert(board[k][l]);
                    }
                }
            }
        }
    }

    return true;
}

// Neat trick

bool isValidSudoku2(vector<vector<char>>& board){
    
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool sub[9][9] = {false};

    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(board[i][j] == '.') continue;
            int idx = board[i][j] - '0' - 1;
            int k = (i/3) * 3 + (j/3); 

            if(row[i][idx] || col[j][idx] || sub[k][idx]) return false;

            row[i][idx] = true;
            col[j][idx] = true;
            sub[k][idx] = true;

        }
    }

    return true;
}

int main(){

    vector<vector<char>> board = {  {'5', '8', '.', '.', '7', '.', '.', '.', '.'},
                                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                    {'.', '9', '.', '.', '.', '.', '.', '6', '.'},
                                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    bool ok = isValidSudoku2(board);

    if(ok) cout << "The sudoku is valid\n";
    else cout << "The sudoku is not valid\n";

    return 0;
}
