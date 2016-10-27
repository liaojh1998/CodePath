#include <cstdio>
long long minstar(int *arr, int N, int start){
	//O(N) solution, for a circle indeed
	//Remake of the original Candy problem in Hackerrank
	//This is not dynamic programming
	int last = arr[start];
	long long incre = 1, decre = 1, total = 1, high;
	bool newhigh = false;
	for(int i = (start+1)%N, k = 1; k < N; i = (i+1)%N, k++){
		if(arr[i] > last){
			total += ++incre;
			//printf("%d ", incre);
			high = incre;
			newhigh = true;
			decre = 0;
		}else if(arr[i] == last){
			total += 1;
			//printf("1 ");
			decre = incre = 1;
			newhigh = false;
		}else if(arr[i] < last){
			total += ++decre;
			//printf("%d ", decre);
			if(newhigh && decre == high){
				total -= high;
				total += ++decre;
				newhigh = false;
			}
			incre = 1;
		}
		last = arr[i];
	}
	return total;
}
int main(){
	//Assume:
	//1 <= N <= 100000
	//-2^31 <= Ni <= 2^31
	int N;
	scanf("%d", &N);
	int arr[N], start = 0;
	//pick any maxima
	//a relative maxima require at most 3 integers, and an extreme maxima require at most 2 integers
	//solution feasible for both
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		if(!start && i > 1 && ((arr[i-1] > arr[i] && arr[i-1] > arr[i-2]) || (arr[i-1] < arr[i] && arr[i-1] < arr[i-2])))
			start = i-1;
	}
	printf("%d\n", minstar(arr, N, start));
	return 0;
}