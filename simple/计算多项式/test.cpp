#include<bits/stdc++.h>

using namespace std;

int main() {

    string str1 = "3.13";
    // double a = stof(to_string((str1[0])));
    // cout<<a<<endl;
    char c = '3';
    string str;
    stringstream stream;
    stream << c;
    str = stream.str();
    cout<<str<<endl;


    cout<<to_string('3')<<endl;

    cout<<stof(str1.substr(0, 1))<<endl;

    stringstream aa;

    aa << 3.131;

    cout<<aa.str()<<endl;

    cout<<stof(str1.substr(0, 1));

    return 0;
}