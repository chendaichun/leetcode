#include<iostream>
#include<vector>
#include<string>

using namespace std;

string  longestPal(string s)
{
	//if (s.length() < 2)return s;
	int maxlenth = 0;
	string maxs = "";
	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++) {
			if (s[i] == s[j]) {
				int left = i + 1;
				int right = j - 1;
				while (left < right) {
					if (s[left] == s[right]) {
						left++;
						right--;
					}
					else {
						break;
					}
				}
				if (left >= right&&j-i+1>maxlenth) {
					maxlenth = j - i + 1;
					maxs = s.substr(i, maxlenth);
				}
			}
		}
	}
	return maxs;
}


string longetsustring(string s)
{
	int length = s.size();
	vector<vector<bool>>dp(length, vector<bool>(length, 0));
	for (int i = 0; i < length-1; i++) {
		dp[i][i] = 1;
		dp[i][i + 1] = 1 ? s[i] == s[i + 1] : 0;
	}
	dp[length-1][length-1] = 1;
	if (length >= 3) {
		for (int j = 2; j < length; j++) {
			for (int i = j - 2; i >= 0; i--) {
				dp[i][j] = dp[i + 1][j - 1] & (s[i] == s[j]);
			}
		}
	}
	int max = 0;
	string maxs = "";
	for(int j=length-1;j>=0;j--){
		for (int i = 0; i < j + 1; i++) {
			if (dp[i][j] && j - i + 1 > max) {
				max = j - i + 1;
				maxs = s.substr(i, max);
			}
		}
	}
	return maxs;
}
