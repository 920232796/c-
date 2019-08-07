#include<bits/stdc++.h> 

using namespace std;

vector<double> calcu;
string multiFormula = "4*50+2 ";
int flag = -1;

void cal() {
    // -1 ＋ -2 减
    //先取出栈中元素，判断加减乘除，计算
    double tar = 1.0;
    while (calcu.size() > 2) {
        double right = calcu[calcu.size() - 1];//取出最后一个
        calcu.pop_back();//弹出最后一个
        double middle = calcu[calcu.size() - 1];//取出中间符号
        calcu.pop_back();
        double left = calcu[calcu.size() - 1];//取出左侧数字
        calcu.pop_back();

        if (middle == -1000) {
        // +
        tar = right + left;
        } else if (middle == -2000) {
            tar = left - right;
        } else if (middle == -3000) {
            tar = right * left;
        } else if (middle == -4000) {
            tar = left / right;
        }

        calcu.push_back(tar);

    }
    
}

//计算多项式
int main() {

    for (int i = 0; i < multiFormula.length(); i ++) {
        if (multiFormula[i] == '+' || multiFormula[i] == '-' || multiFormula[i] == ' ') {
            //如果是加减的话，先把左侧数字push进去，然后进行计算，计算完成之后再把加或者减号push进去 一定注意顺序
            calcu.push_back(stof(multiFormula.substr(flag + 1, i - flag)));
            cal();
            
            if (multiFormula[i] == '+') {
                calcu.push_back(-1000);
            } else if (multiFormula[i] == '-') {
                calcu.push_back(-2000);
            }

            flag = i;

        } else if (multiFormula[i] == '*' || multiFormula[i] == '/') {
            if (multiFormula[i] == '*') {
                //乘法 先把左侧数字push进去 再把乘法push进去 现在不需要进行计算
                calcu.push_back(stof(multiFormula.substr(flag + 1, i - flag)));
                calcu.push_back(-3000);
            } else {
                calcu.push_back(stof(multiFormula.substr(flag + 1, i - flag)));
                calcu.push_back(-4000);
            }
            //更新flag 为了获取间隔中的数字
            flag = i;
        }
    }
    cout<<calcu[0]<<endl;
    return 0;
}