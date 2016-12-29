#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
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
int counter;
template <typename E> void update(TreeNode<E>* head, E value){
	queue<TreeNode<E>* > q;
	q.push(head);
	while(!q.empty()){
		counter++;
		TreeNode<E>* cur = q.front(); q.pop();
		if(value < cur->value){
			if(cur->left != NULL){
				q.push(cur->left);
			}else{
				TreeNode<E>* temp = (TreeNode<E>*) malloc(sizeof(TreeNode<E>));
				temp->set(value);
				cur->addLeft(temp);
				printf("%d\n", counter);
				return;
			}
		}else{
			if(cur->right != NULL){
				q.push(cur->right);
			}else{
				TreeNode<E>* temp = (TreeNode<E>*) malloc(sizeof(TreeNode<E>));
				temp->set(value);
				cur->addRight(temp);
				printf("%d\n", counter);
				return;
			}
		}
	}
}
void createBST(vector < int > keys) {
	int N = keys.size(), temp = keys[0];
	TreeNode<int> root(temp);
	printf("0\n");
	for(int i = 1; i < N; i++)
		update(&root, keys[i]);
}
int main(){
	int N, temp;
	scanf("%d", &N);
	vector<int> keys;
	for(int i = 0; i < N; i++){
		scanf("%d", &temp);
		keys.push_back(temp);
	}
	createBST(keys);
	return 0;
}