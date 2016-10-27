#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
int main(){
	//Just to speed things up
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	//Input
	string s;
	getline(cin, s);
	stringstream ss;
	ss << s;
	int N;
	ss >> N;
	//Assume N <= 1000, |str| <= 1000
	string str[1000];
	for(int i = 0; i < N; i++)
		getline(cin, str[i]);
	bool dp[1000][1000];
	memset(dp[0], 1, sizeof(dp[0]));
	for(int i = 1; i < N; i++){
		int len = str[i].size();
		for(int j = 0; j < len && dp[i-1][j] && str[i][j] == str[i-1][j]; j++)
			dp[i][j] = true;
	}
	int len = str[N-1].size(), end;
	for(end = 0; end < len && dp[N-1][end]; end++);
	cout << str[N-1].substr(0, end) << endl;
	return 0;
}