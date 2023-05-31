#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// Time complexity  : O(n^2)
// Space complexity : O(1) 

int maxArea1(vector<int>& height){

    int curr_max = 0;
    int n = height.size();

    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            int area = min(height[i], height[j]) * (j - i);
            curr_max = max(curr_max, area);
        }
    }

    return curr_max;
}

// Two Pointers Approach
// Time complexity  : O(n)
// Space complexity : O(1)

int maxArea2(vector<int>& height){

    int curr_max = 0;
    int n = height.size();
    int i = 0, j = n - 1;

    while(j > i){
        
        int area = min(height[i], height[j]) * (j - i);
        curr_max = max(curr_max, area);

        if(height[i] > height[j]) --j;
        else ++i;
    }

    return curr_max;
}

int main(){

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    cout << maxArea2(height) << '\n';

    return 0;
}
