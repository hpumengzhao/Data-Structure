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
	Delete x from L
*/
void Del(LinkList &L,int x){
	if(L==NULL) return ;
	LNode *p;
	if(L->val==x){
		p=L;
		L=L->next;
		free(p);
		Del(L,x);
	}else{
		Del(L->next,x);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	LinkList L;
	Construct(L,n);
	int x;
	scanf("%d",&x);
	Del(L,x);
	OutPut(L);
	return 0;
}
