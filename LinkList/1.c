#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int val;
	struct LNode *next;
}Lnode, *Linklist;


/*
	Create Linklist without head node
*/
void Construct(Linklist &L,int n){
	if(n==0) return ;

	/*
		Get L and first node s;
		s <- L
	*/
	L=(Linklist)malloc(sizeof(Linklist));
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s=L;

	/*
		s gets the first element
	*/
	int x;
	scanf("%d",&x);
	s->val=x;

	/*
		r is the next node
	*/
	LNode *r;
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		r=(LNode*)malloc(sizeof(LNode));
		r->val=x;
		s->next=r;
		s=r;
	}
	s->next=NULL;
}
/*
	Output the LinkList
*/
void OutPut(Linklist L){
	while(L!=NULL){
		printf("%d ", L->val);
		L=L->next;
	}
	puts("");
}

/*
	Delete all x from L
*/
void Del(Linklist &L,int x){
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
	Linklist L;
	Construct(L,n);
	int num;
	scanf("%d",&num);
	Del(L,num);
	OutPut(L);
	return 0;
}
