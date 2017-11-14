#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e6+1;
int ans[N];
bool visited[N];

void init() {
	visited[1] = true;
	ans[1] = 1;
	for (int i=2; i<N; i++) {
		vector<long long> v;
		long long j = i;
		while (j>=N || !visited[j]) {
			v.push_back(j);
			if (j&1)
				j = 3*j+1;
			else
				j = j/2;
		}
		v.push_back(j);
		int n = v.size();
		int jump = 0;
		for (int k=n-2; k>=0; k--) {
			long long val = v[k];
			if (val < N) {
				ans[v[k]] = 1 + jump + ans[v[k+1+jump]];
				visited[v[k]] = true;
				jump = 0;
			} else 
				jump += 1;
		}
	}
}

int findAns(int l, int r) {
	int M = -1;
	for (int i=l; i<=r; i++) 
		M = max(M, ans[i]);
	return M;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	init();
	int a, b;
	while (cin >> a >> b) {
		int l = a, m = b;
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		cout << l << " " << m << " " << findAns(a,b) << endl;
	}
}