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
	Merge two ordered LinkList.
*/
LinkList Merge(LinkList &A,LinkList &B){
	LNode *PA=A->next;
	LNode *PB=B->next;
	LNode *s=A->next;
	LNode *NXT;//must record the next of now node
	A->next=NULL;
	while(PA&&PB){
		if(PA->val>=PB->val){
			NXT=PB->next;
			PB->next=A->next;
			A->next=PB;
			PB=NXT;
		}else{
			NXT=PA->next;
			PA->next=A->next;
			A->next=PA;
			PA=NXT;
		}
	}
	while(PA){
		NXT=PA->next;
		PA->next=A->next;
		A->next=PA;
		PA=NXT;
	}
	while(PB){
		NXT=PB->next;
		PB->next=A->next;
		A->next=PB;
		PB=NXT;
	}
	return A;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	LinkList A,B,L;
	Construct(A,n);
	Construct(B,m);
	L=Merge(A,B);
	OutPut(L);
	return 0;
}
