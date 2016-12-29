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
template <typename E> bool checkTree(TreeNode<E>* head){
	queue<TreeNode<E>* > q;
	q.push(head);
	while(!q.empty()){
		TreeNode<E>* cur = q.front(); q.pop();
		if(cur->left != NULL && cur->left->value >= cur->value)
			return false;
		if(cur->right != NULL && cur->right->value < cur->value)
			return false;
		if(cur->left != NULL)
			q.push(cur->left);
		if(cur->right != NULL)
			q.push(cur->right);
	}
	return true;
}
int main(){
	int N, temp;
	//Assuming N is not 0
	scanf("%d", &N);
	if(!N){
		printf("TRUE\n");
		return 0;
	}
	scanf("%d", &temp);
	TreeNode<int> root(temp);
	for(int i = 1; i < N; i++){
		scanf("%d", &temp);
		update(&root, temp);
	}
	if(checkTree(&root))
		printf("TRUE\n");
	else
		printf("FALSE\n");
	return 0;
}