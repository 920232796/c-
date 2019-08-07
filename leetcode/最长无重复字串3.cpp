#include<bits/stdc++.h> 


using namespace std;

int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        map<string, int> m;
        int len = 0;

        for (int i = 0; i < s.size(); i ++) {
            if (m.count(s.substr(i, 1)) == 0) {
                len += 1;
                m[s.substr(i, 1)] = i;
            } else {
                len = 0;
                i = m[s.substr(i, 1)];
                m.clear();
            }
            if (maxLength < len) {
                    maxLength = len;
                }
        }
        return maxLength;
    }

int main() {

    string s;
    s = " ";
    cout<<lengthOfLongestSubstring(s);
    return 0;
}