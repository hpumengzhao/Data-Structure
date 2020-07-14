#include<stdio.h>

const int N = 10;
typedef struct Queue{
	int data[N];
	int front,rear;
	int tag;
}Queue;
void Init(Queue &q){
	q.front=q.rear=0;
	q.tag=0;
}
bool isEmpty(Queue q){
	return q.front==q.rear&&q.tag==0;
}
bool isFull(Queue q){
	return q.front==q.rear&&q.tag==1;
}
void Push(Queue &q,int x){
	if(isFull(q)){
		return ;
	}else{
		q.data[q.rear]=x;
		q.rear=(q.rear+1)%N;
		if(q.rear==q.front){
			q.tag=1;
		}
	}
}
void Pop(Queue &q){
	if(isEmpty(q)){
		return ;
	}
	else{
		q.front=(q.front+1)%N;
		if(q.front==q.rear){
			q.tag=0;
		}
	}
}
int GetFront(Queue q){
	if(isEmpty(q)){
		return -1;
	}
	return q.data[q.front];
}
/*
	1. Push x
	2. Pop
	3. Get the front element
*/
int main(){
	Queue q;
	Init(q);
	int op,x;
	while(scanf("%d",&op)!=EOF){
		if(op==1){
			scanf("%d",&x);
			Push(q,x);
		}
		if(op==2){
			Pop(q);
		}
		if(op==3){
			int ans=GetFront(q);
			if(ans!=-1)
				printf("The front is %d\n", GetFront(q));
			else
				printf("The Queue is empty\n");
		}
	}
	return 0;
}
