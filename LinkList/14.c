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
	Find the Common element of ordered A and B and make them to C
*/
LinkList FindCommmon(LinkList &A,LinkList &B){
	LNode *PA=A->next;
	LNode *PB=B->next;

	LinkList C=(LinkList)malloc(sizeof(LinkList));
	C->next=NULL;
	LNode *s=C;
	while(PA&&PB){
		if(PA->val==PB->val){
			s->next=PA;
			s=PA;
			PA=PA->next;
			PB=PB->next;
		}
		else if(PA->val>PB->val){
			PB=PB->next;
		}
		else{
			PA=PA->next;
		}
	}
	return C;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	LinkList A,B,L;
	Construct(A,n);
	Construct(B,m);
	L=FindCommmon(A,B);
	OutPut(L);
	return 0;
}
