#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
template <typename E> struct TreeNode{
	E value;
	TreeNode<E>* left;
	TreeNode<E>* right;
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
template <typename E> void update(TreeNode<E>* head, E value){
	queue<TreeNode<E>* > q;
	q.push(head);
	while(!q.empty()){
		TreeNode<E>* cur = q.front(); q.pop();
		if(value < cur->value){
			if(cur->left != NULL){
				q.push(cur->left);
			}else{
				TreeNode<E>* temp = (TreeNode<E>*) malloc(sizeof(TreeNode<E>));
				temp->set(value);
				cur->addLeft(temp);
				return;
			}
		}else{
			if(cur->right != NULL){
				q.push(cur->right);
			}else{
				TreeNode<E>* temp = (TreeNode<E>*) malloc(sizeof(TreeNode<E>));
				temp->set(value);
				cur->addRight(temp);
				return;
			}
		}
	}
}
template <typename E> void dfs(TreeNode<E>* cur, vector<int> path, vector<vector<int> >* answer, E sum, E value){
	sum += cur->value;
	path.push_back(cur->value);
	if(cur->left == NULL && cur->right == NULL && sum == value)
		answer->push_back(path);
	if(cur->left != NULL)
		dfs(cur->left, path, answer, sum, value);
	if(cur->right != NULL)
		dfs(cur->right, path, answer, sum, value);
}
int main(){
	int N, value, temp;
	//Assuming N is not 0
	scanf("%d%d", &N, &value);
	if(!N){
		printf("0\n");
		return 0;
	}
	scanf("%d", &temp);
	TreeNode<int> root(temp);
	for(int i = 1; i < N; i++){
		scanf("%d", &temp);
		update(&root, temp);
	}
	vector<int> possible;
	vector<vector<int> > answer;
	dfs(&root, possible, &answer, 0, value);
	int size = answer.size();
	for(int i = 0; i < size; i++){
		int arrlen = answer[i].size();
		printf("%d", answer[i][0]);
		for(int j = 1; j < arrlen; j++)
			printf("->%d", answer[i][j]);
		printf("\n");
	}
	return 0;
}