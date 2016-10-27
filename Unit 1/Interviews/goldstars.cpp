#include <cstdio>
int arr[1000000];
int main(){
	int N, start = 0;
	scanf("%d", &N);
	//Find first decreasing sequence
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		if(!start && i != 0)
			if(arr[i] > arr[i-1])
				start = i;
	}

	return 0;
}