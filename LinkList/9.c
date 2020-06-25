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
	Output LinkList in order and free all nodes
	O(n^2)
*/
void PrintInOrder(LinkList &L){
	while(L->next!=NULL){
		LNode *s=L->next;
		LNode *Pre=L;
		LNode *MinNode,*MinPre;
		int MIN=1e9;
		while(s!=NULL){
			if(s->val<MIN){
				MIN=s->val;
				MinNode=s;
				MinPre=Pre;
			}
			Pre=s;
			s=s->next;
		}
		printf("%d ", MIN);
		MinPre->next=MinNode->next;
		free(MinNode);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	LinkList L;
	Construct(L,n);
	PrintInOrder(L);
	OutPut(L);
	puts("");
	return 0;
}
