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
	bool operator==(TreeNode<E> head){
		queue<pair<TreeNode<E>*, TreeNode<E>*> > q;
		#define pa (pair<TreeNode<E>*, TreeNode<E>*>)
		pair<TreeNode<E>*, TreeNode<E>*> temp;
		temp.first = this;
		temp.second = &head;
		q.push(temp);
		while(!q.empty()){
			TreeNode<E>* first = q.front().first;
			TreeNode<E>* second = q.front().second;
			q.pop();
			if(first == NULL && second == NULL)
				continue;
			if(first != NULL && second == NULL)
				return false;
			if(first == NULL && second != NULL)
				return false;
			if(first->value != second->value)
				return false;
			temp.first = first->left;
			temp.second = second->left;
			q.push(temp);
			temp.first = first->right;
			temp.second = second->right;
			q.push(temp);
		}
		return true;
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
int main(){
	int N1, temp;
	//Assuming N is not 0
	scanf("%d", &N1);
	scanf("%d", &temp);
	TreeNode<int> root1(temp);
	for(int i = 1; i < N1; i++){
		scanf("%d", &temp);
		update(&root1, temp);
	}
	int N2;
	scanf("%d", &N2);
	scanf("%d", &temp);
	TreeNode<int> root2(temp);
	for(int i = 1; i < N2; i++){
		scanf("%d", &temp);
		update(&root2, temp);
	}
	if(root1 == root2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}