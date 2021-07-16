/*
D. Count the Arrays
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Your task is to calculate the number of arrays such that:

each array contains n elements;
each element is an integer from 1 to m;
for each array, there is exactly one pair of equal elements;
for each array a, there exists an index i such that the array is strictly ascending before the i-th element and strictly descending after it (formally, it means that aj<aj+1, if j<i, and aj>aj+1, if j≥i).
Input
The first line contains two integers n and m (2≤n≤m≤2⋅105).

Output
Print one integer — the number of arrays that meet all of the aforementioned conditions, taken modulo 998244353.

Examples
inputCopy
3 4
outputCopy
6
inputCopy
3 5
outputCopy
10
inputCopy
42 1337
outputCopy
806066790
inputCopy
100000 200000
outputCopy
707899035
Note
The arrays in the first example are:

[1,2,1];
[1,3,1];
[1,4,1];
[2,3,2];
[2,4,2];
[3,4,3].

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
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
void solve();
const ll N = 200010;
ull pows(ull x1, ll y1, ll modx)
{
	ull r1 = 1;
	x1 = x1 % modx;
	while (y1 > 0)	{
		if (y1 & 1)
			r1 = (r1 * x1) % modx;
		y1 = y1 >> 1;
		x1 = (x1 * x1) % modx;
	}
	return r1;
}
ull f[N];
ull mi(ull x, ll modx) {
	return pows(x, modx - 2, modx);
}
ull ncr(ull x, ll y, ll modx) {
	if (x < y)
		return 0;
	if (y == 0)
		return 1;
	ll ans = f[x] * mi(f[y], modx) % modx;
	ll z = (ans * mi(f[x - y], modx) % modx) % modx;
	return z % modx;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
//	ll t ; cin >> t;
	foi(N) {
		if (i == 0) {
			f[i] = 1;
			continue;
		}
		f[i] = (f[i - 1] * i) % modx;
	}
//	while (t--)
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
	ll ans = 0;
	if (n == 2) {
		cout << ans;
		return;
	}
	ans = ncr(m, n - 1, modx);
	ans %= modx;
	ans *= (n - 2);
	ans %= modx;
	foi(n - 3) {
		ans *= 2;
		ans %= modx;
	}
	cout << ans;
}

