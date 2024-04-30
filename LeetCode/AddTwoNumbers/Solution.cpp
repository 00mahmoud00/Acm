#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);

void FastIO(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

void ReadWriteIO(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

struct ListNode {
    int data;
    struct ListNode* next;
    ListNode(int data,ListNode* next = NULL){
        this->data = data;
        this->next = next;
    }

    void print(){
        ListNode* curr = this;
        while(curr != NULL){
            cout<<curr->data<<"  ";
            curr = curr->next;
        }
        cout<<"\n---------------------------\n";
    }

    // int getLength(){
    //     int count = 0;
    //     ListNode* curr = this;
    //     while(curr != NULL){
    //         count++;
    //         curr = curr->next;
    //     }
    //     return count;
    // }

    // ListNode* ReturnLast(){
    //     ListNode* curr = this;
    //     while(curr != NULL){
    //         if(curr->next == NULL)
    //             return curr;
    //         curr = curr->next;
    //     }
    //     return NULL;
    // }
    // void ResizeWithZeros(int newSize){
    //     int length = getLength();
    //     ListNode* last = ReturnLast();
    //     for(int i = length; i < newSize; i++){
    //         last->next = new ListNode(0);
    //         last = last->next;
    //     }
    // }
};

ListNode* reverse(ListNode* head) {
    ListNode* current = head;
    ListNode *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void solve(){
}
ListNode* ReturnLast(ListNode* head){
    ListNode* curr = head;
    while(curr != NULL){
        if(curr->next == NULL)
            return curr;
        curr = curr->next;
    }
    return NULL;
}
int getLength(ListNode* head){
    int count = 0;
    ListNode* curr = head;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }
    return count;
}
void ResizeWithZeros(int newSize,ListNode* head){
    int length = getLength(head);
    ListNode* last = ReturnLast(head);
    for(int i = length; i < newSize; i++){
        last->next = new ListNode(0);
        last = last->next;
    }
}
int main(){
    // ReadWriteIO();
    ListNode* n1 = new ListNode(2);
    n1->next = new ListNode(4);
    n1->next->next = new ListNode(9);

    ListNode* s1 = new ListNode(5);
    s1->next = new ListNode(6);
    s1->next->next = new ListNode(4);
    s1->next->next->next = new ListNode(9);

    int maxLen = max(getLength(n1),getLength(s1));

    ResizeWithZeros(maxLen,n1);
    ResizeWithZeros(maxLen,s1);
    // s1->print();
    // n1->print();

    ListNode* ans = new ListNode(0);
    ResizeWithZeros(maxLen + 1,ans);
    ListNode* tranAns = ans;
    int remain = 0;
    for(int i=0;i<maxLen;i++){
        int sum = s1->data + n1->data + remain;
        if(sum >= 10){
            ans->data = sum - 10;
            remain = 1;
        }
        else{
            ans->data = sum;
            remain = 0;
        }
        ans = ans->next;
        s1 = s1->next;
        n1 = n1->next;
    }
    if(remain > 0){
        ans->data = remain;
    }else{
        ans = NULL;
    }
    tranAns->print();
    // ans->print();
    // tranAns->print();
    // // solve();
}