#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	bool flag = true;
	while (n--) {
		flag = true;
		cin >> str;
		stack<char> mystack;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
				mystack.push(str[i]);
			}
			if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
				if (mystack.empty()) {
					flag = false;
					break;
				}
				if ((mystack.top() == '(' && str[i] != ')') || (mystack.top() != '(' && str[i] == ')')) {
					flag = false;
					break;
				}
				if ((mystack.top() == '[' && str[i] != ']') || (mystack.top() != '[' && str[i] == ']')) {
					flag = false;
					break;
				}
				if ((mystack.top() == '{' && str[i] != '}') || (mystack.top() != '{' && str[i] == '}')) {
					flag = false;
					break;
				}
				mystack.pop();
			}
		}
		if (!mystack.empty()) flag = false;
		if (flag == false) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}