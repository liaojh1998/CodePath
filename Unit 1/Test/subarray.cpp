#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int max(int a, int b){
	return a > b ? a : b;
}
int search(int lo, int hi, int index, int* prefix, int k){
	int mid = (hi + lo)/2;
	if(lo == hi)
		return lo;
	if((prefix[index] - prefix[mid]) > k)
		return search(mid+1, hi, index, prefix, k);
	else
		return search(lo, mid, index, prefix, k);
}
int maxLength(vector<int> a, int k){
	//Failed this question in the test, but found an O(NlogN) solution that improves greatly from O(N^2)
	//1 <= N <= 10^5
	//1 <= a[i] <= 10^3
	//1 <= k <= 10^9
	//Requires array to be nonnegative
	int size = a.size(), maxsubarray = 0;
	int prefix[size+1];
	memset(prefix, 0, sizeof(prefix));
	//Binary search
	for(int i = 1; i < size+1; i++){
		prefix[i] = prefix[i-1] + a[i-1];
		//printf("%d %d\n", i, search(0, i, i, prefix, (long long)k));
		maxsubarray = max(maxsubarray, i - search(0, i, i, prefix, k));
	}
	/*for(int i = 0; i < size+1; i++)
		printf("%lld\n", prefix[i]);*/
	return maxsubarray;
}
int main(){
	//Given an integer k and an array of integers, calculate the maximum length of the subarray that has a sum <= k
	int k, arr_i;
	scanf("%d", &k);
	vector<int> arr;
	while(~scanf("%d", &arr_i))
		arr.push_back(arr_i);
	printf("%d\n", maxLength(arr, k));
	return 0;
}