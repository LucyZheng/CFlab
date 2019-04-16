#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string tran(string str) {
	string newstr;
	for (int i = 0; i < str.size(); ++i) {
		int flag = 0;
		for (int j = i+1; j < str.size(); ++j) {
			if (str[i] == str[j]) flag = 1;
		}
		if (!flag) newstr += str[i];
	}
	return newstr;
}

void determin(string alphabet, string state[][4], string reflec[][3], int statelen, int reflen,string start,string end) {
 	string table[1000][3];
	table [0][0] = start;
	int maxlen = 1, oldlen = 0;
	while (true) {
		for (int k = oldlen; k < maxlen; ++k) {
			for (int i = 0; i < table[k][0].size(); ++i) {
				for (int j = 0; j < reflen; ++j) {
					if (table[k][0][i] == reflec[j][0][0])
						if (reflec[j][2][0] == 'x') table[k][1] += reflec[j][1]; else table[k][2] += reflec[j][1];

				}
				table[k][1] = tran(table[k][1]);
				table[k][2] = tran(table[k][2]);

			}
			oldlen = maxlen;
			string prex = table[k][1], prey = table[k][2];
			int flag1 = 0, flag2 = 0;
			for (int j = 0; j < oldlen; j++) {
				if (table[j][0] == prex) flag1 = 1;
				if (table[j][0] == prey) flag2 = 1;
			}
			if (prex == "") flag1 = 1;
			if (prey == "") flag2 = 1;

			if (!flag1) {
				
				table[maxlen][0] = prex;
				maxlen++;
			}
			if (!flag2) {
				
				table[maxlen][0] = prey;
				maxlen++;
			}
		}
		if (oldlen == maxlen && table[maxlen][0] == "") break;
		
	}
	
	cout << "Determine State:"<<endl;
	for (int i = 0; i < maxlen; i++) {
		int ifstart = 0, ifend = 0;
		cout << i << ' ';
		for (int j = 0; j < 3; j++) {
			
			for (int l = 0; l < table[i][0].size(); ++l) {
				if (table[i][0][l] == start[0]) ifstart = 1;
				if (table[i][0][l] == end[0]) ifend = 1;
			}
			
		}
		if (ifstart) cout << 1 << ' '; else cout << 0 << ' ';
		if (ifend) cout << 1 << ' '; else cout << 0 << ' ';
		cout << '[' << table[i][0] << ']' << endl;

	}
	int newtable[1000][3] = { 0 };
	for (int i = 0; i < maxlen; ++i) {
		newtable[i][0] = i;
		for (int j = 0; j < maxlen; ++j) {
			
			if (table[j][0] == table[i][1]) newtable[i][1] = j;
			if (table[j][0] == table[i][2]) newtable[i][2] = j;

		}
	}
	cout << "Determine Mapping:" << endl;
	int num = 0;
	for (int i = 0; i < maxlen; ++i) {
		
			if (newtable[i][1] != 0) {
				cout << newtable[i][0] << ' ' << newtable[i][1] << " x (" << num << endl;;
				num++;
			}
			if (newtable[i][2] != 0) {
				cout << newtable[i][0] << ' ' << newtable[i][2] << " y (" << num << endl;
				num++;
			}
			
		
	}
}
int main() {
	int allen, statelen,reflen;
	string alphabet="";
	cin >> allen;
	for (int i = 0; i < allen; i++) {
		char tmp;
		cin >> tmp;
		alphabet+=tmp;
	}
	cin >> statelen;
	string state[1000][4];
	string start, end;
	for (int i = 0; i < statelen; i++) {
		for (int j = 0; j < 3; ++j) {
			cin >> state[i][j];
		}
		if (state[i][1] == "1") start = state[i][0];
		if (state[i][2] == "1") end = state[i][0];
	}
	string reflec[1000][3];
	cin >> reflen;
	for (int i = 0; i < reflen; i++)
		for (int j=0;j<3;++j)
			cin >> reflec[i][j];
	determin(alphabet, state, reflec, statelen, reflen,start,end);
	system("pause");
}