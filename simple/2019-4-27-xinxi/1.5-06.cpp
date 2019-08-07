#include<bits/stdc++.h>

using namespace std;


int solve(vector<int> nums) {

    int min1 = 1000;
    int max1 = -1000;
    for (int i = 0; i < nums.size(); i ++) {
        min1 = min(nums[i], min1);
        max1 = max(nums[i], max1);
    }
    return max1 - min1;
}

int main() {

    cout<<"hello world;"<<endl;
    vector<int> nums;
    for (int i = 0; i < 6; i ++) {
        int aa;
        cin>>aa;
        nums.push_back(aa);
    }
    cout<<solve(nums)<<endl;
    
}