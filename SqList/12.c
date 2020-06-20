#include<stdio.h>
const int N = 2000;
struct List{
	int data[N];
	int length;
}L;
/*
	FIND THE ELE THAT IT APPEARS MORE THAN N/2
	TIMES
*/
int FindMajor(List A){
	if(A.length==0){
		return -1;
	}
	int now=A.data[0];
	int count=1;
	for(int i=1;i<A.length;i++){
		if(now==A.data[i]){
			++count;
		}else{
			--count;
			if(count==0){
				now=A.data[i];
				count=1;
			}
		}
	}
	count=0;
	for(int i=0;i<A.length;i++){
		if(A.data[i]==now) ++count;
	}
	if(count>A.length/2){
		return now;
	}
	return -1;
}
int main(){
	int n;
	scanf("%d",&n);
	L.length=n;
	for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
		printf("%d\n",FindMajor(L));
	return 0;
}
