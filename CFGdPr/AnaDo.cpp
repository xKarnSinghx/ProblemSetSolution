/*
C. Anadi and Domino
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Anadi has a set of dominoes. Every domino has two parts, and each part contains some dots. For every a and b such that 1≤a≤b≤6, there is exactly one domino with a dots on one half and b dots on the other half. The set contains exactly 21 dominoes. Here is an exact illustration of his set:


Also, Anadi has an undirected graph without self-loops and multiple edges. He wants to choose some dominoes and place them on the edges of this graph. He can use at most one domino of each type. Each edge can fit at most one domino. It's not necessary to place a domino on each edge of the graph.

When placing a domino on an edge, he also chooses its direction. In other words, one half of any placed domino must be directed toward one of the endpoints of the edge and the other half must be directed toward the other endpoint. There's a catch: if there are multiple halves of dominoes directed toward the same vertex, each of these halves must contain the same number of dots.

How many dominoes at most can Anadi place on the edges of his graph?

Input
The first line contains two integers n and m (1≤n≤7, 0≤m≤n⋅(n−1)2) — the number of vertices and the number of edges in the graph.

The next m lines contain two integers each. Integers in the i-th line are ai and bi (1≤a,b≤n, a≠b) and denote that there is an edge which connects vertices ai and bi.

The graph might be disconnected. It's however guaranteed that the graph doesn't contain any self-loops, and that there is at most one edge between any pair of vertices.

Output
Output one integer which denotes the maximum number of dominoes which Anadi can place on the edges of the graph.

Examples
inputCopy
4 4
1 2
2 3
3 4
4 1
outputCopy
4
inputCopy
7 0
outputCopy
0
inputCopy
3 1
1 3
outputCopy
1
inputCopy
7 21
1 2
1 3
1 4
1 5
1 6
1 7
2 3
2 4
2 5
2 6
2 7
3 4
3 5
3 6
3 7
4 5
4 6
4 7
5 6
5 7
6 7
outputCopy
16
Note
Here is an illustration of Anadi's graph from the first sample test:


And here is one of the ways to place a domino on each of its edges:


Note that each vertex is faced by the halves of dominoes with the same number of dots. For instance, all halves directed toward vertex 1 have three dots.


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
const ll modx = 998244353;
ld PI = 3.1415926535897;
const ll N = 200010;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t ; cin >> t;
	while (t--)
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
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
}
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}
ll ask(ll x, ll y, ll n) {
	cout << "?" << " ";
	foi(n - 1) {
		cout << x << " ";
	}
	cout << y << endl;
	ll s;
	cin >> s;
	return s;
}
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
bool is_sorted(vector<ll>a) {
	ll x = 0;
	for (ll i = 0; i < a.size() - 1; i++) {
		if (a[i] < a[i + 1])
			x++;
	}
	return x == a.size() - 1;
}
bool check(string a, string b) {
	ll n = a.size(), m = b.size();
	if (a < b) {
		return true;
	}
	if (a > b) {
		return false;
	}
	foi(a.size()) {
		if (a[i] > b[i]) {
			return false;
		}
		else if (a[i] < b[i]) {
			return true;
		}
	}
	return false;
}
bool isSubSequence(string a, string b, ll m, ll n) {
	ll j = 0;
	for (ll i = 0; i < n and j < m; i++)
		if (a[j] == b[i])
			j++;
	return (j == m);
}
void solve() {
	ll n, m;
	cin >> n >> m;
	ll g[n + 1][n + 1];
	memset(g, 0, sizeof(g));
	foi(m) {
		ll u, v;
		cin >> u >> v;
		g[u][v] = 1, g[v][u] = 1;
	}
	if (n <= 6) {
		cout << m;
		return ;
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = i + 1; j <= n; j++) {
			ll k = 0;
			for (ll x = 1; x <= n; x++) {
				if (x == i or x == j)
					continue;
				if (g[i][x] and g[j][x])
					k++;
			}
			ans = max(ans, m - k);
		}
	}
	cout << ans;
}



