#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Heap approach
// Time complexity  : O(n * log(k))
// Space complexity : O(n + k)

vector<int> topKFrequent1(vector<int> &nums, int k){

    unordered_map<int, int> um; // Hash map element -> its frequency
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        um[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto const& [key, val] : um){
        pq.push({val, key});
        if((int)pq.size() > k) pq.pop(); // Eliminate least frequent element
    }

    while(!pq.empty()){
        cout << pq.top().first << " -> " << pq.top().second << '\n';
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

// Bucket Sort
// Time complexity  : O(n)
// Space complexity : O(n)

vector<int> topKFrequent2(vector<int> &nums, int k){
    
    unordered_map<int, int> um;
    int n = nums.size();
    vector<vector<int>> bucket(n + 1);
    for(int i = 0; i < n; ++i){
        um[nums[i]]++;
    }

    for(const auto& [key, val] : um){
        bucket[val].push_back(key);
    }

    vector<int> ans;
    for(int i = n; i > 0; i--){
        int l = ans.size();
        if(l == k) break;
        if(!bucket[i].empty()){
            ans.reserve(ans.size() + bucket[i].size());
            for(const auto& e : bucket[i]){
                ans.push_back(e);
            }
        }
    }

    return ans;
}

int main(){

    vector<int> nums = {1, 1, 1, 1, 5, 5, 5, 5, 5, 3, 3, 3, 4, 4, 2};
    int k = 3; 
    vector<int> ans = topKFrequent2(nums, k);

    for(const auto &e : ans){
        cout << e << " ";
    }

    return 0;
}
