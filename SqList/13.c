#include<stdio.h>
const int N = 2000;
struct List{
	int data[N];
	int length;
}L;
/*
	FIND THE FIRST POSITIVE INTEGER THAT ISN'T IN A
*/
int FindFirst(List A){
	int cnt[N];
	for(int i=0;i<N;i++) cnt[i]=0;
	for(int i=0;i<A.length;i++){
		if(A.data[i]>0&&A.data[i]<N){
			cnt[A.data[i]]=1;
		}
	}
	int ans;
	for(int i=1;i<N;i++){
		if(cnt[i]==0){
			ans=i;
			break;
		}
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	L.length=n;
	for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
	printf("%d\n",FindFirst(L));
	return 0;
}
