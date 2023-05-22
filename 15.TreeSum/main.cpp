#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Two pointers
// Time complexity  : O(n^2)
// Space complexity : O(n)
 
vector<vector<int>> threeSum(vector<int> nums){

    int n = nums.size();
    vector<vector<int>> ans;

    if(n < 3) return ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 2; ++i){
        
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1, k = n - 1;

        while(k > j){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum > 0) --k;
            else if(sum < 0) ++j;
            else{
                ans.push_back({nums[i], nums[j], nums[k]});
                while(j < k && nums[j] == nums[j + 1]) ++j;
                while(j < k && nums[k] == nums[k - 1]) --k;
                ++j; --k;
            }
        }

    }

    return ans;
}

int main(){

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);

    cout << "The solutions are : \n";

    int n = nums.size();

    for(int i = 0; i < n; ++i){
        cout << ans[i][0] << " + " << ans[i][1] << " + " << ans[i][2] << " = 0\n";
    }


    return 0;
}
