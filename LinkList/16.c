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
	judge if B is a sublist of A
*/
bool IsSubList(LinkList &A,LinkList &B){
	LNode *PA=A->next;
	LNode *PB=B->next;

	while(PA!=NULL){
		LNode *stA=PA;
		LNode *stB=PB;
		while(stA&&stB){
			if(stA->val!=stB->val){
				break;
			}
			stA=stA->next;
			stB=stB->next;
		}
		if(stB==NULL) return 1;
		PA=PA->next;
	}
	return 0;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	LinkList A,B,L;
	Construct(A,n);
	Construct(B,m);
	if(IsSubList(A,B)){
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}
