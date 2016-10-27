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
void justtext(string str, int justlen, vector<string> &ans){
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
		if(num == 1){
			int size = justlen-len;
			string shorter = space(size);
			string answer;
			answer += q.front();
			q.pop();
			ans.push_back(answer);
		}else if((justlen-len)%(num-1)){
			int left = (justlen-len)%(num-1);
			int size = (justlen-len)/(num-1);
			string longer = space(size+1);
			string shorter = space(size);
			string answer;
			for(int i = 0; i < num-1; i++){
				answer += q.front();
				q.pop();
				if(i < left)
					answer += longer;
				else
					answer += shorter;
			}
			answer += q.front();
			q.pop();
			ans.push_back(answer);
		}else{
			int size = (justlen-len)/(num-1);
			string shorter = space(size);
			string answer;
			for(int i = 0; i < num-1; i++){
				answer += q.front();
				q.pop();
				answer += shorter;
			}
			answer += q.front();
			q.pop();
			ans.push_back(answer);
		}
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
	vector<string> ans;
	justtext(str, justlen, ans);
	//Print
	int size = ans.size();
	for(int i = 0; i < size; i++)
		cout << ans[i] << endl;
	return 0;
}