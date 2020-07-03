#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
typedef struct ShareStack{
	int data[MaxSize];
	int top[2];
}ShareStack;

/*
	i==0:Push x in Stack 1
	i==1:Push x in Stack 2
*/
void Init(ShareStack &st){
	st.top[0]=-1;
	st.top[1]=MaxSize;
}
bool Push(ShareStack& st,int i,int x){
	if(i!=0&&i!=1){
		return false;
	}
	if(st.top[1]-st.top[0]==1){
		return false;
	}
	if(i==0){
		st.data[++st.top[0]]=x;
	}else{
		st.data[--st.top[1]]=x;
	}
	return true;
}
bool Pop(ShareStack &st,int i,int &x){
	if(i!=0&&i!=1){
		return false;
	}
	if(i==0){
		if(st.top[0]==-1){
			return false;
		}
		x=st.data[st.top[0]];
		--st.top[0];
	}else{
		if(st.top[1]==MaxSize){
			return false;
		}
		x=st.data[st.top[1]];
		++st.top[1];
	}
	return true;
}
int main(){
	ShareStack st;
	int x;
	Init(st);
	Push(st,0,1);
	Push(st,0,2);
	Push(st,1,3);
	Push(st,1,4);
	Pop(st,1,x);
	printf("%d\n", x);
	Pop(st,1,x);
	printf("%d\n", x);
	Pop(st,0,x);
	printf("%d\n", x);
	Pop(st,0,x);
	printf("%d\n", x);
	return 0;
}
