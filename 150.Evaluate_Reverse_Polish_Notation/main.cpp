#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <functional>
#include <assert.h>

using namespace std;

int evalRPN1(vector<string>& tokens){

    stack<int> stk;

    for(const auto& token : tokens){

        if(token != "+" && token != "-" && token != "*" && token != "/"){
            stk.push(stoi(token));
        }else{
            int op1 = stk.top();
            stk.pop();
            int op2 = stk.top();
            stk.pop();
            int res = 0;

            if(token == "+"){
                res = op2 + op1;
            }   
            else if(token == "-"){
                res = op2 - op1;
            }
            else if(token  == "*"){
                res = op2 * op1;
            } 
            else{
                res = op2 / op1;
            }

            stk.push(res);
        }      
    }
    return stk.top();
}

// Fancy Solution

int evalRPN2(vector<string>& tokens){
    stack<int> stk;
    unordered_map<string, function<int (int, int)>> map{
        {"+" , plus<int>()}, // [](int a , int b){return a + b;}
        {"-" , minus<int>()},
        {"*" , multiplies<int>()},
        {"/", divides<int>()}
    };

    for(const auto& token : tokens){

        if(map.find(token) != map.end()){
            assert(stk.size() >= 2);
            int op1 = stk.top();
            stk.pop();
            int op2 = stk.top();
            stk.pop();
            stk.push(map[token](op2, op1));

        }else{
            stk.push(stoi(token));
        }
    }

    assert(stk.size() == 1);
    return stk.top();
}


int main(){
    
    vector<string> tokens1 = {"4","13","5","/","+"};
    vector<string> tokens2 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    vector<string> tokens3 = {"4","-2","/","2","-3","-","-"};

    cout << "Res 1 : " << evalRPN1(tokens1) << '\n';
    cout << "Res 2 : " << evalRPN1(tokens2) << '\n';
    cout << "Res 3 : " << evalRPN1(tokens3) << '\n';

    cout << "Res 1 : " << evalRPN2(tokens1) << '\n';
    cout << "Res 2 : " << evalRPN2(tokens2) << '\n';
    cout << "Res 3 : " << evalRPN2(tokens3) << '\n';    

}
