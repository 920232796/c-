#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char cleft = tolower(s[left]);
            char cright = tolower(s[right]);

            if (!( 'a' <= cleft &&  cleft <= 'z' || '0' <= cleft && cleft <= '9')) {
                left ++;
                continue;
            }

            if (!( 'a' <= cright && cright <= 'z' || '0' <= cright && cright <= '9')) {
                right --;
                
                continue;
            }

            if (('a' <= cleft && cleft <= 'z' || '0' <= cleft && cleft <= '9') && ('a' <= cright && cright <= 'z' || '0' <= cright && cright <= '9')) {
                if (cleft == cright) {
                    left ++;
                    right --;
                   
                    continue;
                } else {
                    cout<<left<<","<<right<<endl;
                    return false;
                }
            }
            
        }
         cout<<left<<","<<right<<endl;
        return true;
    }
};


int main() {

    cout<<"hello world"<<endl;

    Solution solution = Solution();
    string s = "race a car";
    bool res = solution.isPalindrome(s);
    cout<<res<<endl;

    return 0;
}