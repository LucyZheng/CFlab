#include <iostream>
#include <string>
using namespace std;
struct { int Nv; string VN[10]; } Vns = { 0};
struct { int Nt; string VT[10]; } Vts = { 0};
struct { int Np; string PL[20], PR[20]; } ps = { 0 };
string S;
int judge(string left, string right, string result[], int len) {
	for (int j = 0; j < len; ++j) {
		if (left[0] == result[j][0]) return j;
	}
	return -1;
}
int main(){
	cin >> S>>Vns.Nv;
	for (int i = 0; i < Vns.Nv; ++i)
		cin >> Vns.VN[i];
	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i)
		cin >> Vts.VT[i];

	cin >> ps.Np;
	string result[20];
	int len=0;
	for (int i = 0; i < ps.Np; ++i) {
		cin >> ps.PL[i] >> ps.PR[i];
		if (ps.PL[i] == ps.PR[i]) {
			cout << "delete self production:" << ps.PL[i] << "::=" << ps.PR[i]<<endl;
			continue;
		}
		int index = judge(ps.PL[i], ps.PR[i], result, len);
		if (index!=-1) {
			result[index] += " | ";
			result[index] += ps.PR[i];
		}
		else {
			result[len] = ps.PL[i] + "::=" + ps.PR[i];
			len++;
		}
	}
	cout << "unreached Vn:";
	for (int i = 0; i < len; ++i) {
		int flag1 = 0;
		for (int j = 0; j < len; ++j) {
			if (i == j) continue;
			if (result[i][0] == S[0]) flag1 = 1;
			for (int k = 0; k < result[j].size(); ++k) {
				if (result[i][0] == result[j][k]) flag1 = 1;
			}
			
		}
		if (!flag1) {
			cout << result[i][0]<<endl;
			for (int k2 = 0; k2 < ps.Np; ++k2) {
				if (result[i][0] == ps.PL[k2][0])
					cout << "delete production:" << ps.PL[k2] << "::=" << ps.PR[k2]<<endl;
			}
			cout << "delete VN:" << result[i][0] << endl;

			result[i] = "";
		}
	}
	cout << "G[" << S << "]:" << endl;
	
	for (int j = 0; j < Vns.Nv; ++j) {
		for (int i = 0; i < len; ++i) {
			if (Vns.VN[j][0] == result[i][0]){
				cout << result[i] << endl;
			}
				
		}
	}
	system("pause");
}
 