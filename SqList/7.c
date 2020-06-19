#include<stdio.h>
const int N = 1000;
struct List{
	int data[N];
	int length;
}A,B;
/*
	MERGE TWO ORDERED LIST AND RETURN ANSWER.
*/
List Lmerge(List A,List B){
	List C;
	int cnt=0;
	int i=0,j=0;
	/*
		TWO POINTERS AND CHOOSE THE MIN ONE EACH TIME.
	*/
	while(i<A.length||j<B.length){
		if(i==A.length){
			C.data[cnt++]=B.data[j];
			j++;
		}
		else if(j==B.length){
			C.data[cnt++]=A.data[i];
			i++;
		}
		else if(A.data[i]>=B.data[j]){
			C.data[cnt++]=B.data[j];
			j++;
		}else{
			C.data[cnt++]=A.data[i];
			i++;
		}
	}
	C.length=cnt;
	return C;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	A.length=n;
	B.length=m;
	for(int i=0;i<n;i++) scanf("%d",&A.data[i]);
	for(int i=0;i<m;i++) scanf("%d",&B.data[i]);
	List C=Lmerge(A,B);
	for(int i=0;i<C.length;i++){
		printf("%d ",C.data[i]);
	}
	puts("");
	return 0;
}
