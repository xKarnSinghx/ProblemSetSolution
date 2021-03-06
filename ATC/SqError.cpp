/*
C - Squared Error  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
Given is a number sequence 
A
 of length 
N
.
Find the sum of squared differences of every pair of elements:  
N
∑
i
=
2
  
i
−
1
∑
j
=
1
 
(
A
i
−
A
j
)
2
.

Constraints
2
≤
N
≤
3
×
10
5
|
A
i
|
≤
200
All values in input are integers.
Input
Input is given from Standard Input in the following format:

N

A
1
 
A
2
 
A
3
 
⋯
 
A
N

Output
Print the answer.

Sample Input 1 
Copy
3
2 8 4
Sample Output 1 
Copy
56
We have 
∑
N
i
=
2
∑
i
−
1
j
=
1
(
A
i
−
A
j
)
2
=
(
8
−
2
)
2
+
(
4
−
2
)
2
+
(
4
−
8
)
2
=
56
.

Sample Input 2 
Copy
5
-5 8 9 -4 -3
Sample Output 2 
Copy
950
*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <chrono>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<int>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair<ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

solve();
		

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}

void solve()
{

	ll n;
	cin >> n;
	ll sum = 0;
	ll ans = 0;
	foi(n) {
		ll a;
		cin >> a;
		ans += a * a * (n - 1) - 2 * a * sum;
		sum += a;
	}


	cout << ans ;
}



