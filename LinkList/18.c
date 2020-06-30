#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

/*
	Create a single cycle LinkList
*/
void CreateSingleCy(LinkList &L,int n){
	L=(LinkList)malloc(sizeof(LinkList));

	L->next=L;
	LNode *s=L;
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		LNode *r=(LNode*)malloc(sizeof(LNode));
		r->data=x;
		s->next=r;
		s=r;
	}
	s->next=L;
}
void OutPut(LinkList L){
	LNode *s=L;
	while(s->next!=L){
		printf("%d ", s->next->data);
		s=s->next;
	}
	puts("");
}

/*
	Connect B to A
	B & A are single cycle LinkiList
*/
void Connect(LinkList &A,LinkList &B){
	if(B->next==B){
		return ;
	}
	LNode *s=A->next;
	while(s->next!=A){
		s=s->next;
	}
	s->next=B->next;
	LNode *r=B;
	while(r->next!=B){
		r=r->next;
	}
	r->next=A;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	LinkList A,B;
	CreateSingleCy(A,n);
	CreateSingleCy(B,m);

	Connect(A,B);
	OutPut(A);
	return 0;
}
