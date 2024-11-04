#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    bool answer = true;
    
    for(char ch : s) {
        if(ch == '(')
            st.push(ch);
        else if(st.empty()) {
            answer = false;
            break;
        }
        else 
            st.pop();
    }    
    
    if(!st.empty()) 
        answer = false;
        
    return answer;
}