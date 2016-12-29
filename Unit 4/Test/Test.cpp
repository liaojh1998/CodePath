/*
 * Complete the function below.
 */
void pascalTriangle(int k) {
    int ans[k][k];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < k; i++){
        ans[i][0] = 1;
    }
    for(int i = 0; i < k; i++){
        printf("1");
        for(int j = 1; j <= i; j++){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
}

/*
 * Complete the function below.
 */
bool dfs(int a, int b, int c, int d){
    if(a == c && b == d)
        return true;
    if(a > c || b > d)
        return false;
    bool ans = dfs(a + b, b, c, d);
    if(ans)
        return true;
    ans |= dfs(a, a + b, c, d);
    return ans;
}
string isPossible(int a, int b, int c, int d) {
    bool ans = dfs(a, b, c, d);
    if(ans)
        return "Yes";
    return "No";
}

/*
 * Complete the function below.
 */
#define mod (1000000007)
int numberOfPaths(vector < vector < int > > a) {
    int dp[1001][1001], ysize = a.size(), xsize = a[0].size();
    memset(dp, 0, sizeof(dp));
    if(!a[0][0])
        return 0;
    dp[1][1] = a[0][0];
    for(int i = 1; i <= ysize; i++){
        for(int j = 1; j <= xsize; j++){
            if(a[i-1][j-1] && !(i == 1 && j == 1))
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
        }
    }
    return dp[ysize][xsize];
}

