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
	Delete the mininum element of L
	Suppose the mininum one is only.
*/
void DelMin(LinkList &L){
	LNode *MinNode;
	int Min=1e9;
	LNode *s=L->next;
	while(s!=NULL){
		if(s->val<Min){
			Min=s->val;
			MinNode=s;
		}
		s=s->next;
	}
	s=L;
	while(s!=NULL){
		if(s->next==MinNode){
			s->next=MinNode->next;
			break;
		}
		s=s->next;
	}
	free(MinNode);
}
int main(){
	int n;
	scanf("%d",&n);
	LinkList L;
	Construct(L,n);
	DelMin(L);
	OutPut(L);
	puts("");
	return 0;
}
