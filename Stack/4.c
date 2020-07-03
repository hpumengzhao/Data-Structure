#include<stdio.h>
#include<stdlib.h>
#define MaxSize 200
typedef struct LNode{
	char data;
	struct LNode *next;
}LNode,*LinkList;
typedef struct Stack{
	char data[MaxSize];
	int top;
}Stack;
void InitStack(Stack &s){
	s.top=-1;
}
bool Empty(Stack &s){
	return s.top==-1;
}
bool Push(Stack &s,char c){
	if(s.top==MaxSize-1){
		return false;
	}
	s.data[++s.top]=c;
	return true;
}
bool Pop(Stack &s){
	if(s.top==-1){
		return false;
	}
	s.top--;
}
char GetTop(Stack &s){
	if(s.top==-1){
		return false;
	}
	return s.data[s.top];
}

/*
	If L is Palindrome return true;
	else return false;

	Put first n/2 elements to a stack 
*/
void Construct(LinkList &L,int n){
	L=(LinkList)malloc(sizeof(LinkList));
	L->next=NULL;
	LNode *s=L;
	char c;
	getchar();
	for(int i=0;i<n;i++){
		scanf("%c",&c);
		LNode *r=(LNode*)malloc(sizeof(LNode));
		r->data=c;
		s->next=r;
		s=s->next;
	}
	s->next=NULL;
}
int GetLen(LinkList &L){
	if(L->next==NULL){
		return 0;
	}
	int len=0;
	LNode* s=L->next;
	while(s){
		s=s->next;
		++len;
	}
	return len;
}
void OutPut(LinkList L){
	L=L->next;
	while(L){
		printf("%c", L->data);
		L=L->next;
	}
	puts("");
}

bool IsPalindrome(LinkList &L){
	int n=GetLen(L);
	printf("%d\n", n);
	Stack st;
	InitStack(st);
	LNode *s=L->next;

	for(int i=0;i<n/2;i++){
		Push(st,s->data);
		s=s->next;
	}
	if(n&1) s=s->next;
	while(!Empty(st)){
		if(s->data!=GetTop(st)){
			return false;
		}
		s=s->next;
		Pop(st);
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	LinkList L;
	Construct(L,n);
	// OutPut(L);
	if(IsPalindrome(L)){
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}
