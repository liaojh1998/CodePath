#include <cstdio>
long long mincandy(int *arr, int N){
	//O(N) solution, for placement in a line
	//ONLY POSSIBLE BECAUSE WE DON'T NEED TO FIND A RELATIVE EXTREMA AT THE START OF A TREND
	//The original Candy problem in Hackerrank
	//This is not dynamic programming
	int last = arr[0];
	long long incre = 1, decre = 1, total = 1, high;
	bool newhigh = false;
	for(int i = 1; i < N; i++){
		if(arr[i] > last){
			//observation: increasing values always have 1 more than previous
			total += ++incre;
			//printf("%d ", incre);
			high = incre;
			newhigh = true;
			decre = 0;
		}else if(arr[i] == last){
			//observation: middle values always have 1, unless in bonus gold star case
			total += 1;
			//printf("1 ");
			decre = incre = 1;
			newhigh = false;
		}else if(arr[i] < last){
			//observation: increasing addition = decreasing addition, loop through decreasing as increasing = loop backward for decreasing
			total += ++decre;
			//printf("%d ", decre);
			if(newhigh && decre == high){
				total += 1;
				++decre;
				newhigh = false;
			}
			incre = 1;
		}
		last = arr[i];
	}
	return total;
}
long long incminstar(int *arr, int N, int start, long long *ans){
	long long sum = 0;
	for(int i = start, k = 0; k < N; i = (i+1)%N, k++){
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