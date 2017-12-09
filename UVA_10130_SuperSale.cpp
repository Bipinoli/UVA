#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int n, int value[], int cost[]) {
	int dp[n][W+1];
	for (int i=0; i<=W; i++) 
		dp[0][i] = (cost[0] <= i) ? value[0] : 0;
	for (int i=0; i<n; i++)
		dp[i][0] = 0;
	for (int i=1; i<n; i++)
		for (int j=0; j<=W; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= cost[i])
				dp[i][j] = max(dp[i][j], value[i] + dp[i-1][j-cost[i]]);
		}

	return dp[n-1][W];
}

int main() {
	int T;
	cin >>  T;
	while (T--) {
		int n;
		cin >> n;
		int value[n], cost[n];
		for (int i=0; i<n; i++) 
			cin >> value[i] >> cost[i];
		int q;
		cin >> q;
		int ans = 0;
		while (q--) {
			int w;
			cin >> w;
			ans += knapsack(w, n, value, cost);
		}
		cout << ans << endl;
	}
}