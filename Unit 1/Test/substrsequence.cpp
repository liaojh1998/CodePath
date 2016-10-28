#include <iostream>
#include <vector>
#include <string>
using namespace std;
int longestSubsequence(string x, string y){
	//O(N^2) DP solution
	//1 <= |str| <= 2000
	int xsize = x.size(), ysize = y.size(), maxlen = 0;
	vector<vector<int> > dp(ysize, vector<int>(xsize, 0));
	//DP condition
	for(int i = 0; i < ysize; i++)
		if(x[0] == y[i])
			dp[0][i] = 1;
	//DP
	for(int i = 1; i < ysize; i++){
		int cur = 0;
		for(int j = 0; j < xsize; j++){
			if(j && cur < dp[i-1][j-1])
				cur = dp[i-1][j-1];
			if(x[j] == y[i]){
				dp[i][j] = cur + 1;
				if(dp[i][j] > maxlen)
					maxlen = dp[i][j];
			}
		}
	}
	/*for(int i = 0; i < ysize; i++){
		for(int j = 0; j < xsize; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
	return maxlen;
}
int main(){
	//Given a string x and string y, calculate the maximum subsequence of x that's a substring of y
	string a, b;
	cin >> a >> b;
	cout << longestSubsequence(a, b) << endl;
	return 0;
}