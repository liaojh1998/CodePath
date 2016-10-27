#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
string space(int len){
	char str[len];
	memset(str, ' ', sizeof(str));
	str[len] = '\0';
	string s(str);
	return s;
}
void justlefttext(string str, int justlen, vector<string> &ans){
	stringstream ss;
	ss << str;
	queue<string> q;
	string next;
	while(ss.good() || !q.empty()){
		int len = q.empty() ? 0 : q.front().size();
		int num = q.empty() ? 0 : 1;
		while(ss.good()){
			ss >> next;
			q.push(next);
			if(len + next.size() + num - 1 < justlen){
				num++;
				len+= next.size();
			}else{
				break;
			}
		}
		//This is based on the assumption that word length will always be <= justification length
		int right = justlen - (len + num - 1);
		string sp = space(right);
		string answer;
		for(int i = 0; i < num-1; i++){
			answer += q.front();
			q.pop();
			answer += ' ';
		}
		answer += q.front();
		q.pop();
		answer += sp;
		ans.push_back(answer);
	}
}
void justrighttext(string str, int justlen, vector<string> &ans){
	stringstream ss;
	ss << str;
	queue<string> q;
	string next;
	while(ss.good() || !q.empty()){
		int len = q.empty() ? 0 : q.front().size();
		int num = q.empty() ? 0 : 1;
		while(ss.good()){
			ss >> next;
			q.push(next);
			if(len + next.size() + num - 1 < justlen){
				num++;
				len+= next.size();
			}else{
				break;
			}
		}
		//This is based on the assumption that word length will always be <= justification length
		int left = justlen - (len + num - 1);
		string sp = space(left);
		string answer;
		answer += sp;
		for(int i = 0; i < num-1; i++){
			answer += q.front();
			q.pop();
			answer += ' ';
		}
		answer += q.front();
		q.pop();
		ans.push_back(answer);
	}
}
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
	vector<string> ansleft, ansright;
	justlefttext(str, justlen, ansleft);
	justrighttext(str, justlen, ansright);
	//Print
	int size = ansleft.size();
	for(int i = 0; i < size; i++)
		cout << ansleft[i] << endl;
	size = ansright.size();
	for(int i = 0; i < size; i++)
		cout << ansright[i] << endl;
	return 0;
}