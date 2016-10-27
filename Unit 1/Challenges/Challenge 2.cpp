#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
vector<int> primes;
void beratostenes(int N){
	//Init
	primes.clear();
	//Add 2 and 3 to base case
	primes.push_back(2);
	primes.push_back(3);
	//Sieve of Eratostenes
	//O(N*sqrt(N)), feasible for 10000000
	for(int i = 5; i <= N; i++){
		bool prime = true;
		int size = primes.size();
		for(int j = 0; j < size && primes[j]*primes[j] <= i; j++)
			if(!(i%primes[j])){
				prime = false;
				break;
			}
		if(prime)
			primes.push_back(i);
	}
}
void eratostenes(int N){
	//Init
	primes.clear();
	//Boolean array will not work for sieve requiring N >= 1000000
	int sieve[N+1]; //Use a map if required, though O(logN) update and access
	//Sieve of Eratostenes
	//map<int, bool> sieve;
	memset(sieve, 1, sizeof(sieve));
	for(int i = 2; i <= N; i++)
		if(sieve[i]){
		//if(!sieve.count(i)){
			primes.push_back(i);
			for(int j = 2; j*i <= N; j++)
				sieve[j*i] = 0;
				//sieve[j*i] = true;
		}
}
void atkin(int N){
	//Init
	primes.clear();
	//Similar to above, will not work for sieve requiring N >= 1000000
	int sieve[N+1]; //Use a map if required
	//The Sieve of Atkin
	//Add primes 2, 3
	primes.push_back(2);
	primes.push_back(3);
	memset(sieve, 0, sizeof(sieve));
	for(int x = 1; x*x <= N; x++)
		for(int y = 1; y*y <= N; y++){
			int n = 4*x*x+y*y;
			if(n <= N && (n%12 == 1 || n%12 == 5))
				sieve[n] = ~sieve[n];
			n = 3*x*x+y*y;
			if(n <= N && n%12 == 7)
				sieve[n] = ~sieve[n];
			n = 3*x*x-y*y;
			if(x > y && n <= N && n%12 == 11)
				sieve[n] = ~sieve[n];
		}
	for(int i = 5; i*i <= N; i++)
		if(sieve[i]){
			primes.push_back(i);
			int j = 1;
			int k = j++*i*i;
			while(k <= N){
				sieve[k] = 0;
				k = j++*i*i;
			}
		}
	for(int i = sqrt(N); i <= N; i++)
		if(sieve[i])
			primes.push_back(i);
}
int main(){
	int N;
	scanf("%d", &N);
	beratostenes(N);
	//eratostenes(N);
	//atkin(N);
	int arr_size = primes.size();
	for(int i = 0; i < arr_size; i++)
		if(i == arr_size-1)
			printf("%d\n", primes[i]);
		else
			printf("%d ", primes[i]);
	return 0;
}