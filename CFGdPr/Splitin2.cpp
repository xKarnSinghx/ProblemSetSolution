/*
E. Split Into Two Sets
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp was recently given a set of n (number n — even) dominoes. Each domino contains two integers from 1 to n.

Can he divide all the dominoes into two sets so that all the numbers on the dominoes of each set are different? Each domino must go into exactly one of the two sets.

For example, if he has 4 dominoes: {1,4}, {1,3}, {3,2} and {4,2}, then Polycarp will be able to divide them into two sets in the required way. The first set can include the first and third dominoes ({1,4} and {3,2}), and the second set — the second and fourth ones ({1,3} and {4,2}).

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The descriptions of the test cases follow.

The first line of each test case contains a single even integer n (2≤n≤2⋅105) — the number of dominoes.

The next n lines contain pairs of numbers ai and bi (1≤ai,bi≤n) describing the numbers on the i-th domino.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case print:

YES, if it is possible to divide n dominoes into two sets so that the numbers on the dominoes of each set are different;
NO if this is not possible.
You can print YES and NO in any case (for example, the strings yEs, yes, Yes and YES will be recognized as a positive answer).

Example
inputCopy
6
4
1 2
4 3
2 1
3 4
6
1 2
4 5
1 3
4 6
2 3
5 6
2
1 1
2 2
2
1 2
2 1
8
2 1
1 2
4 3
4 3
5 6
5 7
8 6
7 8
8
1 2
2 1
4 3
5 3
5 4
6 7
8 6
7 8
outputCopy
YES
NO
NO
YES
YES
NO
Note
In the first test case, the dominoes can be divided as follows:

First set of dominoes: [{1,2},{4,3}]
Second set of dominoes: [{2,1},{3,4}]
In other words, in the first set we take dominoes with numbers 1 and 2, and in the second set we take dominoes with numbers 3 and 4.
In the second test case, there's no way to divide dominoes into 2 sets, at least one of them will contain repeated number.
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
#define graph          vector<vector<ll>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<ld>          vld;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<vll, ll>             mvlll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000001;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input3.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output3.txt", "w", stdout);
#endif
	ll t; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve() {
	ll n;
	cin >> n;
	vll a(n), b(n), freq(n, 0), vis(n, 0), col(n, 0);
	foi(n) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		freq[a[i]]++, freq[b[i]]++;
	}
	foi(n) {
		if (freq[i] > 2) {
			cout << "NO";
			return;
		}
	}
	graph g(n, vll());
	foi(n) {
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	ll ok = 1;
	function<void(ll, ll, ll)>dfs = [&](ll u, ll p, ll c) {
		col[u] = c;
		vis[u] = 1;
		for (ll v : g[u]) {
			if (v == p)
				continue;
			if (col[u] == col[v]) {
				ok = 0;
				return;
			}
			if (vis[v])
				continue;
			dfs(v, u, 3 - c);
		}
	};
	foi(n) {
		if (!vis[i]) {
			dfs(i, -1, 1);
		}
	}
	(ok == 1) ? cout << "YES" : cout << "NO";
}
