#include<bits/stdc++.h>

using namespace std;

string prefixtopostfix(string exp){

    string res = "";
    stack<string> s;

    for(int i = exp.size()-1; i >= 0; i--){

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

            s.push(b+a+exp[i]);
        }
    }

    return s.top();

}


int main(){

    string exp =  "*+AB-CD";
    string res = prefixtopostfix(exp);
    cout << "Prefix Expression: " << exp << "\n";
    cout << "Postfix Expression: " << res;

    return 0;
}
