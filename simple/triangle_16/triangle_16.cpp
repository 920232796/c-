#include<iostream>
#include<string>

using namespace std;

int maxTriangleLength(int n) {
    int a[n];
    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            for (int k = j + 1; k < n; k ++) {
                int maxBorder = max(a[i], max(a[j], a[k]));
                int len = a[i] + a[j] + a[k];
                if (maxBorder < len - maxBorder){
                    //璇佹槑鍙互鏋勬垚涓夎褰?
                    ans = max(ans, len);
                }
            }
        }
    }
    cout<<"最大周长为:"<<ans<<endl;
}

int main() {
    int n;
    cout<<"n = ";
    cin>>n;
    maxTriangleLength(n);
    return 0;
}