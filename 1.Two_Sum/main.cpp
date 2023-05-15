#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> um;
    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i < n; ++i){
        int complement = target - nums[i];
        if(um.find(complement) != um.end()){
            ans.push_back(um[complement]);
            ans.push_back(i);
        }else{
            um.insert({nums[i], i});
        }
    }

    return ans;
}

int main(){

    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> ans = twoSum(nums, target);

    for(int i = 0; i < 2; ++i){
        cout << ans[i] << " ";
    }

    return 0;
}
