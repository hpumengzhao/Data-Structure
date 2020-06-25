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
	Delete elements between [l,r]
*/
void DelLR(LinkList &L,int l,int r){
	if(L->next==NULL){
		return ;
	}
	LNode *s=L->next;
	LNode *pre=L;
	while(s!=NULL){
		if(s->val>=l&&s->val<=r){
			pre->next=s->next;
		}else{
			pre=s;
		}
		s=s->next;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	LinkList L;
	Construct(L,n);
	int l,r;
	scanf("%d %d",&l,&r);
	DelLR(L,l,r);
	OutPut(L);
	puts("");
	return 0;
}
