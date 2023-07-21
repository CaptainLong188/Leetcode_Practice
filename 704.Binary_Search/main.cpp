#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target){
    
    int n = nums.size();
    int l = -1, r = n;

    while (r > l + 1){
        
        int m = l + (r - l)/2;

        if(nums[m] >= target){
            r = m;
        }else{
            l = m;
        }
    }
    
    if(r < n && nums[r] == target) return r;
    else return -1;

}

int main(){

    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;

    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;

    cout << search(nums1, target1) << '\n';
    cout << search(nums2, target2) << '\n';

    return 0;
}
