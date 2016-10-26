#include <cstdio>
#include <cstring>
int main(){
	int r, c;
	scanf("%d%d", &r, &c);
	int mat[r][c];
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d", &mat[i][j]);
	//Matrix traversal
	int dirx[4] = {1, 0, -1, 0};
	int diry[4] = {0, 1, 0, -1};
	int x = 0, y = 0, arr[r*c], index = 0, dir = 0;
	bool vis[r][c];
	memset(vis, 0, sizeof(vis));
	while(y < r && x < c && x > -1 && y > -1 && !vis[y][x]){
		arr[index++] = mat[y][x];
		vis[y][x] = true;
		if(x+dirx[dir] == c || y + diry[dir] == r || x + dirx[dir] < 0 || vis[y + diry[dir]][x + dirx[dir]])
			dir = (dir + 1)%4;
		x += dirx[dir];
		y += diry[dir];
	}
	//Print
	for(int i = 0; i < r*c; i++)
		if(i == r*c - 1)
			printf("%d\n", arr[i]);
		else
			printf("%d ", arr[i]);
	return 0;
}