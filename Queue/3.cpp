/*
* @author:  codancer
* @createTime:  2020-07-14, 21:14:26
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
#define deb(x) cerr<<#x<<" = "<<(x)<<"\n"
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll B) {
	return (ull)rng() % B;
}
/*
	Implement a queue by two stacks 
*/

stack<int> s1,s2;
int x;
void Enqueue(int x){
	s1.push(x);
}
void Dequeue(int &x){
	if(s2.empty()){
		while(!s1.empty()){
			s2.push(s1.top());s1.pop();
		}
	}
	if(s2.empty()){
		printf("Queue is empty\n");
		return ;
	}
	x=s2.top();
	s2.pop();
	printf("%d\n",x );
}
/*
	1. Enqueue
	2. Dequeue
*/
int main(){
	int op;
	while(cin>>op){
		if(op==1){
			cin>>x;
			Enqueue(x);
		}else{
			Dequeue(x);
		}
	}
	return 0;
}
