/*
D. Minimum Euler Cycle
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a complete directed graph Kn with n vertices: each pair of vertices u≠v in Kn have both directed edges (u,v) and (v,u); there are no self-loops.

You should find such a cycle in Kn that visits every directed edge exactly once (allowing for revisiting vertices).

We can write such cycle as a list of n(n−1)+1 vertices v1,v2,v3,…,vn(n−1)−1,vn(n−1),vn(n−1)+1=v1 — a visiting order, where each (vi,vi+1) occurs exactly once.

Find the lexicographically smallest such cycle. It's not hard to prove that the cycle always exists.

Since the answer can be too large print its [l,r] segment, in other words, vl,vl+1,…,vr.

Input
The first line contains the single integer T (1≤T≤100) — the number of test cases.

Next T lines contain test cases — one per line. The first and only line of each test case contains three integers n, l and r (2≤n≤105, 1≤l≤r≤n(n−1)+1, r−l+1≤105) — the number of vertices in Kn, and segment of the cycle to print.

It's guaranteed that the total sum of n doesn't exceed 105 and the total sum of r−l+1 doesn't exceed 105.

Output
For each test case print the segment vl,vl+1,…,vr of the lexicographically smallest cycle that visits every edge exactly once.

Example
inputCopy
3
2 1 3
3 3 6
99995 9998900031 9998900031
outputCopy
1 2 1 
1 3 2 3 
1 
Note
In the second test case, the lexicographically minimum cycle looks like: 1,2,1,3,2,3,1.

In the third test case, it's quite obvious that the cycle should start and end in vertex 1.*/
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
ll s = 0, rem = 1;
ll cal(ll a, ll n) {
	if (a > n * (n - 1))
		return 1;
	while (a > s + (n - rem) * 2) {
		s += (n - rem) * 2;
		rem++;
	}
	if (a % 2)
		return rem;
	else
		return rem + (a - s) / 2;
}
void solve() {
	ll n, l, r;
	cin >> n >> l >> r;
	for (ll i = l; i <= r; i++) {
		cout << cal(i, n) << " ";
	}
	s = 0, rem = 1;
}
 
