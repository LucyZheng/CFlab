#include<iostream>
#include <string>
#include<stack>
using namespace std;
string S;
struct {
	int num;
	string vnsign[100];
	string LLresult[100][100];
}VN = { 0 };
struct {
	int num;
	string vtsign[100];
}VT = { 0 };
struct {
	int num;
	int order[100];
	string left[100], right[100];
}pro = { 0 };
struct {
	int num;
	int order[100];
	int pronum[100];
	string row[100], col[100];

}LL = { 0 };

void printresult(string left, stack<string> stackresult) {
	string str = "";
	cout << "#" << left << " & ";
	while (!stackresult.empty()) {
		cout << stackresult.top();
		str += stackresult.top();
		stackresult.pop();
	}
	cout << "#" << endl;
	while (str.length() != 0) {
		string str2 = str.substr(str.length() - 1, 1);
		stackresult.push(str2);
		str = str.substr(0, str.length() - 1);
	}
	return;
}


int main() {
	cin >> S >> VN.num;
	for (int i = 0; i < VN.num; i++)
		cin >> VN.vnsign[i];
	cin >> VT.num;
	for (int i = 0; i < VT.num; i++)
		cin >> VT.vtsign[i];
	cin >> pro.num;
	for (int i = 0; i < pro.num; i++)
		cin >> pro.order[i] >> pro.left[i] >> pro.right[i];
	cin >> LL.num;
	for (int i = 0; i < LL.num; ++i)
		cin >> LL.order[i] >> LL.row[i] >> LL.col[i] >> LL.pronum[i];
	string ts;
	cin >> ts;
	stack<string> stackresult;
	stackresult.push(S);
	string left = "";
	printresult(left, stackresult);

	while(!stackresult.empty()) {
		string strtop = stackresult.top(),fl=ts.substr(0,1);
		if (strtop == fl) {
			left += strtop;
			ts = ts.substr(1, ts.length() - 1);
			stackresult.pop();
			printresult(left, stackresult);
			continue;
		}
		else {
			for (int i = 0; i < LL.num; ++i) {
				if (LL.row[i] == strtop && LL.col[i] == fl) {
					stackresult.pop();
					string str = pro.right[LL.pronum[i] - 1];
					if (str == "k") continue;
					while (str.length() != 0) {
						string str2 = str.substr(str.length() - 1, 1);
						stackresult.push(str2);
						str = str.substr(0, str.length() - 1);
					}
				}
			}
			printresult(left, stackresult);
		}
		


	}



	system("pause");
}