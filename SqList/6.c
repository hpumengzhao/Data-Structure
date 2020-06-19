#include<stdio.h>
const int N = 1000;
struct List{
	int data[N];
	int length;
}L;
/*
	TASK:DELETE THE SAME ELEMENTS OF AN ORDERED LIST 
	TIME: O(N)
*/
bool DelSame(List &L){
	if(L.length==0){
		puts("LIST IS EMPTY!");
		return false;
	}
	int i,j;
	for(i=0,j=1;j<L.length;j++){
		if(L.data[i]!=L.data[j]){
			L.data[++i]=L.data[j];
		}
	}
	L.length=i+1;
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	L.length=n;
	for(int i=0;i<n;i++){
		scanf("%d",&L.data[i]);
	}
	if(DelSame(L)){
		for(int i=0;i<L.length;i++){
			printf("%d ", L.data[i]);
		}
		puts("");
	}
	return 0;
}
