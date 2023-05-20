#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

// Time complexity  : O(n)
// Space complexity : O(1) 

bool isPalindrome1(string s){

    // Remove all non-alphanumerical characters

    s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){
        return !isalnum(c);
    }), s.end());

    // Converting uppercase letter to lowercase
    
    for(char& c : s){
        if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    }

    int n = s.size();
    int i = 0, j = n - 1;

    while(j > i){
        if(s[i] != s[j]) return false;
        ++i;
        --j;
    }

    return true;
}

// Time complexity  : O(n)
// Space complexity : O(1) 

bool isPalindrome2(string s){

    int n = s.size();
    int i = 0, j = n - 1;

    while (j > i){
        
        while(!isalnum(s[i]) && i < j) ++i;
        while(!isalnum(s[j]) && i < j) --j;

        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
        if(s[j] >= 'A' && s[j] <= 'Z') s[j] = s[j] - 'A' + 'a';

        if(s[i] != s[j]) return false;
        ++i;
        --j;
    }
    
    return true;
}

int main(){

    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";
    
    cout << boolalpha;
    cout << isPalindrome2(s1) << " " << isPalindrome2(s2) << " " << isPalindrome2(s3) << '\n'; 

    return 0;
}
