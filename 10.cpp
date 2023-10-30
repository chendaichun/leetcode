#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isMarch(string s, string p)
{
	int m = 0;
	int n = 0;
	//匹配开头
	if (s[0] == p[0] || p[0] == '.') {
		m++;
		n++;
	}
	else if (p[1] = '*'&&p[2]==s[0]) {
		m++;
		n += 3;
	}
	else return false;
	for (m; m < s.size(); m++) {
		if (n > p.size() - 1)return false;
		if (s[m] == p[n] || p[m] == '.') {
			n++; continue;
		}
		else if (p[n] == '*') {
			if (p[n - 1] == s[m])continue;
			else if (p[n + 1] == s[m]) {
				n += 2;
				continue;
			}
		}
	}
	if (p[n]=='*'||p[n]=='\0')return true;
	else return false;
}

bool isMarch1(string s, string p)
{
	vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
	dp[0][0] = true;
	for (int i = 1; i < p.size()+1; i++) {
		if (p[i-1] == '*') {
			dp[i][0] = dp[i - 2][0];
		}
	}
	for (int i = 1; i < p.size()+1; i++) {
		for (int j = 1; j < s.size()+1; j++) {
			if (p[i-1] != '*') {
				dp[i][j] = dp[i - 1][j - 1]&&
					(p[i-1]==s[j-1]||p[i-1]=='.');
			}
			else {
				if (p[i - 2] == s[j-1]||p[i-2]=='.') {
					dp[i][j] = (dp[i][j - 1] || dp[i - 2][j]);
				}
				else dp[i][j] = dp[i - 2][j];
			}
		}
	}
	return dp[p.size()][s.size()];
}

bool isMarch3(string s, string p)
{
	vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
	//初始化dp数组
	dp[s.size()][p.size()] = 1;
	for (int j = p.size(); j >1; j--) {
		if (p[j-1] == '*') {
			dp[s.size()][j-1]=
			dp[s.size()][j - 2] = dp[s.size()][j];
		}
		for (int j = p.size() - 1; j > 0; j--) {
			for (int i = s.size() - 1; i > 0; i--) {
				if (p[j] != '*') {
					dp[i][j] = dp[i + 1][j + 1] && (s[i] == p[i] || p[i] == '.');
				}
				else {
					if (p[j - 1] == s[i]) {
						dp[i][j]=
						dp[i][j - 1] = dp[i + 1][j - 1] || dp[i][j + 1];
					}
					else {
						dp[i][j]=
						dp[i][j - 1] = dp[i][j + 1];
					}
				}
			}
		}
	}
	return dp[0][0];
}
//bool isMatch(string s, string p) {
//	return isMarch4(s, p, 0, 0);
//}

bool isMarch4(string s, string p,int ptra,int ptrb)
{
	bool first_march = ((ptra==s.size() && (ptrb==p.size() || (!p.size()-ptrb == 1 && p[2+ptrb] == '*'))) ||
	
		s[ptra] == p[ptrb] || 
		p[ptrb] == '.'	);
	if (p.size()-ptrb > 1 && p[1+ptrb] == '*'&&s.size()-ptra) {
		return (first_march && isMarch4(s, p,ptra+1,ptrb+0)) ||
			(isMarch4(s, p,ptra,ptrb+2));
	}
	if ((s.size()-ptra>0)&&( p.size()-ptrb>0)) {
		return first_march&&isMarch4(s, p,ptra+1,ptrb+1);
	}
	if (s.size()-ptra == 0 &&p.size()-ptrb>0) {
		return p[1+ptrb]=='*' && isMarch4(s,p,ptra+0,ptrb+2);
	}
	return first_march;
}
int main()
{
	string s = "aa";
	string p = "a*";
	cout << isMarch4(s, p,0,0);
}