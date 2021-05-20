#include<bits/stdc++.h>

using namespace std;

string postfixtoprefix(string exp){

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

            s.push(exp[i]+a+b);
        }
    }

    return s.top();

}


int main(){

    string exp =  "ABC/-AK/L-*";
    string res = postfixtoprefix(exp);
    cout << "Postfix Expression: " << exp << "\n";
    cout << "Prefix Expression: " << res;

    return 0;
}
