#include <cstdio>
#include <cstring>
int main(){
	int N;
	scanf("%d", &N);
	//Assume N <= 1000, |str| <= 1000
	char str[1000][1000];
	for(int i = 0; i < N; i++)
		scanf("%s", &str[i]);
	bool dp[1000][1000];
	memset(dp[0], 1, sizeof(dp[0]));
	for(int i = 1; i < N; i++){
		int len = strlen(str[i]);
		for(int j = 0; j < len && dp[i-1][j] && str[i][j] == str[i-1][j]; j++)
			dp[i][j] = true;
	}
	int len = strlen(str[N-1]), end;
	for(end = 0; end < len && dp[N-1][end]; end++);
	char ans[1000];
	memset(ans, 0, sizeof(ans));
	memcpy(ans, str[N-1], end);
	printf("%s\n", ans);
	return 0;
}