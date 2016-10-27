#include <cstdio>
int unique(int *arr, int N){
	//Given sorted array
	int count = 0;
	for(int i = 0; i < N; i++){
		arr[count++] = arr[i];
		int last = arr[i];
		for(int j = i+1; j < N && arr[j] == last; j++, i++){
			last = arr[j];
			arr[j] = 0;
		}
		if(i == N-1 && count != N)
			arr[N-1] = 0;
	}
	return count;
}
int main(){
	int N;
	scanf("%d", &N);
	int arr[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int sorted_size = unique(arr, N);
	printf("%d\n", sorted_size);
	for(int i = 0; i < N; i++)
		if(i == N-1)
			printf("%d\n", arr[i]);
		else
			printf("%d ", arr[i]);
	return 0;
}