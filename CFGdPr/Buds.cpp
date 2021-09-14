/*
E. Buds Re-hanging
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A tree is a connected graph without cycles. A rooted tree has a special vertex called the root. The parent of a vertex v (different from root) is the previous to v vertex on the shortest path from the root to the vertex v. Children of the vertex v are all vertices for which v is the parent.

A vertex is a leaf if it has no children. We call a vertex a bud, if the following three conditions are satisfied:

it is not a root,
it has at least one child, and
all its children are leaves.
You are given a rooted tree with n vertices. The vertex 1 is the root. In one operation you can choose any bud with all its children (they are leaves) and re-hang them to any other vertex of the tree. By doing that you delete the edge connecting the bud and its parent and add an edge between the bud and the chosen vertex of the tree. The chosen vertex cannot be the bud itself or any of its children. All children of the bud stay connected to the bud.

What is the minimum number of leaves it is possible to get if you can make any number of the above-mentioned operations (possibly zero)?

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤2⋅105) — the number of the vertices in the given tree.

Each of the next n−1 lines contains two integers u and v (1≤u,v≤n, u≠v) meaning that there is an edge between vertices u and v in the tree.

It is guaranteed that the given graph is a tree.

It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

Output
For each test case print a single integer — the minimal number of leaves that is possible to get after some operations.

Example
inputCopy
5
7
1 2
1 3
1 4
2 5
2 6
4 7
6
1 2
1 3
2 4
2 5
3 6
2
1 2
7
7 3
1 5
1 3
4 6
4 7
2 1
6
2 1
2 3
4 5
3 4
3 6
outputCopy
2
2
1
2
1
Note
In the first test case the tree looks as follows:


Firstly you can choose a bud vertex 4 and re-hang it to vertex 3. After that you can choose a bud vertex 2 and re-hang it to vertex 7. As a result, you will have the following tree with 2 leaves:


It can be proved that it is the minimal number of leaves possible to get.

In the second test case the tree looks as follows:


You can choose a bud vertex 3 and re-hang it to vertex 5. As a result, you will have the following tree with 2 leaves:


It can be proved that it is the minimal number of leaves possible to get.

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
ull pows(ull x1, ll y1, ll mod)
{
	ull r1 = 1;
	x1 = x1 % mod;
	while (y1 > 0)	{
		if (y1 & 1)
			r1 = (r1 * x1) % mod;
		y1 = y1 >> 1;
		x1 = (x1 * x1) % mod;
	}
	return r1;
}
ull f[N];
ull mi(ull x, ll mod) {
	return pows(x, mod - 2, mod);
}
ull ncr(ull x, ll y, ll mod) {
	if (x < y)
		return 0;
	if (y == 0)
		return 1;
	ll ans = f[x] * mi(f[y], mod) % mod;
	ll z = (ans * mi(f[x - y], mod) % mod) % mod;
	return z % mod;
}
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
string ask(ll x, ll y) {
	cout << x + 1 << " " << y + 1;
	string s;
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
ll ans = 0, n;
vll g[200001];
bool dfs(ll u, ll p) {
	ll leaf = 0;
	for (auto it : g[u]) {
		if (it != p)
			leaf += !dfs(it, u);
	}
	ans += max(0ll, leaf - 1);
	return leaf != 0;
}
void solve() {
	cin >> n;
	foi(n - 1) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0, -1);
	cout << ans + 1;
	ans = 0;
	foi(200001) {
		g[i].clear();
	}
}


 
