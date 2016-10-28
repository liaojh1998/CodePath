#include <cstdio>
#include <vector>
using namespace std;
int max(int a, int b){
	return a > b ? a : b;
}
int search(int lo, int hi, int index, vector<long long> prefix, long long k){
	int mid = (hi + lo)/2;
	if(lo == hi)
		return lo;
	if((prefix[index] - prefix[mid]) > k)
		return search(mid+1, hi, index, prefix, k);
	else
		return search(lo, mid, index, prefix, k);
}
int subarray(vector<int> arr, int k){
	//Failed this question in the test, but found an O(NlogN) solution that improves greatly from O(N^2)
	//1 <= N <= 10^5
	//0 <= ai, k <= 10^9
	//Require array to be nonnegative
	int size = arr.size(), maxsubarray = 0;
	vector<long long> prefix(size+1, 0);
	//Binary search
	for(int i = 1; i < size+1; i++){
		prefix[i] = prefix[i-1] + (long long)arr[i-1];
		//printf("%d %d\n", i, search(0, i, i, prefix, (long long)k));
		maxsubarray = max(maxsubarray, i - search(0, i, i, prefix, (long long)k));
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
	printf("%d\n", subarray(arr, k));
	return 0;
}