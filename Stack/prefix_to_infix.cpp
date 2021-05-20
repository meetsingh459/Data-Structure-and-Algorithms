#include<bits/stdc++.h>

using namespace std;

string prefixtoinfix(string exp){

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

            if( a.size() > 1 ) a = '('+a+')';
            if( b.size() > 1 ) b = '('+b+')';
            s.push(b+exp[i]+a);
        }
    }

    return s.top();

}


int main(){

    string exp =  "*-A/BC-/AKL";
    string res = prefixtoinfix(exp);
    cout << "Prefix Expression: " << exp << "\n";
    cout << "Infix Expression: " << res;

    return 0;
}
