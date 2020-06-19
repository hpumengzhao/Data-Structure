#include<stdio.h>
const int N = 1000;
struct List{
	int data[N];
	int length;
}L;
/*
 	DELETE THE MINIMUM ELEMENT OF LIST L
*/
bool DelMinEle(List &L){
	/*
		IF THE LIST IS EMPTY, RETURN FALSE;
	*/
	if(L.length==0) return false;

	/*
	 FIND THE MINIMUM ELEMENT'S ID
	*/
	int MinId,Min=1e9;
	for(int i=0;i<L.length;i++){
		if(L.data[i]<Min){
			Min=L.data[i];
			MinId=i;
		}
	}
	/*
		DELETE 
	*/
	for(int i=MinId;i<L.length-1;i++){
		L.data[i]=L.data[i+1];
	}

	L.length--;

	return true;

}
int main(){
	int n;
	scanf("%d",&n);
	L.length=n;
	for(int i=0;i<n;i++){
		scanf("%d",&L.data[i]);
	}
	if(DelMinEle(L)){
		puts("DELETE SUCCESS");
		for(int i=0;i<L.length;i++){
			printf("%d ",L.data[i]);
		}
		puts("");
	}else{
		puts("THE LIST IS EMPTY!");
	}
	return 0;
}
