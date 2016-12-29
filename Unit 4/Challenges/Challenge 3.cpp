#include <cstdio>
#include <cstring>
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
//For problems like these its better to stay with while loop due to possible stack overflow
/*int gcd(int a, int b){
	while(b){
		int temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}*/
int main(){
	int arr[10000], div, N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	if(N == 1){
		printf("%d\n", arr[0]);
		return 0;
	}
	div = gcd(arr[0], arr[1]);
	for(int i = 2; i < N; i++){
		div = gcd(div, arr[i]);
	}
	printf("%d\n", div);
	return 0;
}