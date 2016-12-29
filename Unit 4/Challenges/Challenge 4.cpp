#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> substr;
void substrbreak(int index, string str){
	int size = str.size();
	if(index == size)
		return;
	for(int i = index+1; i <= size; i++){
		substr.push_back(str.substr(index, i-index));
	}
	return substrbreak(index+1, str);
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	substrbreak(0, s);
	//Size = 2^(given_string.size-1)-1;
	int size = substr.size();
	for(int i = 0; i < size; i++)
		if(i == size-1)
			cout << substr[i] << endl;
		else
			cout << substr[i] << " ";
	return 0;
}