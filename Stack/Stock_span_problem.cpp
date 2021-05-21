#include<bits/stdc++.h>

using namespace std;

vector<int> stock_span(int arr[], int n){

    stack<int> s;
    vector<int> res;
    for(int i = 0; i < n; i++){

        if(s.empty()){
            s.push(i);
            res.push_back(i+1);
        }
        else{
            while(!s.empty() && arr[s.top()] <= arr[i]) s.pop();
            
            if(s.empty()) res.push_back(i+1);
            else res.push_back(i-s.top());

            s.push(i);
        }
    }

    return res;

}

int main(){
    int arr[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    vector<int> res = stock_span(arr, n);  
    
    cout << "Stock Span is: ";
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
}
