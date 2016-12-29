#include <cstdio>
#include <cstdlib>
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
template <typename E> bool update(TreeNode<E>* head, E value){
	bool added = false;
	if(value < head->value && head->left != NULL)
		added = update(head->left, value);
	else if(value < head->value){
		TreeNode<E>* temp = (TreeNode<E>*) malloc(sizeof(TreeNode<E>));
		temp->set(value);
		head->addLeft(temp);
		return true;
	}
	if(added) return true;
	if(value >= head->value && head->right != NULL)
		added = update(head->right, value);
	else if(value >= head->value){
		TreeNode<E>* temp = (TreeNode<E>*) malloc(sizeof(TreeNode<E>));
		temp->set(value);
		head->addRight(temp);
		return true;
	}
	if(added) return true;
	return false;
}
vector<int> traversed;
template <typename E> void traverse(TreeNode<E>* head){
	traversed.push_back(head->value);
	if(head->left != NULL)
		traverse(head->left);
	if(head->right != NULL)
		traverse(head->right);
}
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int Q, N, temp;
	scanf("%d", &Q);
	while(Q--){
		scanf("%d%d", &N, &temp);
		TreeNode<int> root(temp);
		vector<int> answer;
		answer.push_back(temp);
		for(int i = 1; i < N; i++){
			scanf("%d", &temp);
			answer.push_back(temp);
			update(&root, temp);
		}
		traverse(&root);
		int size = answer.size();
		bool success = true;
		for(int i = 0; i < size && success; i++){
			//printf("%d %d\n", answer[i], traversed[i]);
			if(answer[i] != traversed[i])
				success = false;
		}
		if(success)
			printf("YES\n");
		else
			printf("NO\n");
		traversed.clear();
	}
	return 0;
}