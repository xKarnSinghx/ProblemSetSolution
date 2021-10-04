/*
C. Bakry and Partitioning
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bakry faced a problem, but since he's lazy to solve it, he asks for your help.

You are given a tree of n nodes, the i-th node has value ai assigned to it for each i from 1 to n. As a reminder, a tree on n nodes is a connected graph with n−1 edges.

You want to delete at least 1, but at most k−1 edges from the tree, so that the following condition would hold:

For every connected component calculate the bitwise XOR of the values of the nodes in it. Then, these values have to be the same for all connected components.

Is it possible to achieve this condition?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤5⋅104). Description of the test cases follows.

The first line of each test case contains two integers n and k (2≤k≤n≤105).

The second line of each test case contains n integers a1,a2,...,an (1≤ai≤109).

The i-th of the next n−1 lines contains two integers ui and vi (1≤ui,vi≤n, ui≠vi), which means that there's an edge between nodes ui and vi.

It is guaranteed that the given graph is a tree.

It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

Output
For each test case, you should output a single string. If you can delete the edges according to the conditions written above, output "YES" (without quotes). Otherwise, output "NO" (without quotes).

You can print each letter of "YES" and "NO" in any case (upper or lower).

Example
inputCopy
5
2 2
1 3
1 2
5 5
3 3 3 3 3
1 2
2 3
1 4
4 5
5 2
1 7 2 3 5
1 2
2 3
1 4
4 5
5 3
1 6 4 1 2
1 2
2 3
1 4
4 5
3 3
1 7 4
1 2
2 3
outputCopy
NO
YES
NO
YES
NO
Note
It can be shown that the objection is not achievable for first, third, and fifth test cases.

In the second test case, you can just remove all the edges. There will be 5 connected components, each containing only one node with value 3, so the bitwise XORs will be 3 for all of them.

In the fourth test case, this is the tree:.

You can remove an edge (4,5)

The bitwise XOR of the first component will be, a1⊕a2⊕a3⊕a4=1⊕6⊕4⊕1=2 (where ⊕ denotes the bitwise XOR).

The bitwise XOR of the second component will be, a5=2.

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
int n, k, s = 0, c = 0;
vi a(N / 2, 0);
vector<vi> g(N / 2);
int dfs(int u, int p) {
	int j = 0;
	for (ll v : g[u]) {
		if (v == p)
			continue;
		ll x = dfs(v, u);
		if (x == s)
			c++;
		else
			j ^= x;
	}
	j ^= a[u];
	return j;
}
void solve() {
	a.clear(), g.clear();
	c = 0, s = 0;
	cin >> n >> k;
	foi(n) {
		cin >> a[i];
		s ^= a[i];
	}
	foi(n - 1) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	if (s == 0) {
		cout << "Yes";
		return;
	}
	if (k == 2) {
		cout << "No";
		return;
	}
	//cout << c << " ";
	dfs(0, -1);
	if (c > 1)
		cout << "Yes";
	else
		cout << "No";
	cout << c;
}



