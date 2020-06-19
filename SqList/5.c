#include<stdio.h>
const int N = 1000;
struct List{
	int data[N];
	int length;
}L;
/*
	TASK:DELETE THE ELEMENT BETWEEN [S,T] 
	TIME: O(N)
*/
bool DeleST(List &L,int s,int t){
	if(L.length==0){
		return false;
	}
	if(s>t){
		return false;
	}
	int i,j;
	for(i=0,j=0;j<L.length;j++){
		if(L.data[j]<s||L.data[j]>t){
			L.data[i++]=L.data[j];
		}
	}
	L.length=i;
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	L.length=n;
	for(int i=0;i<n;i++){
		scanf("%d",&L.data[i]);
	}
	if(DeleST(L,2,3)){
		for(int i=0;i<L.length;i++){
			printf("%d ", L.data[i]);
		}
		puts("");
	}
	return 0;
}
