#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void printVector(const vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n; ++i){
        cout << v[i] << (i != n - 1 ? " " : "\n");
    }
}


// Prefix - Sum 1

vector<int> runningSum1(vector<int>& nums){
    
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = nums[0];

    for(int i = 1; i < n; ++i){
        ans[i] = ans[i - 1] + nums[i];
    }

    return ans;
}

// Prefix - Sum 2 (in-place)

vector<int> runningSum2(vector<int>& nums){
    int n = nums.size();
    for(int i = 1; i < n; ++i){
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main(){

    vector<int> nums = {3, 1, 2, 10, 1};

    vector<int> ans1 = runningSum1(nums);
    vector<int> ans2 = runningSum2(nums);

    printVector(ans1);
    printVector(ans2);

    return 0;
}