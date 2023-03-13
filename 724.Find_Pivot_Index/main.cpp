#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int pivotIndex1(vector<int> &nums){

    int sum_left = 0, sum_right = 0;
    int n = nums.size();

    for(int i = 0; i < n; ++i){
        
        if(i) sum_left += nums[i - 1];
        sum_right = 0;
        for(int j = i + 1; j < n; ++j){
            sum_right += nums[j];
        }

        if(sum_left == sum_right) return i;
    }
    return -1;
}

int pivotIndex2(vector<int> &nums){
    
    int n = nums.size();
    int sum_left = 0;
    int sum_right = accumulate(nums.begin(), nums.end(), 0);

    for(int i = 0; i < n; ++i){
        sum_right -= nums[i];
        if(sum_left == sum_right){
            return i;
        }
        sum_left += nums[i];
    }

    return -1;
}

int main(){

    vector<int> vec1 = {1, 7, 3, 6, 5, 6};
    vector<int> vec2 = {1, 2, 3};
    vector<int> vec3 = {2, 1, -1};

    cout << pivotIndex1(vec1) << '\n';
    cout << pivotIndex1(vec2) << '\n';
    cout << pivotIndex1(vec3) << '\n';

    cout << pivotIndex2(vec1) << '\n';
    cout << pivotIndex2(vec2) << '\n';
    cout << pivotIndex2(vec3) << '\n';

    return 0;
}