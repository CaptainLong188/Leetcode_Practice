#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Time complexity  : O(nlogn)
// Space complexity : O(1)

int longestConsecutive1(vector<int>& nums){
    
    int n = nums.size();
    int ans = 0;
    int cnt = 1;

    if (n == 0) return 0;

    sort(nums.begin(), nums.end());

    for(int i = 1; i < n; ++i){
        if(nums[i] == nums[i - 1] + 1) cnt++;
        else if(nums[i] == nums[i - 1]) continue;
        else{
            ans = max(ans, cnt);
            cnt = 1;
        }
    }

    return max(ans, cnt);
}

// Store in hash set, only check if it's the beggining
// Time complexity  : O(n)
// Space complexity : O(n)

int longestConsecutive2(vector<int>& nums){

    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;

    for(auto const& e : s){
        if(!s.count(e - 1)){ // e - 1 is not in the set
            int length = 1;
            while(s.count(e + length)) ++length;
            longest = max(longest, length);
        } 
    }

    return longest;
}

    

int main(){

    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    vector<int> nums2 = {0, 1, 1, 2};

    cout << longestConsecutive2(nums1) << '\n';
    cout << longestConsecutive2(nums2) << '\n';

    return 0;
}
