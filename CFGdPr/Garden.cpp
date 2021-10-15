/*
E. Gardener and Tree
time limit per test4 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A tree is an undirected connected graph in which there are no cycles. This problem is about non-rooted trees. A leaf of a tree is a vertex that is connected to at most one vertex.

The gardener Vitaly grew a tree from n vertices. He decided to trim the tree. To do this, he performs a number of operations. In one operation, he removes all leaves of the tree.

Example of a tree.
For example, consider the tree shown in the figure above. The figure below shows the result of applying exactly one operation to the tree.

The result of applying the operation "remove all leaves" to the tree.
Note the special cases of the operation:

applying an operation to an empty tree (of 0 vertices) does not change it;
applying an operation to a tree of one vertex removes this vertex (this vertex is treated as a leaf);
applying an operation to a tree of two vertices removes both vertices (both vertices are treated as leaves).
Vitaly applied k operations sequentially to the tree. How many vertices remain?

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

Each test case is preceded by an empty line.

Each test case consists of several lines. The first line of the test case contains two integers n and k (1≤n≤4⋅105, 1≤k≤2⋅105) — the number of vertices in the tree and the number of operations, respectively. Then n−1 lines follow, each of them contains two integers u and v (1≤u,v≤n, u≠v) which describe a pair of vertices connected by an edge. It is guaranteed that the given graph is a tree and has no loops or multiple edges.

It is guaranteed that the sum of n from all test cases does not exceed 4⋅105.

Output
For each test case output on a separate line a single integer — the number of vertices that remain in the tree after applying k operations.

Example
inputCopy
6

14 1
1 2
2 3
2 4
4 5
4 6
2 7
7 8
8 9
8 10
3 11
3 12
1 13
13 14

2 200000
1 2

3 2
1 2
2 3

5 1
5 1
3 2
2 1
5 4

6 2
5 1
2 5
5 6
4 2
3 4

7 1
4 3
5 1
1 3
6 1
1 7
2 1
outputCopy
7
0
0
3
1
2
Note
The first test case is considered in the statement.

The second test case contains a tree of two vertices. 200000 operations are applied to it. The first one removes all two vertices, the other operations do not change the tree.

In the third test case, a tree of three vertices is given. As a result of the first operation, only 1 vertex remains in it (with the index 2), the second operation makes the tree empty.

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
void solve() {
	ll n, k;
	cin >> n >> k;
	vector<set<ll>> a(n);
	foi(n - 1) {
		ll x, y;
		cin >> x >> y;
		--x; --y;
		a[x].insert(y);
		a[y].insert(x);
	}
	ll b[n];
	queue<ll> q;
	foi(n) {
		if (a[i].size() <= 1) {
			q.push(i);
			b[i] = 1;
		}
	}
	while (!q.empty()) {
		ll c = q.front();
		q.pop();
		for (ll y : a[c]) {
			a[y].erase(c);
			if (a[y].size() == 1) {
				q.push(y);
				b[y] = b[c] + 1;
			}
		}
	}
	ll ans = 0;
	foi(n) {
		if (b[i] > k)
			ans++;
	}
	cout << ans;
}



