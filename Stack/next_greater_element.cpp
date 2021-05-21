#include<bits/stdc++.h>

using namespace std;

vector<int> next_greater(int arr[], int n){

    stack<int> s;
    vector<int> res(n);
    for(int i = n-1; i >= 0; i--){

        if(s.empty()){
            s.push(arr[i]);
            res[i] = -1;
        }
        else{
            while(!s.empty() && s.top()  <= arr[i] ) s.pop();
            
            if(s.empty()) res[i] = -1;
            else res[i] = s.top();

            s.push(arr[i]);
        }
    }

    return res;

}

int main(){
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> res = next_greater(arr, n);  
    
    cout << "The Next Greater Element is: " << endl;
    for(int i = 0; i < res.size(); i++) cout << arr[i] << " --> " << res[i] << endl;
}
