/*
* @author:  codancer
* @createTime:  2020-07-16, 22:21:06
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
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
#include<stack>
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
// const int N = 200000;
// char s[N];
int main(){
	char c;
	stack<char> sta;
	while((c=getchar())!='\n'){
		// if(c==10) break;
		if(c=='['||c=='{'||c=='('){
			sta.push(c);
		}else{
			if(sta.empty()){
				printf("No\n");
				return 0;
			}
			else if(sta.top()=='('&&c!=')'){
				printf("No\n");
				return 0;
			}
			else if(sta.top()=='['&&c!=']'){
				printf("No\n");
				return 0;
			}
			else if(sta.top()=='{'&&c!='}'){
				printf("No\n");
				return 0;
			}
			else{
				sta.pop();
			}
		}
	}
	if(sta.empty()){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
