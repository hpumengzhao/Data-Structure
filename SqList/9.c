#include<stdio.h>
const int N = 2000;
struct List{
	int data[N];
	int length;
}L;
/*
	GIVEN AN ORDERED LIST.
	FIND FIRST X'S POSITION AND SWAP IT WITH THE NEXT ELEMENT.
	IF THERE IS NO X, THEN INSERT IT AND MAKE IT STILL ORDERED 
*/
void FindInsert(List &L,int x){
	int l=0,r=L.length;

	/*
		BINARY SEARCH TO FIND THE FIRST ELEMENT >=X
	*/
	while(l<r){
		int mid=(l+r)/2;
		if(L.data[mid]>=x){
			r=mid;
		}else{
			l=mid+1;
		}
	}

	/*IF IS X JUST SWAP R AND R+1*/
	if(L.data[r]==x){
		if(r<L.length-1){
			int tmp=L.data[r];
			L.data[r]=L.data[r+1];
			L.data[r+1]=tmp;
		}
	}
	/*
		THAT MEANS L[R]>X
		SO INSERT X IN POSITION R
	*/
	else{
		for(int i=L.length-1;i>=r;i--){
			L.data[i+1]=L.data[i];
		}
		L.length++;
		L.data[r]=x;
	}
}
void OutPut(List &L){
	for(int i=0;i<L.length;i++){
		printf("%d ", L.data[i]);
	}
	puts("");
}
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	L.length=n;
	for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
	FindInsert(L,x);
	OutPut(L);
	return 0;
}
