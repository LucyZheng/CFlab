#include<iostream>
#include<string>
using namespace std;
struct { int Nv; string VN[10]; } Vns = { 0 };
struct { int Nt; string VT[10]; } Vts = { 0 };
struct { int Np; string PL[20], PR[20]; bool enabled[20]; } ps = { 0 };
string S;
int equalm[100][100];

int findindex(char a, string col) {
	for (int i = 0; i < col.size(); i++)
		if (a == col[i]) return i;
}
void plu(int m[][100], int m2[][100], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = m2[i][j];
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (m[i][j] == 1) {
				for (int k = 0; k < n; k++)
					m[i][k] = m[i][k] | m[j][k];
			}
		}
	}
}

int main() {
	string col = "";
	cin >> S >> Vns.Nv;
	for (int i = 0; i < Vns.Nv; ++i) {
		cin >> Vns.VN[i];
		col += Vns.VN[i];
	}

	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i) {
		cin >> Vts.VT[i];
		col += Vts.VT[i];
	}
	int n = col.size();

	cin >> ps.Np;
	int tmp;
	for (int i = 0; i < ps.Np; i++)
		cin >> tmp >> ps.PL[i] >> ps.PR[i];
	int mn;
	cin >> mn;
	for (int i = 0; i < mn; i++) {
		for (int j = 0; j < mn; j++)
			cin >> equalm[i][j];
	}
	string res,output;
	cin >> res;
	int len;
	output = "#";
	cout << output << " & " << res<<endl;
	output += res[0];
	len = res.length();
	res = res.substr(1, len - 1);
	cout << output << " & " << res << endl;
	int tmp1, tmp2;
	while (true) {
		if (res[0] != '#') {
			tmp1 = findindex(output.back(), col);
			tmp2 = findindex(res[0], col);
			if (equalm[tmp1][tmp2] != 3) {
				output += res[0];
				len = res.length();
				res = res.substr(1, len - 1);
				cout << output << " & " << res << endl;
			}
			else {
				string tmp = "";
				tmp += output.back();
				int len2 = output.size();

				for (int i = len2 - 1; i > 0; i--) {
					if (output[i - 1] == '#') {
						output = output.substr(0, len2 - tmp.size());
						for (int j = 0; j < ps.Np; j++) {
							if (tmp == ps.PR[j]) {
								output += ps.PL[j];
								break;
							}
						}
						break;
					}

					tmp1 = findindex(output[i], col);
					tmp2 = findindex(output[i - 1], col);
					if (equalm[tmp2][tmp1] != 1) {
						tmp = output[i - 1] + tmp;
					}
					else {
						output = output.substr(0, len2 - tmp.size());
						for (int j = 0; j < ps.Np; j++) {
							if (tmp == ps.PR[j]) {
								output += ps.PL[j];
								break;
							}
						}
						break;
					}
				}
				cout << output << " & " << res << endl;
			}
		}
		else {
			string tmp = "";
			tmp += output.back();
			int len2 = output.size();

			for (int i = len2 - 1; i > 0; i--) {
				if (output[i - 1] == '#') {
					output = output.substr(0, len2 - tmp.size());
					for (int j = 0; j < ps.Np; j++) {
						if (tmp == ps.PR[j]) {
							output += ps.PL[j];
							break;
						}
					}
					break;
				}

				tmp1 = findindex(output[i], col);
				tmp2 = findindex(output[i - 1], col);
				if (equalm[tmp2][tmp1] != 1) {
					tmp = output[i - 1] + tmp;
				}
				else {
					output = output.substr(0, len2 - tmp.size());
					for (int j = 0; j < ps.Np; j++) {
						if (tmp == ps.PR[j]) {
							output += ps.PL[j];
							break;
						}
					}
					break;
				}
			}
			cout << output << " & " << res << endl;
		}
		if (output.size() == 2 && output.back() == S[0] && res.size()==1 && res.back()=='#') break;
	}
}