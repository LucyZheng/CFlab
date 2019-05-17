#include <iostream>
#include <string>
using namespace std;
char matrix[100][100];
int result[100][100] = { 0 };
char vn[100];
int n;
int f[100] = { 0 }, g[100] = { 0 };
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vn[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}
	int tmp1, tmp2;
	for (int i = 0; i <  n; i++) {
		for (int j = 0; j <  n; j++) {
			if (matrix[i][j] == '>') result[i][j + n] = 1;
			else if (matrix[i][j] == '<') result[j+n][i] = 1;
			else if (matrix[i][j] == '=') {
				result[i][j + n] = 1;
				result[j+n][i] = 1;
			}
		}
	}
	for (int j = 0; j < 2 * n; ++j) {
		result[j][j] = 1;
		for (int i = 0; i < 2*n; ++i) {
			if (result[i][j] == 1) {
				for (int k = 0; k < 2 * n; k++)
					result[i][k] = result[i][k] | result[j][k];

			}
		}
	}
	for (int i = 0; i < 2*n; i++) {
		if (i < n) {
			for (int j = 0; j < 2 * n; j++) {
				f[i] += result[i][j];
			}
		}
		else {
			for (int j = 0; j < 2 * n; j++) {
				g[i-n] += result[i][j];
			}
		}
	}
	for (int i = 0; i < 2 * n; ++i) {
		if (i < n) cout << "  " << f[i]; else cout << "  " << g[i - n];
		for (int j = 0; j < 2 * n; ++j) {
			cout << "  " << result[i][j];
		}
		cout << endl;
	}
	cout << "   ";
	for (int i = 0; i < n; i++)
		cout << "  " << vn[i];
	cout << endl << "  f";
	for (int i = 0; i < n; i++)
		cout << "  " << f[i];
	cout << endl << "  g";
	for (int i = 0; i < n; i++)
		cout << "  " << g[i];
	system("pause");

}