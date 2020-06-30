#include<stdio.h>
#include<stdlib.h>
const int INF = 1e9;
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
	Delete the Minimum element from L until it is NULL;
*/
void DeleteMinOrdered(LinkList &A){
	if(A->next==A){
		return ;
	}

	while(A->next!=A){
		LNode *s=A->next;
		LNode *pre=A;
		LNode *minn;//record the minimum Lnode
		LNode *minpre;
		int Min=INF;
		while(s!=A){
			if(s->data<Min){
				Min=s->data;
				minn=s;
				minpre=pre;
			}
			pre=s;
			s=s->next;
		}
		printf("%d\n",minn->data);
		minpre->next=minn->next;
		free(minn);
	}
}
int main(){
	int n,m;
	scanf("%d",&n);
	LinkList A;
	CreateSingleCy(A,n);

	DeleteMinOrdered(A);
	OutPut(A);
	return 0;
}
