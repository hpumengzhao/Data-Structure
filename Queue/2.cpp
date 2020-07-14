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
	Reverse a queue by stack
*/
int n,x;
queue<int> q;
void ReverseQ(queue<int> &q){
	stack<int> sta;
	while(!q.empty()){
		sta.push(q.front());q.pop();
	}
	while(!sta.empty()){
		q.push(sta.top());
		sta.pop();
	}
}
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>x;
		q.push(x);
	}
	ReverseQ(q);
	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
}
