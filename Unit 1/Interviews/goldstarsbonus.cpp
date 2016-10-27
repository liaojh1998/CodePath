#include <cstdio>
long long incminstar(int *arr, int N, int start, long long *ans){
	long long sum = 0;
	for(int i = start, k = 0; k < N; i = (i+1)%N, k++){
		if(arr[i] == arr[(i-1+N)%N]){
			sum += ans[(i-1+N)%N] - ans[i];
			ans[i] = ans[(i-1+N)%N];
		}
		if(arr[i] > arr[(i-1+N)%N]){
			sum += ans[(i-1+N)%N]+1 - ans[i];
			ans[i] = ans[(i-1+N)%N]+1;
		}
	}
	return sum;
}
long long decminstar(int *arr, int N, int start, long long *ans){
	long long sum = 0;
	for(int i = start, k = N-1; k >= 0; i = (i-1+N)%N, k--){
		if(arr[i] == arr[(i+1)%N] && ans[i] < ans[(i+1)%N]){
			sum += ans[(i+1)%N] - ans[i];
			ans[i] = ans[(i+1)%N];
		}
		if(arr[i] > arr[(i+1)%N] && ans[i] < ans[(i+1)%N] + 1){
			sum += ans[(i+1)%N]+1 - ans[i];
			ans[i] = ans[(i+1)%N]+1;
		}
	}
	return sum;
}
int main(){
	//Assume:
	//1 <= N <= 100000
	//-2^31 <= Ni <= 2^31
	//O(3*N) solution
	//Proof: must require at least O(2*N) to find a relative minima at the start of a increasing sequence for a circular array
	//For example: 3 4 5 6 1 2 
	//Must require O(2*N) to ensure 1 is the relative minima for an increasing sequence
	//1 O(N) to search length of increasing sequence after 1
	//1 O(N) to search length of decreasing sequence before 1, which is basically increasing sequence towards the left
	//The length is absolutely required because it dictates the number of stars required at the relative maxima
	//O(N) is only possible when the relative extrema at the start of a trend is not required, consider Candies in Hackerrank
	int N;
	scanf("%d", &N);
	int arr[N], start = 0;
	long long total = 0, ans[N];
	//search for the smallest number because it is automatically assumed to be the relative minima
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		if(arr[start] > arr[i])
			start = i;
		ans[i] = 1; //fill_n(ans, 1);
		total += ans[i];
	}
	total += incminstar(arr, N, start, ans);
	total += decminstar(arr, N, start, ans);
	printf("%lld\n", total);
	return 0;
}