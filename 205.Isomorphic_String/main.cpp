#include <iostream>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t){
    
    unordered_map<int, int> map_s_t, map_t_s;
    int n = s.length(); // s and t equal length

    for(int i = 0; i < n; ++i){
        if(map_s_t[s[i]] == 0 && map_t_s[t[i]] == 0){
            map_s_t[s[i]] = t[i];
            map_t_s[t[i]] = s[i];
        }else if(map_s_t[s[i]] != t[i] || map_t_s[t[i]] != s[i]){
            return false;
        }
    }

    return true;
}

int main(){
    
    string s1 = "egg", t1 = "add";
    string s2 = "foo", t2 = "bar";
    string s3 = "paper", t3 = "title"; 

    cout << boolalpha << isIsomorphic(s1, t1) << '\n';
    cout << isIsomorphic(s2, t2) << '\n';
    cout << isIsomorphic(s3, t3) << '\n';

    return 0;
}