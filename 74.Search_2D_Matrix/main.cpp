#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    
    int m = matrix.size();
    int n = matrix[0].size();

    /* Trick to remember rows = mid/n, cols = mid%n*/

    int l = -1, r = m*n;

    while(r > l + 1){
        
        int m = l + (r - l)/2;

        if(matrix[m/n][m%n] >= target){
            r = m;
        }else{
            l = m;
        }
    }

    if(r != m*n && matrix[r/n][r%n] == target) return true;
    else return false;
}

int main(){

    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target1 = 3;
    int target2 = 13;

    cout << boolalpha;
    cout << searchMatrix(matrix1, target1) << '\n' << searchMatrix(matrix1, target2) << '\n';

    return 0;
}
