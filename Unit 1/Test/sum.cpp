#include <cstdio>
#include <vector>
using namespace std;
//Solution
int sum(vector<int> numbers){
	//O(N)
	//1 <= N <= 10^4
	//1 <= numbersi <= 10^4
	int s = 0, size = numbers.size();
	for(int i = 0; i < size; i++)
		s += numbers[i];
	return s;
}
int main(){
	//Given an array, calculate the sum
	int N, arr_i;
	scanf("%d", &N);
	vector<int> arr;
	for(int i = 0; i < N; i++){
		scanf("%d", arr_i);
		arr.push_back(arr_i);
	}
	printf("%d\n", sum(arr));
	return 0;
}