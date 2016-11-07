//后缀表达式的计算
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;

double toDouble(char ch) {
	double temp;
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		temp = (double)(ch);
	if (ch >= 'a' && ch <= 'z') 
		temp = (double)(ch) - 96;
	if (ch >= 'A' && ch <= 'Z')
		temp = (double)(ch) - 64;
	return temp;
}

int main() {
	int n;
	string str;
	cin >> n;
	while (n--) {
		double one, another, result = 0;
		stack<double> operand;
		cin >> str;
		vector<double> num;
		double temp;
		for (int i = 0; i < str.size(); ++i) {
			temp = toDouble(str[i]);
			num.push_back(temp);
		}
		for (int i = 0; i < str.size(); ++i) {
			if (num[i] == 43) {
				one = operand.top();
				operand.pop();
				another = operand.top();
				operand.pop();
				result = another + one;
				operand.push(result);
			} else if (str[i] == 45) {
				one = operand.top();
				operand.pop();
				another = operand.top();
				operand.pop();
				result = another - one;
				operand.push(result);
			} else if (str[i] == 42) {
				one = operand.top();
				operand.pop();
				another = operand.top();
				operand.pop();
				result = another * one;
				operand.push(result);
			} else if (str[i] == 47) {
				one = operand.top();
				operand.pop();
				another = operand.top();
				operand.pop();
				result = another / one;
				operand.push(result);
			} else {
				operand.push(num[i]);
			}
		}
		cout << setprecision(2) << fixed << result << endl;
	}
	return 0;
}