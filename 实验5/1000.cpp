#include<iostream>
#include<string>
#include<cstring>
using namespace std;
struct { int number; string str[10]; } keywords = { 3,"int","main","return" }; //关键词
struct { int number; string str[10]; } operators = { 5,"+","*","=","+=","*=" }; //运算符
struct { int number; string str[10]; } boundaries = { 6,"(",")","{","}",",",";" }; //分界符
struct { int number; string str[100]; } identifieres = { 0 }; //标识符
struct { int number; string str[100]; } Unsigned_integer = { 0 }; //无符号整数

int find(string str,int length, string str2[]) {
	int flag = 0;
	for (int i = 0; i < length; i++) 
		if (str == str2[i]) return (i+1);
	
	return 0;
}

int main() {
	string str;
	int flag = 0;
	while (true) {
		getline(cin, str);
		if (str[str.size() - 1] == '#') {
			str.pop_back();
			flag = 1;
		}
		string tmpstr = "";
		int i = 0;
		while (i < str.length()) {
			if (str[i]!=' ') tmpstr += str[i];
			if (find(tmpstr, boundaries.number, boundaries.str)) {//分界符
				cout << "<" << 3 << "," << find(tmpstr, boundaries.number, boundaries.str)-1 << ">";
			}
			else {
				if (str[i] >= 'a'&& str[i] <= 'z' || str[i] >= 'A'&& str[i] <= 'Z' &&str[i]!=' ') {//字母
					while (true) {
						if (str[i + 1] >= 'a'&& str[i + 1] <= 'z' || str[i + 1] >= 'A'&& str[i + 1] <= 'Z' || str[i + 1] >= '0'&&str[i + 1] <= '9') {
							tmpstr += str[i+1];
							i++;
						}
						else {
							break;
						}
					}//在关键词则输出关键词
					if (find(tmpstr, keywords.number, keywords.str)) cout << "<" << 1 << "," << find(tmpstr, keywords.number, keywords.str)-1 << ">";
					//不在则输入标识符中
					else {
						int flag2 = find(tmpstr, identifieres.number, identifieres.str);
						if (flag2==0) {
							identifieres.number++;
							int tmp = identifieres.number - 1;
							identifieres.str[tmp] = tmpstr;
						}
						cout << "<" << 4 << "," << find(tmpstr, identifieres.number, identifieres.str)-1 << ">";
					}
				}
				else if (str[i] >= '0' && str[i] <= '9') {//数字
					while (true) {
						if (str[i + 1] >= '0'&&str[i + 1] <= '9') {
							tmpstr += str[i + 1];
							i++;
						}
						else {
							break;
						}
					}
					int newflag = 1;
					for (int j = 0; j < Unsigned_integer.number; j++) {
						if (tmpstr == Unsigned_integer.str[j]) newflag = 0;
					}
					if (newflag==1) {
						Unsigned_integer.number++;
						int tmp = Unsigned_integer.number - 1;
						Unsigned_integer.str[tmp] = tmpstr;
					}
					cout << "<" << 5 << "," << find(tmpstr, Unsigned_integer.number, Unsigned_integer.str)-1 << ">";
				}
				else if(find(tmpstr, operators.number, operators.str)){//符号
					while (true) {
						string stri1 = "" + str[i + 1];
						if (find(stri1, operators.number, operators.str)) {
							tmpstr += str[i + 1];
							i++;
						}
						else break;

					}
					cout << "<" << 2 << "," << find(tmpstr, operators.number, operators.str)-1 << ">";
				}
			}
			tmpstr = "";
			i++;
		}
		if (flag) break;
	}
	
	cout << endl << "identifieres:";
	for (int i = 0; i < identifieres.number; ++i) {
		cout << identifieres.str[i];
		if (i != identifieres.number - 1) cout << " "; else cout << endl;
	}
	
	cout  << "Unsigned_integer:";
	for (int i = 0; i < Unsigned_integer.number; ++i) {
		cout << Unsigned_integer.str[i];
		if (i != Unsigned_integer.number - 1) cout << " "; else cout << endl;
	}
	system("pause");
}