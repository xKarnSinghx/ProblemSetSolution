/*
D2. Mocha and Diana (Hard Version)
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is the hard version of the problem. The only difference between the two versions is the constraint on n. You can make hacks only if all versions of the problem are solved.

A forest is an undirected graph without cycles (not necessarily connected).

Mocha and Diana are friends in Zhijiang, both of them have a forest with nodes numbered from 1 to n, and they would like to add edges to their forests such that:

After adding edges, both of their graphs are still forests.
They add the same edges. That is, if an edge (u,v) is added to Mocha's forest, then an edge (u,v) is added to Diana's forest, and vice versa.
Mocha and Diana want to know the maximum number of edges they can add, and which edges to add.

Input
The first line contains three integers n, m1 and m2 (1≤n≤105, 0≤m1,m2<n) — the number of nodes and the number of initial edges in Mocha's forest and Diana's forest.

Each of the next m1 lines contains two integers u and v (1≤u,v≤n, u≠v) — the edges in Mocha's forest.

Each of the next m2 lines contains two integers u and v (1≤u,v≤n, u≠v) — the edges in Diana's forest.

Output
The first line contains only one integer h, the maximum number of edges Mocha and Diana can add.

Each of the next h lines contains two integers u and v (1≤u,v≤n, u≠v) — the edge you add each time.

If there are multiple correct answers, you can print any one of them.

Examples
inputCopy
3 2 2
1 2
2 3
1 2
1 3
outputCopy
0
inputCopy
5 3 2
5 4
2 1
4 3
4 3
1 4
outputCopy
1
2 4
inputCopy
8 1 2
1 7
2 6
1 5
outputCopy
5
5 2
2 3
3 4
4 7
6 8
Note
In the first example, we cannot add any edge.

In the second example, the initial forests are as follows.



We can add an edge (2,4).


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
	/*foi(N) {
		if (i == 0) {
			f[i] = 1;
			continue;
		}
		f[i] = (f[i - 1] * i) % MOD;
	}*/
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
class DisjointSet {
public:

	vector<int> parent;

	DisjointSet(int n): parent(n) {
		for (int i = 0; i < n; i++) parent[i] = i;
	}

	void join(int a, int b) {
		parent[find(b)] = find(a);
	}

	int find(int a) {
		return a == parent[a] ? a : parent[a] = find(parent[a]);
	}

	bool check(int a, int b) {
		return find(a) == find(b);
	}
};
void solve() {
	ll n, m1, m2;
	cin >> n >> m1 >> m2;
	DisjointSet obj(n), obj1(n);
	foi(m1) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		obj.join(y, x);
	}
	foi(m2) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		obj1.join(y, x);
	}
	vpll ans;
	foi(n) {
		for (ll j = i + 1; j < n; j++) {
			if (obj1.find(i) != obj1.find(j) and obj.find(i) != obj.find(j)) {
				obj1.join(i, j);
				obj.join(i, j);
				ans.pb(mp(i + 1, j + 1));
			}
		}
	}
	cout << ans.size() << endl;
	foi(ans.size()) {
		cout << ans[i].ff << " " << ans[i].ss << endl;
	}
}


