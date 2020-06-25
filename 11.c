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
/*
	{a1,b1,a2,b2,...an,bn}
	split to
	{a1,a2,...,an}
	{bn,...,b2,b1}
*/

void SplitAB(LinkList &L,LinkList &A,LinkList &B){
	A=(LinkList)malloc(sizeof(LinkList));
	B=(LinkList)malloc(sizeof(LinkList));
	LNode *s=L->next;
	int cnt=1;

	LNode *PA=A;
	LNode *PB=B;
	LNode *p;
	while(s!=NULL){
		p=(LNode*)malloc(sizeof(LNode));
		p->val=s->val;
		p->next=NULL;
		if(cnt%2==1){
			PA->next=p;
			PA=p;
		}
		else{
			PB->next=p;
			PB=p;
		}
		s=s->next;
		cnt++;
	}
	Reverse(B);

}

int main(){
	int n;
	scanf("%d",&n);
	LinkList A,B,L;
	Construct(L,n);
	SplitAB(L,A,B);
	OutPut(A);
	puts("");
	OutPut(B);
	puts("");
	return 0;
}
