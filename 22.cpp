#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

vector<string> generateParenthesis(int n)
{
	if (n == 1)return vector<string>(1,"()");
	vector<vector<string>> dp(n+1,vector<string>());
	dp[0].push_back({ "" });
	dp[1].push_back({ "()" });
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i - 1; j++) {
			for (int k = 0; k < dp[j].size(); k++) {
				for (int l = 0; l < dp[i - j - 1].size(); l++) {
					dp[i].push_back('(' + dp[j][k] + ')' + dp[i - j - 1][l]);
				}
			}
		}
	}
	return dp[n];
}
int main()
{
	vector<string> i = generateParenthesis(3);
	for (string m:i) {
		cout << m << endl;
	}

}