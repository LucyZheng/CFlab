#include<iostream>
#include<string>
using namespace std;
struct { int Nv; string VN[10]; } Vns = { 0 };
struct { int Nt; string VT[10]; } Vts = { 0 };
struct { int Np; string PL[20], PR[20]; bool enabled[20]; } ps = { 0 };
string S;
int first[100][100];
int last[100][100];
int firstplus[100][100],firststar[100][100];
int lastplus[100][100],lastplust[100][100];
int equalm[100][100],lequalm[100][100],requalm[100][100];

int findindex(char a, string col) {
	for (int i = 0; i < col.size(); i++)
		if (a == col[i]) return i;
}
void plu(int m[][100], int m2[][100],int n) {
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
	for (int i = 0; i < ps.Np; i++) {
		int mi = findindex(ps.PL[i][0], col);
		int mj = findindex(ps.PR[i][0], col);
		int mj2 = findindex(ps.PR[i][ps.PR[i].size() - 1], col);
		first[mi][mj] = 1;
		last[mi][mj2] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (first[i][j] != 1) first[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (last[i][j] != 1) last[i][j] = 0;
		}
	}
	plu(firstplus,first, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (firstplus[i][j] != 1) firstplus[i][j] = 0;
		}
	}
	plu(lastplus,last, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (lastplus[i][j] != 1) lastplus[i][j] = 0;
		}
	}
	int tmp1, tmp2;
	for (int i = 0; i < ps.Np; ++i) {
		for (int j = 0; j < ps.PR[i].size()-1; ++j) {
				tmp1 = findindex(ps.PR[i][j], col);
				tmp2 = findindex(ps.PR[i][j+1], col);
				equalm[tmp1][tmp2] = 1;
			
			
		}
	}
	cout << "EQUAL=" << endl << "   ";
	for (int i = 0; i < n; ++i)
		cout << "  " << col[i];
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "  " << col[i];
		for (int j = 0; j < n; ++j) {
			if (equalm[i][j] != 1) equalm[i][j] = 0;
			cout << "  " << equalm[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		firststar[i][i] = 1;
		for (int j = 0; j < n; j++) {
			firststar[i][j] = firstplus[i][j];
			lastplust[i][j] = lastplus[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			lequalm[i][j] = 0;
			for (int k = 0; k < n; k++) {
				lequalm[i][j] += equalm[i][k] * firststar[k][j];
			}
		}
	}
	cout << "LEQUAL=" << endl << "   ";
	for (int i = 0; i < n; ++i)
		cout << "  " << col[i];
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "  " << col[i];
		for (int j = 0; j < n; ++j) {
			cout << "  " << lequalm[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			requalm[i][j] = 0;
			for (int k = 0; k < n; k++) {
				requalm[i][j] += lastplust[i][k] * equalm[k][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				requalm[i][j] += requalm[i][k] * firststar[k][j];
			}
		}
	}
	cout << "GEQUAL=" << endl << "   ";
	for (int i = 0; i < n; ++i)
		cout << "  " << col[i];
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "  " << col[i];
		for (int j = 0; j < n; ++j) {
			cout << "  " << requalm[i][j];
		}
		cout << endl;
	}
	cout << "M[R]=" << endl << "   ";
	for (int i = 0; i < n; ++i)
		cout << "  " << col[i];
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "  " << col[i];
		for (int j = 0; j < n; ++j) {
			if (equalm[i][j]) cout << "  " << '=';
			else if (lequalm[i][j]) cout << "  " << '<';
			else if (requalm[i][j]) cout << "  " << '>';
			else cout << "  " << ' ';
		}
		cout << endl;
	}
	system("pause");
}