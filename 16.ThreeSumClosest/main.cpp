#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target){
    
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < n - 2; ++i){

        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1, k = n - 1;

        while(k > j){
            
            int sum = nums[i] + nums[j] + nums[k];

            if(abs(sum - target) < abs(closest - target)) closest = sum;

            if(sum > target) --k;
            else if (sum < target) ++j;
            else return target;

        }
    }

    return closest;
}


int main(){

    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = -1;
    vector<int> nums2 = {-200, -100, -2, 3};
    int target2 = -100; 

    cout << "The sum that is closes to the valor " << target1 << " is : " << threeSumClosest(nums1, target1) << '\n';
    cout << "The sum that is closes to the valor " << target2 << " is : " << threeSumClosest(nums2, target2) << '\n';

    return 0;
}
