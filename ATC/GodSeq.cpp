/*
A - God Sequence  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
A sequence of length 
A
+
B
, 
E
=
(
E
1
,
E
2
,
…
,
E
A
+
B
)
, that satisfies all of the conditions below is said to be a god sequence.

E
1
+
E
2
+
⋯
+
E
A
+
B
=
0
 holds.
There are exactly 
A
 positive integers among 
E
1
,
E
2
,
…
,
E
A
+
B
.
There are exactly 
B
 negative integers among 
E
1
,
E
2
,
…
,
E
A
+
B
.
E
1
,
E
2
,
…
,
E
A
+
B
 are all distinct.
−
10
9
≤
E
i
≤
10
9
,
E
i
≠
0
 holds for every 
i
 
(
1
≤
i
≤
A
+
B
)
.
Construct one god sequence.

We can prove that at least one god sequence exists under Constraints of this problem.

Constraints
1
≤
A
≤
1000
1
≤
B
≤
1000
All values in input are integers.
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
typedef pair<pll, ll>      plll;
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


	//ll t ; cin >> t;
	//while (t--)
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
	ll a, b;
	cin >> a >> b;
	ll sa = 1, sb = -1, s1 = 0, s2 = 0;
	ll x = min(a, b);
	foi(x - 1) {
		cout << sa << " " << sb << " ";
		sa++, sb--;
	}
	a -= x ;
	b -= x ;
	a++, b++;
	if (a > b) {
		foi(a) {
			cout << sa << " ";
			s1 += sa;
			sa++;
		}
		cout << -s1 << " ";
	}
	else {
		foi(b) {
			cout << sb << " ";
			s2 += abs(sb);
			sb--;
		}
		cout << s2 << " ";
	}
}


