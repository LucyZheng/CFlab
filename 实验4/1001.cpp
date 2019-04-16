#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//将I去除重复的状态以及将状态排序
string tran(string str) {
	string newstr;
	for (int i = 0; i < str.size(); ++i) {
		int flag = 0;
		for (int j = i + 1; j < str.size(); ++j) {
			if (str[i] == str[j]) flag = 1;
		}
		if (!flag) newstr += str[i];
	}
	for (int i = 0; i < newstr.size(); ++i) {
		for (int j = 0; j < newstr.size() - i - 1; ++j) {
			if (newstr[j] > newstr[j + 1]) {
				char tmp = newstr[j];
				newstr[j] = newstr[j + 1];
				newstr[j + 1] = tmp;
			}
		}
	}
	return newstr;
}
//确定化的过程
void determin(string alphabet, string state[][4], string reflec[][3], int statelen, int reflen, string start, string end) {
	string table[1000][3];
	table[0][0] = start;
	int maxlen = 1, oldlen = 0;
	//搜索过程
	while (true) {
		for (int k = oldlen; k < maxlen; ++k) {
			for (int i = 0; i < table[k][0].size(); ++i) {
				for (int j = 0; j < reflen; ++j) {
					//判断属于Ix还是Iy
					if (table[k][0][i] == reflec[j][0][0])
						if (reflec[j][2][0] == 'x') {
							table[k][1] += reflec[j][1];
							string tmp = reflec[j][1];
							//搜索字母为k的状态的节点
							for (int k2 = 0; k2 < reflen; k2++) {
								if (reflec[k2][0][0] == tmp[0] && reflec[k2][2][0] == 'k') {
									table[k][1] += reflec[k2][1];
									tmp = reflec[k2][1][0];
									k2 = 0;
								}
							}
						} 
						else if (reflec[j][2][0] == 'y') {
							table[k][2] += reflec[j][1];
							string tmp = reflec[j][1];
							//搜索字母为k的状态的节点
							for (int k2 = 0; k2 < reflen; k2++) {
								if (reflec[k2][0][0] == tmp[0] && reflec[k2][2][0] == 'k') {
									table[k][2] += reflec[k2][1];
									tmp = reflec[k2][1][0];
									k2 = 0;
								}
							}
						}
							

				}
				//删去重复节点与节点排序
				table[k][1] = tran(table[k][1]);
				table[k][2] = tran(table[k][2]);

			}
			//如果状态为新状态，则加入表中
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
		//如果没有新状态添加且所有旧状态处理完毕，则退出
		if (oldlen == maxlen && table[maxlen][0] == "") break;

	}
	//输出状态表，如果状态名里含有起始节点或者终止节点，则赋值为1
	cout << "Determine State:" << endl;
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
	//将填表里的节点集转化为新的节点
	int newtable[1000][3] = { 0 };
	for (int i = 0; i < maxlen; ++i) {
		newtable[i][0] = i;
		for (int j = 0; j < maxlen; ++j) {

			if (table[j][0] == table[i][1]) newtable[i][1] = j;
			if (table[j][0] == table[i][2]) newtable[i][2] = j;

		}
	}
	//根据新的节点输出新的状态表
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
//初始化部分
int main() {
	int allen, statelen, reflen;
	string alphabet = "";
	cin >> allen;
	//输入字母表和状态表
	for (int i = 0; i < allen; i++) {
		char tmp;
		cin >> tmp;
		alphabet += tmp;
	}
	cin >> statelen;
	string state[1000][4];
	string start, end;
	for (int i = 0; i < statelen; i++) {
		for (int j = 0; j < 3; ++j) {
			cin >> state[i][j];
		}
		//判断开始和终止节点
		if (state[i][1] == "1") start = state[i][0];
		if (state[i][2] == "1") end = state[i][0];
	}
	string reflec[1000][3];
	cin >> reflen;
	for (int i = 0; i < reflen; i++)
		for (int j = 0; j<3; ++j)
			cin >> reflec[i][j];
	//确定化过程
	determin(alphabet, state, reflec, statelen, reflen, start, end);
	system("pause");
}