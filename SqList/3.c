#include<stdio.h>
const int N = 1000;
struct List{
	int data[N];
	int length;
}L;
/*
 	TASK: DELETE ALL X FROM L
 	TIME: O(N)
 	MEMORY: O(1)
*/
void DelX(List &L,int x){
	int k=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]==x){
			++k;
		}else{
			L.data[i-k]=L.data[i];
		}
	}
	L.length-=k;
}
int main(){
	int n;
	scanf("%d",&n);
	L.length=n;
	for(int i=0;i<n;i++){
		scanf("%d",&L.data[i]);
	}
	DelX(L,3);
	for(int i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	puts("");
	return 0;
}
