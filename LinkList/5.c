#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int val;
	struct LNode *next;
}LNode,*LinkList;

/*
	Create a LinkList with head node
*/
void Construct(LinkList &L,int n){
	L=(LinkList)malloc(sizeof(LinkList));
	LNode *s,*r;
	s=L;
	s->next=NULL;

	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);

		r=(LNode*)malloc(sizeof(LNode));
		r->val=x;
		s->next=r;
		s=r;
	}
	s->next=NULL;
}

/*
	Print LinkList with head
*/
void OutPut(LinkList L){
	while(L->next!=NULL){
		printf("%d ", L->next->val);
		L=L->next;
	}
	puts("");
}

/*
	Reverse LinkList 
*/
void Reverse(LinkList &L){
	/*
		Record the pre node and the next node
	*/
	LNode *pre,*nxt;
	LNode *s=L->next;

	pre=NULL;
	while(s!=NULL){
		nxt=s->next;
		if(nxt==NULL){
			L->next=s;
		}
		s->next=pre;
		pre=s;
		s=nxt;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	LinkList L;
	Construct(L,n);
	Reverse(L);
	OutPut(L);
	puts("");
	return 0;
}
