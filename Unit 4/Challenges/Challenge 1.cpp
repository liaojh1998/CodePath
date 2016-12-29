#include <cstdio>
#include <cstring>
struct BigInteger{
	int num[600], size;
	BigInteger(){
		memset(num, 0, sizeof(num));
		size = 0;
	}
	BigInteger(char* n){
		memset(num, 0, sizeof(num));
		size = strlen(n);
		for(int i = size-1; i >= 0; i--)
			num[size-i-1] = n[i]-'0';
	}
	void operator=(BigInteger bi){
		memcpy(num, bi.num, sizeof(bi.num));
		size = bi.size;
	}
	BigInteger decre(){
		BigInteger temp;
		memcpy(temp.num, num, sizeof(num));
		temp.size = size;
		temp.num[0]--;
		for(int i = 0; i < temp.size-1 && (temp.num[i] < 0); i++){
			if(temp.num[i] < 0){
				temp.num[i]+= 10;
				temp.num[i+1]--;
			}
		}
		if(temp.num[temp.size-1] <= 0){
			temp.num[temp.size-1] = 0;
			temp.size--;
		}
		return temp;
	}
	BigInteger operator*=(BigInteger bi){
		BigInteger temp;
		for(int i = 0; i < size; i++){
			for(int j = 0; j < bi.size; j++){
				temp.num[i+j] += num[i]*bi.num[j];
				temp.num[i+j+1] += temp.num[i+j]/10;
				temp.num[i+j] %= 10;
			}
		}
		for(temp.size = size + bi.size - 1; temp.num[temp.size]; temp.size++){
			temp.num[temp.size + 1] += temp.num[temp.size]/10;
			temp.num[temp.size] %= 10;
		}
		return temp;
	}
	void print(){
		for(int i = size-1; i >= 0; i--)
			printf("%d", num[i]);
		printf("\n");
	}
};
BigInteger fact(BigInteger bi){
	return (bi.size == 1 && bi.num[0] == 1) ? bi : bi*=fact(bi.decre());
}
int main(){
	char str[3]; //Max at 285
	scanf("%s", &str);
	str[strlen(str)] = '\0';
	BigInteger bi(str), fin;
	fact(bi).print();
	return 0;
}