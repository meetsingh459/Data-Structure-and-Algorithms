#include<bits/stdc++.h>

using namespace std;


int priority(char a){

    if(a == '^') return 3;
    else if(a == '*' || a == '/') return 2;
    else if(a == '+' || a == '-') return 1;
    return -1;
}


string infixtoprefix(string exp){

    int i  = 0, j = exp.size()-1;

    while( i < j ){
        char temp = exp[j];
        (exp[i] == '(')? exp[j] = ')' : exp[j] = exp[i];
        ( temp == ')')? exp[i] = '(' : exp[i] = temp;
        i++; j--;
    }


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
            if(exp[i] == '^'){
                while(!s.empty() && pre <= priority(s.top()) ){
                    res += s.top();
                    s.pop();
                }
            }
            else{
                while(!s.empty() && pre < priority(s.top()) ){
                    res += s.top();
                    s.pop();
                }
            }

            s.push(exp[i]);

        }
    }

    while(!s.empty()){
        res += s.top();
        s.pop();
    }

    reverse(res.begin(), res.end());

    return res;

}


int main(){

    string exp =  "(x+y*z/w+u)";
    string res = infixtoprefix(exp);
    cout << "Infix Expression: " << exp << "\n";
    cout << "Prefix Expression: " << res;

    return 0;
}
