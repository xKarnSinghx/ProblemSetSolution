/*
C. Chef Monocarp
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Chef Monocarp has just put n dishes into an oven. He knows that the i-th dish has its optimal cooking time equal to ti minutes.

At any positive integer minute T Monocarp can put no more than one dish out of the oven. If the i-th dish is put out at some minute T, then its unpleasant value is |T−ti| — the absolute difference between T and ti. Once the dish is out of the oven, it can't go back in.

Monocarp should put all the dishes out of the oven. What is the minimum total unpleasant value Monocarp can obtain?

Input
The first line contains a single integer q (1≤q≤200) — the number of testcases.

Then q testcases follow.

The first line of the testcase contains a single integer n (1≤n≤200) — the number of dishes in the oven.

The second line of the testcase contains n integers t1,t2,…,tn (1≤ti≤n) — the optimal cooking time for each dish.

The sum of n over all q testcases doesn't exceed 200.

Output
Print a single integer for each testcase — the minimum total unpleasant value Monocarp can obtain when he puts out all the dishes out of the oven. Remember that Monocarp can only put the dishes out at positive integer minutes and no more than one dish at any minute.

Example
inputCopy
6
6
4 2 4 4 5 2
7
7 7 7 7 7 7 7
1
1
5
5 1 2 4 3
4
1 4 4 4
21
21 8 1 4 1 5 21 1 8 21 11 21 11 3 12 8 19 15 9 11 13
outputCopy
4
12
0
0
2
21
Note
In the first example Monocarp can put out the dishes at minutes 3,1,5,4,6,2. That way the total unpleasant value will be |4−3|+|2−1|+|4−5|+|4−4|+|6−5|+|2−2|=4.

In the second example Monocarp can put out the dishes at minutes 4,5,6,7,8,9,10.

In the third example Monocarp can put out the dish at minute 1.

In the fourth example Monocarp can put out the dishes at minutes 5,1,2,4,3.

In the fifth example Monocarp can put out the dishes at minutes 1,3,4,5.


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
	ll n;
	cin >> n;
	vll a(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	ll dp[n + 1][n + (n + 1) / 2];
	foi(n + 1) {
		foj(n + (n + 1) / 2) {
			dp[i][j] = 1111111111;
		}
	}
	dp[0][0] = 0;
	sort(all(a));
	foi(n + 1) {
		foj(n + (n + 1) / 2 - 1) {
			dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
			if (i < n) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(a[i] - j - 1));
			}
		}
	}
	cout << dp[n][n + (n + 1) / 2 - 1];
}
 
