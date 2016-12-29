#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;
template <typename E> struct TreeNode{
	E value;
	TreeNode<E>* left;
	TreeNode<E>* right;
	TreeNode(){
		this->left = this->right = NULL;
	}
	TreeNode(E value){
		this->value = value;
		this->left = this->right = NULL;
	}
	void set(E value){
		this->value = value;
		this->left = this->right = NULL;
	}
	void addLeft(TreeNode<E>* left){
		this->left = left;
	}
	void addRight(TreeNode<E>* right){
		this->right = right;
	}
};
int counter;
bool vis[256], cycle;
template <typename E> string traverse(TreeNode<E>* root){
	counter++;
	string ans;
	ans += '(';
	if(vis[root->value]){
		cycle = true;
		return "";
	}
	ans += root->value;
	vis[root->value] = true;
	if(root->left != NULL)
		ans += traverse(root->left);
	if(root->right != NULL)
		ans += traverse(root->right);
	ans += ')';
	return ans;
}
string SExpression(string nodes) {
	stringstream ss(nodes);
	string cur;
	TreeNode<char> all[256];
	bool G[256][256], child[256];
	memset(G, 0, sizeof(G));
	memset(child, 0, sizeof(child));
	TreeNode<char>* root = NULL;
	int possible = 1;
	while(ss.good()){
		ss >> cur;
		if(cur.size() != 5) return "E5";
		if(root == NULL)
			root = &all[(int)cur[1]];
		if(G[cur[1]][cur[3]])
			return "E2";
		if(child[(int)cur[3]])
			return "E3";
		all[cur[1]].value = cur[1];
		all[cur[3]].value = cur[3];
		G[cur[1]][cur[3]] = true;
		child[cur[3]] = true;
		if(all[cur[1]].left != NULL && all[cur[1]].right != NULL)
			return "E1";
		if(all[cur[1]].left == NULL)
			all[cur[1]].addLeft(&all[cur[3]]);
		else if(all[cur[1]].left->value > all[cur[3]].value){
			all[cur[1]].addRight(all[cur[1]].left);
			all[cur[1]].addLeft(&all[cur[3]]);
		}else
			all[cur[1]].addRight(&all[cur[3]]);
		if(all[cur[1]].left == root || all[cur[1]].right == root)
			root = &all[cur[1]];
		possible++;
	}
	if(root == NULL) return "E5";
	string answer = traverse(root);
	if(cycle)
		return "E3";
	if(counter < possible)
		return "E4";
	return answer;
}
int main(){
	string s;
	getline(cin, s);
	cout << SExpression(s) << endl;
	return 0;
}