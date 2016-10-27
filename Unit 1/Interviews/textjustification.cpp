#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main(){
	//Pretty interesting but annoying implementation problem
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	//Input
	string str;
	getline(cin, str);
	string num;
	getline(cin, num);
	int justlen;
	stringstream ss;
	ss << num;
	ss >> justlen;
	//Text Justification
	vector<string> ans;
	justtext(str, justlen, ans);
	return 0;
}