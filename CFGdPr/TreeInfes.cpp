/*
C. Tree Infection
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A tree is a connected graph without cycles. A rooted tree has a special vertex called the root. The parent of a vertex v (different from root) is the previous to v vertex on the shortest path from the root to the vertex v. Children of the vertex v are all vertices for which v is the parent.

You are given a rooted tree with n vertices. The vertex 1 is the root. Initially, all vertices are healthy.

Each second you do two operations, the spreading operation and, after that, the injection operation:

Spreading: for each vertex v, if at least one child of v is infected, you can spread the disease by infecting at most one other child of v of your choice.
Injection: you can choose any healthy vertex and infect it.
This process repeats each second until the whole tree is infected. You need to find the minimal number of seconds needed to infect the whole tree.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤2⋅105) — the number of the vertices in the given tree.

The second line of each test case contains n−1 integers p2,p3,…,pn (1≤pi≤n), where pi is the ancestor of the i-th vertex in the tree.

It is guaranteed that the given graph is a tree.

It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

Output
For each test case you should output a single integer — the minimal number of seconds needed to infect the whole tree.

Example
inputCopy
5
7
1 1 1 2 2 4
5
5 5 1 4
2
1
3
3 1
6
1 1 1 1 1
outputCopy
4
4
2
3
4
Note
The image depicts the tree from the first test case during each second.

A vertex is black if it is not infected. A vertex is blue if it is infected by injection during the previous second. A vertex is green if it is infected by spreading during the previous second. A vertex is red if it is infected earlier than the previous second.


Note that you are able to choose which vertices are infected by spreading and by injections.


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
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
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
void solve() {
	ll n;
	cin >> n;
	vll freq(n + 1, 0), a = {1};
	foi(n - 1) {
		ll x;
		cin >> x;
		freq[x]++;
	}
	for (ll i = 1; i <= n; ++i) {
		if (freq[i])
			a.pb(freq[i]);
	}
	sort(rall(a));
	foi(a.size()) {
		a[i] = a[i] + i - a.size();
	}
	ll l = 0, r = n;
	while (l <= r) {
		ll m = (l + r) >> 1, cnt = 0;
		foi(a.size()) {
			cnt += max(0ll, a[i] - m);
		}
		if (cnt <= m)
			r = m - 1;
		else
			l = m + 1;
	}
	cout << l + a.size();
}

