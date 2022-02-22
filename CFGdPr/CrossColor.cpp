/*
D. Cross Coloring
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a sheet of paper that can be represented with a grid of size n×m: n rows and m columns of cells. All cells are colored in white initially.

q operations have been applied to the sheet. The i-th of them can be described as follows:

xi yi — choose one of k non-white colors and color the entire row xi and the entire column yi in it. The new color is applied to each cell, regardless of whether the cell was colored before the operation.
The sheet after applying all q operations is called a coloring. Two colorings are different if there exists at least one cell that is colored in different colors.

How many different colorings are there? Print the number modulo 998244353.

Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.

The first line of the testcase contains four integers n,m,k and q (1≤n,m,k,q≤2⋅105) — the size of the sheet, the number of non-white colors and the number of operations.

The i-th of the following q lines contains a description of the i-th operation — two integers xi and yi (1≤xi≤n; 1≤yi≤m) — the row and the column the operation is applied to.

The sum of q over all testcases doesn't exceed 2⋅105.

Output
For each testcase, print a single integer — the number of different colorings modulo 998244353.

Example
inputCopy
2
1 1 3 2
1 1
1 1
2 2 2 3
2 1
1 1
2 2
outputCopy
3
4

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
const ll N = 1000010;
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
	ll n, m, k, q;
	cin >> n >> m >> k >> q;
	set<ll> r, c;
	set<pll>s;
	vpll a;
	foi(q) {
		ll x, y;
		cin >> x >> y;
		a.pb({x, y});
	}
	reverse(all(a));
	foi(q) {
		if (r.size() == n or c.size() == m) {
			cout << binpow(k, s.size(), mod);
			return;
		}
		if (r.find(a[i].ff) == r.end() or c.find(a[i].ss) == c.end()) {
			s.insert({a[i].ff, a[i].ss});
		}
		r.insert(a[i].ff), c.insert(a[i].ss);
	}
	cout << binpow(k, s.size(), mod);

}

