#include <iostream>
#include <string>
using namespace std;
int main() {
	int m[100][100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> m[i][j];
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (m[i][j] == 1) {
				for (int k = 0; k < n; k++)
					m[i][k] = m[i][k] | m[j][k];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (j == n - 1) cout << ' ' << m[i][j]; else cout << ' ' << m[i][j] << ' ';
		cout << endl;
	}
	system("pause");

}