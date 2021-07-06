/*
C. Dreamoon Likes Coloring
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dreamoon likes coloring cells very much.

There is a row of n cells. Initially, all cells are empty (don't contain any color). Cells are numbered from 1 to n.

You are given an integer m and m integers l1,l2,…,lm (1≤li≤n)

Dreamoon will perform m operations.

In i-th operation, Dreamoon will choose a number pi from range [1,n−li+1] (inclusive) and will paint all cells from pi to pi+li−1 (inclusive) in i-th color. Note that cells may be colored more one than once, in this case, cell will have the color from the latest operation.

Dreamoon hopes that after these m operations, all colors will appear at least once and all cells will be colored. Please help Dreamoon to choose pi in each operation to satisfy all constraints.

Input
The first line contains two integers n,m (1≤m≤n≤100000).

The second line contains m integers l1,l2,…,lm (1≤li≤n).

Output
If it's impossible to perform m operations to satisfy all constraints, print "'-1" (without quotes).

Otherwise, print m integers p1,p2,…,pm (1≤pi≤n−li+1), after these m operations, all colors should appear at least once and all cells should be colored.

If there are several possible solutions, you can print any.

Examples
inputCopy
5 3
3 2 2
outputCopy
2 4 1
inputCopy
10 1
1
outputCopy
-1

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
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
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
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
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
void solve() {
	ll n, m;
	cin >> n >> m;
	vll a(m, 0), s(m, 0);
	foi(m) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	s[m - 1] = a[m - 1];
	for (ll i = m - 2; i > -1; i--) {
		s[i] = s[i + 1] + a[i];
	}
	if (s[0] < n) {
		cout << -1;
		return;
	}
	vll p(m, 0);
	foi(m) {
		if (i > n - a[i]) {
			cout << -1;
			return;
		}
		p[i] = max(i + 1, n + 1 - s[i]);
	}
	foi(m) {
		cout << p[i] << " ";
	}
}
// 3 ques cf 1 cc and 6 ccl

