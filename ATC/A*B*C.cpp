/*
A - A*B*C  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
Given a positive integer 
K
, find the number of triples of positive integers 
(
A
,
B
,
C
)
 such that 
A
B
C
≤
K
. Two triples that only differ in the order of numbers are also distinguished.

Constraints
1
≤
K
≤
2
×
10
5
K
 is an integer.
Input
Input is given from Standard Input in the following format:

K

Output
Print the number of triples of positive integers 
(
A
,
B
,
C
)
 such that 
A
B
C
≤
K
.

Sample Input 1 
Copy
2
Sample Output 1 
Copy
4
We have the following triples: 
(
1
,
1
,
1
)
,
(
1
,
1
,
2
)
,
(
1
,
2
,
1
)
,
(
2
,
1
,
1
)
.

Sample Input 2 
Copy
10
Sample Output 2 
Copy
53
Sample Input 3 
Copy
31415
Sample Output 3 
Copy
1937281
*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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


void solve()
{

	ll n, ans = 0;
	cin >> n;
	for (ll i = 1; i <= n; ++i)
	{
		for (ll j = 1; i * j <= n; j++) {
			for (ll z = 1 ; z * i * j <= n; ++z)
			{
				ans++;
			}
		}
	}
	cout << ans;
}



