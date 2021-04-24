/*
C - IPFL  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
We have a string 
S
 of length 
2
N
.
You are given 
Q
 queries on this string.
In the 
i
-th query, given three integers 
T
i
, 
A
i
, and 
B
i
, do the following:

if 
T
i
=
1
: swap the 
A
i
-th and 
B
i
-th characters of 
S
;
if 
T
i
=
2
: swap the first 
N
 characters and last 
N
 characters of 
S
 (the values 
A
i
 and 
B
i
 are not used).
For example, if 
S
 is FLIP, this query makes it IPFL.
Print the string 
S
 after processing all 
Q
 queries in the order they are given.

Constraints
1
≤
N
≤
2
×
10
5
S
 is a string of length 
2
N
 consisting of uppercase English letters.
1
≤
Q
≤
3
×
10
5
T
i
 is 
1
 or 
2
.
If 
T
i
=
1
, 
1
≤
A
i
<
B
i
≤
2
N
.
If 
T
i
=
2
, 
A
i
=
B
i
=
0
.
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
typedef pair< ll, pll>      plll;
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
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


//	ll t ; cin >> t;
//	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
void solve()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll q;
	cin >> q;
	bool f = false;
	for (ll i = 0; i < q; i++) {
		ll t, a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			a--;
			b--;
			if (f) {
				a = (a + n) % (n * 2);
				b = (b + n) % (n * 2);
			}
			swap(s[a], s[b]);
		}
		if (t == 2) {
			f = !f;
		}
	}
	if (f) {
		s = s.substr(n) + s.substr(0, n);
	}
	cout << s;

}


