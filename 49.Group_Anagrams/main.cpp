#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
    Given an array of strings strs, group the anagrams together. You can
    return the answer in any order.
    An anagram is a word or phrase formed by rearranging the letters of a
    different word or phrase, typically using all the original letters 
    exactly once.

    Time: O(n x l x 26) -> n = length of strs, l = max length of a string in strs
    Time(sort) : O(n x l x log(l))
    Space: O(n x l)
*/

string getKey(string str){
    
    string key = "";
    vector<int> cnt(26);
    int n = str.size();
    
    for(int i = 0; i < n; ++i){
        ++cnt[str[i] - 'a'];
    }

    for(int i = 0; i < 26; ++i){
        key.append(to_string(cnt[i]) + '/');
    }

    return key;
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> um;
    vector<vector<string>> ans;
    int n = strs.size();

    for(int i = 0; i < n; ++i){
        string key = getKey(strs[i]);
        // string key = strs[i];
        // sort(key.begin(), key.end());
        um[key].push_back(strs[i]);
    }

    for(auto const& [key, val] : um){
        ans.push_back(val);
    }

    return ans;
}

int main(){

    vector<string> strs = {"bdddddddddd", "bbbbbbbbbbc", "bcbbbbbbbbb", "ddbdddddddd"};
    vector<vector<string>> ans = groupAnagrams(strs);

    for(size_t i = 0; i < ans.size(); ++i){
        cout << "Anagrams : ";
        for(size_t j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
