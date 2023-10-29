#include<iostream>
#include<vector>
#include<string>

using namespace std;

int strangPrinter(string s)
{
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
    for(int i=0;i<s.size();i++){
        dp[i][i]=1;
    }
    for(int j=1;j<s.size();j++){
        for(int i=j-1;i>=0;i--){
            int tempmin=INT_MAX;
            for(int k=i;k<j;k++){
                for (int l = i; l < k + 1; l++) {
                    if (s[l] == s[k + 1]) {
                        if ((dp[i][l] + dp[k + 1][j] - 1+dp[l+1][k]) < tempmin) {
                            tempmin = dp[i][l] + dp[k + 1][j] - 1+dp[l+1][k];
                            continue;
                        }
                    }
                }
                if(dp[i][k]+dp[k+1][j]<tempmin)
                tempmin=dp[i][k]+dp[k+1][j];
            }
            dp[i][j] = tempmin;
        }
    }
    return dp[0][s.size()-1];
}

