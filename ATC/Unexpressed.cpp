/*C - Unexpressed  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
Given is an integer 
N
. How many integers between 
1
 and 
N
 (inclusive) are unrepresentable as 
a
b
, where 
a
 and 
b
 are integers not less than 
2
?

Constraints
N
 is an integer.
1
≤
N
≤
10
10
Input
Input is given from Standard Input in the following format:

N

Output
Print the answer.

Sample Input 1 
Copy
8
Sample Output 1 
Copy
6
4
 and 
8
 are representable as 
a
b
: we have 
2
2
=
4
 and 
2
3
=
8
.
On the other hand, 
1
, 
2
, 
3
, 
5
, 
6
, and 
7
 are unrepresentable as 
a
b
 using integers 
a
 and 
b
 not less than 
2*/
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

	ll N;
	cin >> N;
	unordered_set<ll> s;
	for (ll a = 2; a * a <= N; a++) {
		ll x = a * a;
		while (x <= N) {
			s.insert(x);
			x *= a;
		}
	}
	cout << N - s.size();
}




, so the answer is 
6
.

Sample Input 2 
Copy
100000
Sample Output 2 
Copy
99634
