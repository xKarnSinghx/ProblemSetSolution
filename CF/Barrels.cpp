/*
B. Barrels
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have n barrels lined up in a row, numbered from left to right from one. Initially, the i-th barrel contains ai liters of water.

You can pour water from one barrel to another. In one act of pouring, you can choose two different barrels x and y (the x-th barrel shouldn't be empty) and pour any possible amount of water from barrel x to barrel y (possibly, all water). You may assume that barrels have infinite capacity, so you can pour any amount of water in each of them.

Calculate the maximum possible difference between the maximum and the minimum amount of water in the barrels, if you can pour water at most k times.

Some examples:

if you have four barrels, each containing 5 liters of water, and k=1, you may pour 5 liters from the second barrel into the fourth, so the amounts of water in the barrels are [5,0,5,10], and the difference between the maximum and the minimum is 10;
if all barrels are empty, you can't make any operation, so the difference between the maximum and the minimum amount is still 0.
Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains two integers n and k (1≤k<n≤2⋅105) — the number of barrels and the number of pourings you can make.

The second line contains n integers a1,a2,…,an (0≤ai≤109), where ai is the initial amount of water the i-th barrel has.

It's guaranteed that the total sum of n over test cases doesn't exceed 2⋅105.

Output
For each test case, print the maximum possible difference between the maximum and the minimum amount of water in the barrels, if you can pour water at most k times.

Example
inputCopy
2
4 1
5 5 5 5
3 2
0 0 0
outputCopy
10
0
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
#define graph          vector<vector<int>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair<ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

	int t ; cin >> t;
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
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}
bool isPrime(ll n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll ans = 0;
	forrr(i, n - 1, n - 1 - k)
	ans += a[i];
	cout << ans;

}
