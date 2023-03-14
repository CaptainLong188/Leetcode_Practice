#include <iostream>

using namespace std;

bool isSubsequence(string s, string t){

    size_t i = 0, j = 0;

    while(i < s.length() && j < t.length()){
        
        if(t[j] == s[i]){
            ++i;
        }

        ++j;
    }

    return (i == s.length());
}

int main(){

    string s1 = "abc", t1 = "ahbgdc";
    string s2 = "axc", t2 = "ahbgdc";

    cout << boolalpha << isSubsequence(s1, t1) << '\n';
    cout << isSubsequence(s2, t2) << '\n';

    return 0;
}