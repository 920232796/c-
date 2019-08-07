#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {

    int a, b, c, d;
    cin>>a>>b>>c>>d;
    P p1 = P(a, b);
    P p2 = P(c, d);
    int res = gcd(abs(p1.first - p2.first), abs(p1.second - p2.second)) - 1;

    cout<<res<<endl;
    return 0;
}