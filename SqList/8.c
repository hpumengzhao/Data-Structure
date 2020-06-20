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
	REVERSE FIRST M AND REST N ELEMENTS
*/
void ReverseMN(List &L,int m,int n){
	if(m+n!=L.length){
		return ;
	}
	Reverse(L,0,L.length-1);
	Reverse(L,0,n-1);
	Reverse(L,n,L.length-1);
}
void OutPut(List &L){
	for(int i=0;i<L.length;i++){
		printf("%d ", L.data[i]);
	}
	puts("");
}
int main(){
	int n,m;
	scanf("%d %d",&m,&n);
	L.length=n+m;
	/*
	  First m elements of L
	*/
	for(int i=0;i<m;i++) scanf("%d",&L.data[i]);

	/*
		Rest n elements of L
	*/
	for(int i=m;i<L.length;i++) scanf("%d",&L.data[i]);

	ReverseMN(L,m,n);
	
	OutPut(L);
	return 0;
}
