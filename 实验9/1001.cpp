#include<iostream>
#include<string>
using namespace std;
struct { int Nv; string VN[10]; } Vns = { 0 };
struct { int Nt; string VT[10]; } Vts = { 0 };
struct { int Np; string PL[20], PR[20]; bool enabled[20]; } ps = { 0 };
string S;
int first[100][100];
int last[100][100];
int findindex(char a, string col) {
	for (int i = 0; i < col.size(); i++)
		if (a == col[i]) return i;
}
void plu(int m[][100],int n) {
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
		cin >> tmp>>ps.PL[i] >> ps.PR[i];
	for (int i = 0; i < ps.Np; i++) {
		int mi = findindex(ps.PL[i][0], col);
		int mj = findindex(ps.PR[i][0], col);
		int mj2 = findindex(ps.PR[i][ps.PR[i].size() - 1], col);
		first[mi][mj] = 1;
		last[mi][mj2] = 1;
	}
	cout << "FIRST=" << endl<<"   ";
	for (int i = 0; i < n; ++i)
		cout << "  " << col[i];
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "  " << col[i];
		for (int j = 0; j < n; ++j) {
			if (first[i][j] != 1) first[i][j] = 0;
			cout << "  " << first[i][j];
		}
		cout << endl;
	}
	cout << "LAST=" << endl << "   ";
	for (int i = 0; i < n; ++i)
		cout << "  " << col[i];
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "  " << col[i];
		for (int j = 0; j < n; ++j) {
			if (last[i][j] != 1) last[i][j] = 0;
			cout << "  " << last[i][j];
		}
		cout << endl;
	}
	plu(first, n);
	cout << "FIRST+=" << endl << "   ";
	for (int i = 0; i < n; ++i)
		cout << "  " << col[i];
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "  " << col[i];
		for (int j = 0; j < n; ++j) {
			if (first[i][j] != 1) first[i][j] = 0;
			cout << "  " << first[i][j];
		}
		cout << endl;
	}
	plu(last, n);
	cout << "LAST+=" << endl << "   ";
	for (int i = 0; i < n; ++i)
		cout << "  " << col[i];
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "  " << col[i];
		for (int j = 0; j < n; ++j) {
			if (last[i][j] != 1) last[i][j] = 0;
			cout << "  " << last[i][j];
		}
		cout << endl;
	}
	
}