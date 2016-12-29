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
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", gcd(a,b));
	return 0;
}