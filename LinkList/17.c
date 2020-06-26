#include<stdio.h>
#include<stdlib.h>
/*
	Doubly circular linked list
*/
typedef struct LNode{
	int val;
	struct LNode *next,*pre;
}LNode,*LinkList;

/*
	Create a Doubly circular linked list with head node
*/
void Construct(LinkList &L,int n){
	L=(LinkList)malloc(sizeof(LinkList));
	LNode *s;
	L->next=L;
	L->pre=L;
	s=L;
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		LNode *r=(LNode*)malloc(sizeof(LNode));
		r->val=x;
		r->next=L;
		r->pre=s;
		L->pre=r;
		s->next=r;
		s=r;
	}
}

/*
	Print Doubly circular linked list with head
*/
void OutPut(LinkList L){
	LNode *s=L;
	while(s->next!=L){
		printf("%d ", s->next->val);
		s=s->next;
	}
	puts("");
}
/*
	Check Doubly circular linked list is Palindrome
*/

bool IsPalindrome(LinkList L){
	if(L->next==L){
		return true;
	}
	LNode *left=L->next;
	LNode *right=L->next;
	while(right->next!=L){
		right=right->next;
	}
	while(left!=right){
		if(left->val!=right->val){
			return false;
		}
		left=left->next;
		right=right->pre;
	}
	return true;
}

int main(){
	int n,m;
	LinkList L;
	scanf("%d",&n);
	Construct(L,n);
	if(IsPalindrome(L)){
		puts("Yes");
	}else{
		puts("No");
	}
	// OutPut(L);
	return 0;
}
