#include <cstdio>
#include <cstring>
int readStr(char *str){
	register char c = getchar();
	register int len = 0;
	if(!(~c)) return -1;
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
	//32 if stop at space, 10 if stop at next line
	while(c != 10 && c != 32 && ~c){
		str[len] = c;
		c = getchar();
		len++;
	}
	str[len] = '\0';
	//Just in case if needs to return arriving at end of line
	//if(c == 10) return 10;
	return 1;
}
int main(){
	int N;
	scanf("%d", &N);
	getchar();
	//Assume N <= 1000, |str| <= 1000
	char str[1000][1000];
	for(int i = 0; i < N; i++)
		readStr(str[i]);
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