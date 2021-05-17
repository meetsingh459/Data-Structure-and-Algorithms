#include<bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    vector<int> res;   
    deque<int> q;
        
    int n = nums.size();
        
    for(int i = 0; i < k; i++){
        while( !q.empty() && nums[i] >= nums[q.back()] ) q.pop_back();
        q.push_back(i);
    }
        
    for(int i = k; i < n; i++){
            
        res.push_back(nums[q.front()]);
            
        while( !q.empty() && q.front() <= i-k ) q.pop_front();
        while( !q.empty() && nums[i] >= nums[q.back()] ) q.pop_back();     
            
        q.push_back(i);
    }
        
    res.push_back(nums[q.front()]);
    return res;
        
}


int main(){

    int n, k; cin >> n >> k;
    vector<int> nums(n);

    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<int> res = maxSlidingWindow(nums, k);
        
    cout << "Maximum of all subarrays of size k is: ";
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";

    return 0;
}
