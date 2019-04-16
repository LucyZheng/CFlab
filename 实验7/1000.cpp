#include<iostream>
#include <string>
using namespace std;
string S;
struct {
	int num;
	string vnsign[100];
	string LLresult[100][100];
}VN={ 0 };
struct {
	int num;
	string vtsign[100];
}VT={ 0 };
struct {
	int num;
	int order[100];
	string left[100], right[100];
}pro={ 0 };
struct {
	int num;
	int order[100];
	int pronum[100];
	string row[100], col[100];
	
}LL={0};

int main() {
	cin >> S >> VN.num;
	for (int i = 0; i < VN.num; i++)
		cin >> VN.vnsign[i];
	cin >> VT.num;
	for (int i = 0; i < VT.num; i++)
		cin >> VT.vtsign[i];
	cin >> pro.num;
	for (int i = 0; i < pro.num; i++)
		cin >> pro.order[i]>>pro.left[i]>>pro.right[i];
	cin >> LL.num;
	for (int i = 0; i < LL.num; ++i)
		cin >> LL.order[i] >> LL.row[i] >> LL.col[i] >> LL.pronum[i];
	VT.vtsign[VT.num] = "#";
	VT.num++;
	for (int i = 0; i < LL.num; ++i) {
		int j;
		for (j = 0; j < VN.num&&VN.vnsign[j] != LL.row[i]; ++j);
		int k;
		for (k = 0; k < VT.num && VT.vtsign[k] != LL.col[i]; ++k);
		VN.LLresult[j][k] = pro.right[LL.pronum[i] - 1];	
	}
	cout << "     ";
	for (int i = 0; i<VT.num; i++) 
		cout << "    " << VT.vtsign[i];
	cout << endl;
	for (int i = 0; i < VN.num; i++) {
		for (int k2 = 0; k2 < 5 - VN.vnsign[i].length(); ++k2)
			cout << ' ';
		cout << VN.vnsign[i];
		for (int j = 0; j < VT.num; ++j) {
			for (int k = 0; k < 5 - VN.LLresult[i][j].length(); ++k)
				cout << ' ';
			cout << VN.LLresult[i][j];
		}
		cout << endl;
	}
	system("pause");
}