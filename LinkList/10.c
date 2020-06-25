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
	Split A to A and B
*/
void Split(LinkList &A,LinkList &B){
	if(A->next==NULL){
		return ;
	}
	B=(LinkList)malloc(sizeof(LinkList));
	B->next=NULL;

	LNode *Apre=A;
	LNode *PA=A->next;
	LNode *PB=B;

	int cnt=1;
	while(PA!=NULL){
		if(cnt%2==0){
			LNode *tmp=(LNode*)malloc(sizeof(LNode));
			tmp->val=PA->val;
			tmp->next=NULL;
			PB->next=tmp;
			PB=tmp;

			Apre->next=PA->next;
			free(PA);
		}
		else{
			Apre=PA;
		}
		PA=PA->next;
		cnt++;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	LinkList A,B;
	Construct(A,n);
	Split(A,B);
	OutPut(A);
	puts("");
	OutPut(B);
	puts("");
	return 0;
}
