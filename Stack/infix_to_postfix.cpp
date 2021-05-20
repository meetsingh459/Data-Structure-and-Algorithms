#include<bits/stdc++.h>

using namespace std;


int priority(char a){

    if(a == '^') return 3;
    else if(a == '*' || a == '/') return 2;
    else if(a == '+' || a == '-') return 1;
    return -1;
}


string infixtopostfix(string exp){

    string res = "";
    stack<char> s;

    for(int i = 0; i < exp.size(); i++){

        if((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') )
            res += exp[i];

        else if( exp[i] == '(' ) s.push(exp[i]);
        else if( exp[i] == ')' ){
            while(!s.empty() && s.top() != '('){
                res += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            int pre = priority(exp[i]);
            while(!s.empty() && pre <= priority(s.top()) ){
                res += s.top();
                s.pop();
            }

            s.push(exp[i]);

        }
    }

    while(!s.empty()){
        res += s.top();
        s.pop();
    }

    return res;

}


int main(){

    string exp1 =  "(A+B/C*(D+E)-F)";
    string res1 = infixtopostfix(exp1);
    cout << "Infix Expression: " << exp1 << "\n";
    cout << "Postfix Expression: " << res1;

    cout << "\n\n";

    string exp2 =  "a+b*(c^d-e)^(f+g*h)-i";
    string res2 = infixtopostfix(exp2);
    cout << "Infix Expression: " << exp2 << "\n";
    cout << "Postfix Expression: " << res2;

    return 0;
}
