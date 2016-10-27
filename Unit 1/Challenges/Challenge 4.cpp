#include <cstdio>
#include <string>
//Forgive me for using string class (SO SLOW)
//I would've used cstring if string length is defined
using namespace std;
bool pal(string str){
	int len = str.size();
	for(int i = 0; i < len/2; i++)
		if(str[i] != str[len-i-1]) return false;
	return true;
}
void toLower(char &c){
	c += 32;
}
int main(){
	char c;
	string str;
	while(c = getchar(), ~c && c != 10){
		if(c > 64 && c < 91)
			toLower(c);
		if(c > 96 && c < 123)
			str += c;
	}
	printf("%s\n", pal(str) ? "true" : "false");
	return 0;
}