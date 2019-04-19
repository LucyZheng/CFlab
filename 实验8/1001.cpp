#include <iostream>
#include <string>
using namespace std;
struct { int Nv; string VN[10]; bool enabled[20]; } Vns = { 0 };
struct { int Nt; string VT[10]; } Vts = { 0 };
struct { int Np; string PL[20], PR[20]; bool enabled[20]; } ps = { 0 };
string S;
string used = "";


bool inuse(char a) {
	for (int i = 0; i < used.size(); i++) 
		if (a == used[i]) return true;
	return false;
}
void useful() {
	for (int i = 0; i < Vts.Nt; ++i) {
		used += Vts.VT[i];
	}
	bool usechange = true;
	while (usechange) {
		usechange = false;
		for (int i = 0; i < ps.Np; ++i) {
			for (int j = 0; j < ps.PR[i].size(); ++j) {
				if (inuse(ps.PR[i][j]) && !inuse(ps.PL[i][0])) {
					used += ps.PL[i];
					usechange = true;
					break;
				}
			}
		}
		
	}
}
int main() {
	cin >> S >> Vns.Nv;
	for (int i = 0; i < Vns.Nv; ++i) {
		cin >> Vns.VN[i];
		Vns.enabled[i] = true;
	}
	cin >> Vts.Nt;
	for (int i = 0; i < Vts.Nt; ++i)
		cin >> Vts.VT[i];
	cin >> ps.Np;
	for (int i = 0; i < ps.Np; i++) {
		cin >> ps.PL[i] >> ps.PR[i];
		ps.enabled[i] = true;
	}
	for (int i = 0; i < ps.Np; ++i) {//自产生式
		if (ps.PL[i] == ps.PR[i]) {
			ps.enabled[i] = false;
			cout << "delete self production:" << ps.PL[i] << ":=" << ps.PR[i] << endl;

		}
	}
	useful();
	bool changed = true;
	while (changed) {
		changed = false;
		for (int i = Vns.Nv - 1; i >= 1; i--) {
			int flag = 0;
			if (Vns.enabled[i]) {
				for (int j = 0; j < ps.Np; j++) {
					for (int k = 0; k < ps.PR[j].size(); ++k) {
						if (Vns.VN[i][0] == ps.PR[j][k] && ps.enabled[j] == true) {
							flag = 1;
						}
					}

				}
				if (!flag) {
					changed = true;
					Vns.enabled[i] = false;
					cout << "unreached Vn:" << Vns.VN[i] << endl << "delete VN:" << Vns.VN[i] << endl;
					for (int j = 0; j < ps.Np; j++) {
						if (ps.PL[j] == Vns.VN[i] && ps.enabled[j]) {
							cout << "delete production:" << ps.PL[j] << ":=" << ps.PR[j] << endl;
							ps.enabled[j] = false;
						}
					}

				}
			}
			if (Vns.enabled[i]) {
				int flag2 = 0;
				for (int k3 = 0; k3 < used.size(); ++k3) {
					if (Vns.VN[i][0] == used[k3]) flag2 = 1;
				}
				if (!flag2) {
					changed = true;
					Vns.enabled[i] = false;
					cout << "unusefulNv:" << Vns.VN[i] << endl << "delete VN:" << Vns.VN[i] << endl;
					for (int k4 = 0; k4 < ps.Np; k4++) {
						int tmp = 0;
						for (int k2 = 0; k2 < ps.PR[k4].size(); ++k2) {
							if (ps.PR[k4][k2] == Vns.VN[i][0]) tmp = 1;
						}
						if ((ps.PL[k4] == Vns.VN[i] || tmp==1)&& ps.enabled[k4]) {
							cout << "delete production:" << ps.PL[k4] << ":=" << ps.PR[k4] << endl;
							ps.enabled[k4] = false;
						}
					}
				}
			}

		}
	}
	cout << "G[" << S << "]:" << endl;
	for (int i = 0; i < Vns.Nv; ++i) {
		string result = "";
		for (int j = 0; j < ps.Np; ++j) {
			if (ps.enabled[j] && Vns.VN[i] == ps.PL[j]) {
				if (result == "") {
					result = Vns.VN[i] + "::=" + ps.PR[j];
				}
				else {
					result += "|" + ps.PR[j];
				}
			}
		}
		if (Vns.enabled[i]) cout << result << endl;
	}
}