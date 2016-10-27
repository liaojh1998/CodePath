#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int substrpal(string str, int len, string* substr){
	int substrlen = 0, a, b;
	bool dp[len][len];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < len; i++){
		dp[i][i] = true;
		if(i != len-1)
			dp[i][i+1] = (str[i] == str[i+1]);
	}
	//O(N^2)
	for(int i = len-1; i >= 0; i--){
		for(int j = i+1; j < len; j++){
			dp[i][j] = (dp[i][j] || (str[i] == str[j] && dp[i+1][j-1]));
			if(dp[i][j] && (j - i) > substrlen){
				substrlen = j - i + 1;
				a = i, b = j;
			}
		}
	}
	*substr = str.substr(a, substrlen);
	return substrlen;
}
int main(){
	//Assume |str| <= 100000
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	string str;
	getline(cin, str);
	//Counts both the amount of palindrome substrings in string
	//and also finds longest palindrome substring
	string substr;
	cout << substrpal(str, str.size(), &substr) << endl << substr << endl;
	return 0;
}