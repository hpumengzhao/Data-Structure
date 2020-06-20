#include<stdio.h>
const int N = 2000;
struct List{
	int data[N];
	int length;
}L;
/*
	REVERSE [l,r] OF LIST L
*/
void Reverse(List &L,int l,int r){
	/*
		CHECK 
	*/
	if(l>r){
		return ;
	}
	if(l<0||r>L.length-1){
		return ;
	}

	for(int i=l;i<l+(r-l+1)/2;i++){
		int temp=L.data[i];
		L.data[i]=L.data[l+r-i];
		L.data[l+r-i]=temp;
	}
}

/*
	MOVE L RIGHT P STEPS (P>0&&P<N)
	=
	SWAP LSAT P ELE AND FISRT N-P ELE
*/
void MOVEP(List &L,int p){
	Reverse(L,0,L.length-1);
	Reverse(L,0,p-1);
	Reverse(L,p,L.length-1);
}
void OutPut(List &L){
	for(int i=0;i<L.length;i++){
		printf("%d ", L.data[i]);
	}
	puts("");
}
int main(){
	int n,p;
	scanf("%d %d",&n,&p);
	L.length=n;
	for(int i=0;i<n;i++){
		scanf("%d",&L.data[i]);
	}
	MOVEP(L,p);
	OutPut(L);
	return 0;
}
