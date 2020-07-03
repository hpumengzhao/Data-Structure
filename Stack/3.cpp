#include<bits/stdc++.h>

using namespace std;
/*
  Check the operation seq of a stack.
*/
bool check(string s){
	int balance=0;
	for(char c:s){	
		if(c=='I') ++balance;
		else --balance;
		if(balance<0){
			return false;
		}
	}
	return balance==0;
}
int main(){
	string s;
	cin>>s;
	if(check(s)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
