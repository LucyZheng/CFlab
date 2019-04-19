#include <iostream>
#include <string>
using namespace std;
struct { int Nv; string VN[10]; } Vns = { 0 };
struct { int Nt; string VT[10]; } Vts = { 0 };
struct { int Np; string PL[20], PR[20]; } ps = { 0 };
string S;
struct first {
	int index;
	string list;
	int oldlength;

};
bool judgevt(char pr) {
	if (pr == 'k') return true;
	for (int j = 0; j < Vts.Nt; j++)
		if (pr == Vts.VT[j][0]) return true;

	return false;
}

int judgeindex(char pl){
	for (int j = 0; j < Vns.Nv; j++)
		if (pl == Vns.VN[j][0]) return j;
}

string clear(string old) {
	string newstring = "";
	int flag;
	for (int i = 0; i < old.size(); i++) {
		flag = 0;
		for (int j = i + 1; j < old.size(); j++) {
			if (old[i] == old[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) newstring += old[i];
	}
	return newstring;
}

int main() {
	first result[10];
	cin >> S >> Vns.Nv;
	for (int i = 0; i < Vns.Nv; ++i) {
		result[i].index = i;
		result[i].list = "";
		result[i].oldlength = 0;
		cin >> Vns.VN[i];

	}
		
	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i)
		cin >> Vts.VT[i];
	cin >> ps.Np;
	int tmp;
	for (int i = 0; i < ps.Np; ++i) 
		cin >>tmp>>ps.PL[i] >> ps.PR[i];
	while (true) {
		for (int i = 0; i < ps.Np; i++) {
			int index = judgeindex(ps.PL[i][0]);
			if (judgevt(ps.PR[i][0])) {
				result[index].list += ps.PR[i][0];
				result[index].list = clear(result[index].list);
			}
			else {
				int newindex = judgeindex(ps.PR[i][0]);
				result[index].list += result[newindex].list;
				result[index].list = clear(result[index].list);
			}

		}
		int flag = 0;
		for (int k = 0; k < Vns.Nv; k++) {
			if (result[k].list.size() != result[k].oldlength) {
				result[k].oldlength = result[k].list.size();
				flag = 1;
			}
		}
		if (!flag) break;
	}
	cout << "FIRST(VT)" << endl;
	for (int i = 0; i < Vns.Nv; ++i) {
		cout << Vns.VN[i] << ' ';
		for (int j = 0; j < result[i].list.size(); ++j)
			cout << result[i].list[j] << ' ';
		if (i!=5) cout << endl;
	}
	system("pause");
}
