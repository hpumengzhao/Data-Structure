#include<stdio.h>
const int N = 1000;
struct List{
	int data[N];
	int length;
}L;
/*
 	REVERSE LIST L;
*/
void Reverse(List &L){
	for(int i=0;i<L.length/2;i++){
		int tmp=L.data[i];
		L.data[i]=L.data[L.length-i-1];
		L.data[L.length-i-1]=tmp;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	L.length=n;
	for(int i=0;i<n;i++){
		scanf("%d",&L.data[i]);
	}
	Reverse(L);	
	for(int i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	puts("");
	return 0;
}
