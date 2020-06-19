#include<stdio.h>
const int N = 1000;
struct List{
	int data[N];
	int length;
}L;
/*
 	TASK: DELETE ALL ELEMENT BETWEEN [S,T] OF AN ORDERED LIST
 	TIME: O(N)

*/
bool DelInterval(List &L,int s,int t){
	if(L.length==0){
		printf("LIST IS EMPTY\n");
		return false;
	}
	if(s>t){
		printf("Interval is illegal\n");
		return false;
	}
	int num=0;
	int last=L.length;
	/*
		CACULATE THE NUMBER OF ELE BETWEEN [S,T]
		AND THE FIRST ELEMENT AFTER THE INTERVAL
	*/
	for(int i=0;i<L.length;i++){
		if(L.data[i]>=s&&L.data[i]<=t){
			++num;
		}
		else{
			if(num){
				last=i;
				break;
			}
		}
	}

	/*
		DELETE
	*/
	for(int i=last;i<L.length;i++){
		L.data[i-num]=L.data[i];
	}

	L.length-=num;
	return true;

}
int main(){
	int n;
	scanf("%d",&n);
	L.length=n;
	for(int i=0;i<n;i++){
		scanf("%d",&L.data[i]);
	}
	if(DelInterval(L,1,5)){
		printf("DELETE SUCCESS\n");
		for(int i=0;i<L.length;i++){
			printf("%d ",L.data[i]);
		}
		puts("");
	}
	return 0;
}
