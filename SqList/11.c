#include<stdio.h>
const int N = 2000;
struct List{
	int data[N];
	int length;
}A,B;
/*
	FIND THE MEDIAN NUM OF TWO 
	ORDERD LIST A & B
*/
int FindMedian(List A,List B){
	int n=A.length;
	int i=0,j=0;
	int cnt=0;
	int ans;
	while(i<n&&j<n){
		if(i==n){
			cnt++;
			ans=B.data[j];
			j++;
		}else if(j==n){
			cnt++;
			ans=A.data[i];
			i++;
		}
		else if(A.data[i]<=B.data[j]){
			cnt++;
			ans=A.data[i];
			i++;
		}else{
			cnt++;
			ans=B.data[j];
			j++;
		}
		if(cnt==n) break;
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	A.length=B.length=n;
	for(int i=0;i<n;i++) scanf("%d",&A.data[i]);
	for(int i=0;i<n;i++) scanf("%d",&B.data[i]);
	int ans=FindMedian(A,B);
	printf("%d\n", ans);
	return 0;
}
