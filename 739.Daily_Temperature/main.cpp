#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures){

    int n = temperatures.size();
    stack<int> stk;
    vector<int> ans(n);

    for(int i = 0; i < n; ++i){

        while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
            int j = stk.top();
            stk.pop();
            ans[j] = i - j;
        }
        stk.push(i);
    }

    return ans;
}

int main(){

    vector<int> temperatures = {73,74,75,71,69,72,76,73}; 
    vector<int> ans = dailyTemperatures(temperatures);

    int n = ans.size();
    
    cout << "[ ";
    for(int i = 0; i < n; ++i){
        cout << ans[i] << ((i == n - 1) ? " " : ", ");  
    }
    cout << "]" << '\n';

    return 0;
}
