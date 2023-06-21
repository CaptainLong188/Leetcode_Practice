#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack1 {
public:
    
    int arr[100000];
    int topElement, capacity;

    /*Initializes the stack object*/
    MinStack1(){
        topElement = -1;
        capacity = 100000;
    }
    
    /*pushes the element val onto the stack*/
    void push(int val){

        if(topElement == -1){

            ++topElement;
            arr[topElement] = val;
            ++topElement;
            arr[topElement] = val;

        }else{

            int currMin = min(val, arr[topElement]);
            ++topElement;
            arr[topElement] = val;
            ++topElement;
            arr[topElement] = currMin;
        }

    }

    /*removes the element on the top of the stack*/
    void pop(){
        topElement -= 2;
    }

    /*gets the element on the top of the stack*/
    int top(){
        return arr[topElement - 1];
    }

    /*retrieves the minimum element in the stack*/
    int getMin(){
        return arr[topElement];
    }
};

class MinStack2 {
public:
    
    stack<int> stk;
    stack<pair<int, int>> stkMin;

    /*Initializes the stack object*/
    MinStack2(){

    }
    
    /*pushes the element val onto the stack*/
    void push(int val){

        stk.push(val);

        if(stkMin.empty() || val < stkMin.top().first){
            stkMin.push({val ,1});
        }else if(val == stkMin.top().first){
            ++stkMin.top().second;
        }

    }

    /*removes the element on the top of the stack*/
    void pop(){
        if(stk.top() == stkMin.top().first){
            --stkMin.top().second;
            if(stkMin.top().second == 0){
                stkMin.pop();
            }
        }
        stk.pop();
    }

    /*gets the element on the top of the stack*/
    int top(){
        return stk.top();
    }

    /*retrieves the minimum element in the stack*/
    int getMin(){
        return stkMin.top().first;
    }
};


int main(){

    MinStack1 minStack1;
    minStack1.push(-2);
    minStack1.push(0);
    minStack1.push(-3);
    cout << minStack1.getMin() << '\n';
    minStack1.pop();
    cout << minStack1.top() << '\n';
    cout << minStack1.getMin() << '\n';

    MinStack2 minStack2;
    minStack2.push(-2);
    minStack2.push(0);
    minStack2.push(-3);
    cout << minStack2.getMin() << '\n';
    minStack2.pop();
    cout << minStack2.top() << '\n';
    cout << minStack2.getMin() << '\n';

}
