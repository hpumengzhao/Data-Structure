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

int Len(LinkList &L){
	if(L->next==NULL){
		return 0;
	}
	LNode *s=L->next;
	int len=0;
	while(s!=NULL){
		s=s->next;
		++len;
	}
	return len;
}
bool GetK(LinkList &L,int k){
	int len=Len(L);

	if(k>len||k<=0){
		return 0;
	}
	int id=len-k+1;
	LNode *s=L;
	for(int i=1;i<=id;i++){
		s=s->next;
	}
	printf("%d\n", s->val);
	return 1;
}



int main(){
	int n;
	scanf("%d",&n);
	LinkList L;
	Construct(L,n);
	int k;
	scanf("%d",&k);
	if(GetK(L,k)){
		printf("Find it!\n");
	}else{
		printf("Sorry\n");
	}
	return 0;
}
