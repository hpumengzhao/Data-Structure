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
	Delete the number of same abs
*/
bool vis[2000000];
int abs(int x){
	return x<=0?-x:x;
}
void DeleteAbs(LinkList &L){
	LNode *s=L->next;
	LNode* pre=L;
	while(s){
		if(vis[abs(s->val)]){
			pre->next=s->next;
			free(s);
		}else{
			vis[abs(s->val)]=1;
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
	DeleteAbs(L);
	OutPut(L);
	return 0;
}
