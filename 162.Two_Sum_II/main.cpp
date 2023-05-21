#include <iostream>
#include <vector>

using namespace std;

// Binary Search approach
// Time complexity  : O(nlogn)
// Space complexity : O(1)

vector<int> twoSum1(vector<int>& nums, int target){

    int n = nums.size();

    for(int i = 0; i < n - 1; ++i){

        int l = i, r = n;

        while(r > l + 1){
            int m = l + (r - l)/2;
            if(nums[l] + nums[m] >= target) r = m;
            else l = m; 
        }

        if(r != n && nums[l] + nums[r] == target) return {l + 1, r + 1}; // 1-indexed array
    }

    return {};
}

// Two Pointers Approach
// Time complexity  : O(n)
// Space complexity : O(1)

vector<int> twoSum2(vector<int>& nums, int target){
    
    int n = nums.size();
    int i = 0, j = n - 1;

    while(j > i){
        if(nums[i] + nums[j] > target) --j;
        else if(nums[i] + nums[j] < target) ++i;
        else return {i + 1, j + 1};
    }

    return {};
}

int main(){

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> nums2 = {4, 6, 23, 190, 300, 2342, 12324};
    int target2 = 490;

    vector<int> ans1 = twoSum2(nums1, target1);
    vector<int> ans2 = twoSum2(nums2, target2);

    cout << nums1[ans1[0] - 1] << " + " << nums1[ans1[1] - 1] << " = " << target1 << '\n';
    cout << nums2[ans2[0] - 1] << " + " << nums2[ans2[1] - 1] << " = " << target2 << '\n'; 

    return 0;

}
