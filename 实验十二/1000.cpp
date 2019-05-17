#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
struct { int Nv; string VN[10]; } Vns = { 0 };
struct { int Nt; string VT[10]; } Vts = { 0 };
struct { int Np; string PL[20], PR[20]; } ps = { 0 };
string action[100][100];
int gotom[100][100];
string S,input;
vector <char>  str;
vector <int> num;
int findindexaction(char a) {
	for (int i = 0; i < Vts.Nt; ++i)
		if (a == Vts.VT[i][0]) return i;
	return -1;
}
int findindexgoto(char a) {
	for (int i = 0; i < Vns.Nv; ++i)
		if (a == Vns.VN[i][0]) return i;
	return -1;
}
int main() {
	cin >> S;
	cin >> Vns.Nv;
	for (int i = 0; i < Vns.Nv; ++i)
		cin >> Vns.VN[i];
	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i)
		cin >> Vts.VT[i];
	cin >> ps.Np;
	int tmp;
	for (int i = 0; i < ps.Np; ++i)
		cin >> tmp >> ps.PL[i] >> ps.PR[i];
	int n, na, ng;
	cin >> n >> na >> ng;
	string tmp1, tmp2;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < na; ++j) {
			
			cin >> tmp1 >> tmp2;
			action[i][j] = tmp1 + tmp2;
		}
		for (int k = 0; k < ng; k++)
			cin >> gotom[i][k];
	}
	cin >> input;
	str.push_back('#');
	num.push_back(0);
	int flag = 0;
	while (true) {
		for (int i = 0; i < str.size(); ++i) {
			cout << str[i] << num[i];
		}
		cout << " & ";
		for (int i = 0; i < input.size(); ++i)
			cout << input[i];
		cout << endl;
		int index = findindexaction(input[0]);
		string ele = action[num.back()][index];
		if (ele == "A0") break;
		if (ele[0] == 's') {
			str.push_back(input[0]);
			input = input.substr(1);
			if (ele.size()==2)
				num.push_back(ele[1]-'0');
			else {
				num.push_back((ele[1] - '0') * 10 + (ele[2] - '0'));
			}
		}
		else {
			int tmpindex;
			if (ele.size() == 2)
				tmpindex = ele[1] - '0';
			else {
				tmpindex = (ele[1] - '0') * 10 + (ele[2] - '0');
			}
			
			int length = ps.PR[tmpindex].size();
			for (int i = 0; i < length; ++i) {
				num.pop_back();
				str.pop_back();
			}
			str.push_back(ps.PL[tmpindex][0]);
			int tmpgoto = gotom[num.back()][findindexgoto(str.back())];
			num.push_back(tmpgoto);


		}

	}
	system("pause");
}