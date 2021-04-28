#include<bits/stdc++.h>

using namespace std;


void Manachars_algorithm(string s) {
        
    int n1 = s.size();
    string str = "#";
       
    for(int i = 0; i < n1; i++){
    	str += s[i];
    	str += '#';
    }   	
      
    int l = 0, r = -1;
    int n = str.size();
    int arr[n];        
    for(int i = 0; i < n; i++){
            
    	int k;
    	if( i > r ) k = 0;
    	else k = min(arr[l+r-i], r-i);
            
    	while( i-k >=0 && i+k < n && str[i-k] == str[i+k]) k++;
        if(str[i-k] != str[i+k]) k--;
        arr[i] = k;
        if(i+k > r ){
            l = i-k;
            r = i+k;
        }
    }	
        
    int d = -1;
    for(int i = 0; i < n; i++ ){
       	if(d < arr[i]){
       		d = arr[i];	
           l = i-d;
           r = i+d;
        }
    }
  
    str = str.substr(l, r-l+1);
    string res = "";
    for(int i = 0; i < str.size(); i++ ){
        if(str[i] != '#') res += str[i];
    }
	
	cout << res;      
}



int main(){
		
	string s; cin >> s;
	Manachars_algorithm(s);
	return 0;
}
