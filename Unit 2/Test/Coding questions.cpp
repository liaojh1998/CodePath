/*
 * Complete the function below.
 */
string firstRepeatedWord(string s) {
    map<string, int> freq;
    string str;
    int size = s.size();
    for(int i = 0; i < size; i++){
        if(s[i] == ' ' || s[i] == ',' || s[i] == ';' || s[i] == ':' || s[i] == '-' || s[i] == '.' || s[i] == 9){
            if(str.size()){
                if(freq.count(str))
                    return str;
                else
                    freq[str] = 1;
                str.clear();
            }
        }
        else
            str += s[i];
    }
    return str;
}

/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
LinkedListNode* removeNodes(LinkedListNode* list, int x) {
    while(list->val > x) list = list->next;
    LinkedListNode* head = list;
    while(list->next != NULL){
        if(list->next->val > x)
            list->next = list->next->next;
        else
            list = list->next;
    }
    return head;
}

#include <cstdio>
#include <cstring>
using namespace std;
int abs(int a){
    if(a < 0)
        return a*(-1);
    else
        return a;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    getchar();
    while(n--){
        char str[10005];
        memset(str, 0, sizeof(str));
        scanf("%s", &str);
        if(strlen(str)%2){
            printf("-1\n");
            continue;
        }
        int len = strlen(str)/2, ans = 0;
        //possible ascii = 256
        int freq[256];
        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < len; i++)
            freq[str[i]]++;
        for(int i = len; i < len*2; i++)
            if(freq[str[i]])
                freq[str[i]]--;
            else
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}