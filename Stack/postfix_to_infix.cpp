#include<bits/stdc++.h>

using namespace std;

string postfixtoinfix(string exp){

    int i  = 0, j = exp.size()-1;

    string res = "";
    stack<string> s;

    for(int i = 0; i < exp.size(); i++){

        if((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') ){
            string temp = "";
            temp += exp[i];
            s.push(temp);
        }
        else{
            
            string b = s.top();
            s.pop();
            string a = s.top();
            s.pop();

            if( a.size() > 1 ) a = '('+a+')';
            if( b.size() > 1 ) b = '('+b+')';
            s.push(a+exp[i]+b);
        }
    }

    return s.top();

}


int main(){

    string exp =  "ab*c+";
    string res = postfixtoinfix(exp);
    cout << "Postfix Expression: " << exp << "\n";
    cout << "Infix Expression: " << res;

    return 0;
}
