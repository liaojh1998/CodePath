#include <cstdio>
#include <cstring>
int substrpal(char* str, int len, char* substr){
	int substrlen = 0, a, b;
	bool dp[len][len];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < len; i++){
		dp[i][i] = true;
		if(i != len-1)
			dp[i][i+1] = (str[i] == str[i+1]);
	}
	for(int i = len-1; i >= 0; i--){
		for(int j = i+1; j < len; j++){
			dp[i][j] = (dp[i][j] || (str[i] == str[j] && dp[i+1][j-1]));
			if(dp[i][j] && (j - i) > substrlen){
				substrlen = j - i + 1;
				a = i, b = j;
			}
		}
	}
	memcpy(substr, str+a, substrlen+1);
	return substrlen;
}
int main(){
	int len;
	scanf("%d", &len);
	char str[len];
	scanf("%s", &str);
	//Counts both the amount of palindrome substrings in string
	//and also finds longest palindrome substring
	char substr[len];
	memset(substr, 0, sizeof(substr));
	int substrlen = substrpal(str, len, substr);
	printf("%d\n%s\n", substrlen, substr);
	return 0;
}