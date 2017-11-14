#include <iostream>
using namespace std;

int main() {
	int n, m;
	int t = 0;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			return 0;
		t++;
		if (t > 1) cout << endl;
		char arr[n][m], ans[n][m];
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			for (int k=0; k<s.size(); k++) 
				arr[i][k] = s[k];
		}
		for (int i=0; i<n; i++) 
			for (int j=0; j<m; j++) {
				if (arr[i][j]=='*') {
					ans[i][j] = '*';
					continue;
				}
				int c = 0;
				for (int p=-1; p<=1; p++)
					for (int q=-1; q<=1; q++) {
						if (p == 0 && q == 0) continue;
						if (p+i < n && p+i >=0 && q+j < m && q+j >= 0 && arr[p+i][q+j] == '*')
							c++;
					}
				ans[i][j] = '0'+c;
			}
		cout << "Field #" << t << ":" << endl;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
				cout << ans[i][j];
			cout << endl;
		}
	}
}