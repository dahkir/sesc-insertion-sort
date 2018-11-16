#include <stdio.h>
#include <stdlib.h>

struct Node{
 int value;
 struct Node * next;
};


void pushb(struct Node ** head, int val){
 struct Node * tempnode;
 tempnode = *head;
 while (tempnode->next!=NULL){
   tempnode = tempnode->next;
 }
 tempnode->next =(struct Node*)malloc(sizeof(struct Node));
 tempnode->next->value = val;
 tempnode->next->next = NULL;
}


int main(void) {
 struct Node *head=(struct Node*)malloc(sizeof(struct Node));
 int n, k;
 struct Node * temp;
 scanf("%d", &n);
 for (int i=0;i<n;i++){
   scanf("%d", &k);
   pushb(&head, k);
 }
 head = head->next;
 int count = n;
 while (count>0){
   temp = head;
   for(int i=count-1;i>0;i--)temp=temp->next;
   while (temp->next!=NULL){
     if (temp->value<temp->next->value){
       k = temp->value;
       temp->value = temp->next->value;
       temp->next->value = k;
     }
     temp=temp->next;
    }
  count--;
 }
 while (head!=NULL){
   printf("%d ", head->value);
   head = head->next;
 }
 return 0;
}
