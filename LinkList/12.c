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
	Delete Same elements of an ordered LinkList
*/

void Unique(LinkList &L){
	if(L->next==NULL){
		return ;
	}

	LNode *pre=L->next;
	LNode *s=L->next->next;
	while(s!=NULL){
		if(s->val==pre->val){
			pre->next=s->next;
			free(s);
		}else{
			pre=s;
		}
		s=s->next;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	LinkList A,B,L;
	Construct(L,n);
	Unique(L);
	OutPut(L);
	return 0;
}
