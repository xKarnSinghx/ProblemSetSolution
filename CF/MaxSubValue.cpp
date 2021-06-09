/*
E. Maximum Subsequence Value
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ridhiman challenged Ashish to find the maximum valued subsequence of an array a of size n consisting of positive integers.

The value of a non-empty subsequence of k elements of a is defined as ∑2i over all integers i≥0 such that at least max(1,k−2) elements of the subsequence have the i-th bit set in their binary representation (value x has the i-th bit set in its binary representation if ⌊x2i⌋mod2 is equal to 1).

Recall that b is a subsequence of a, if b can be obtained by deleting some(possibly zero) elements from a.

Help Ashish find the maximum value he can get by choosing some subsequence of a.

Input
The first line of the input consists of a single integer n (1≤n≤500) — the size of a.

The next line consists of n space-separated integers — the elements of the array (1≤ai≤1018).

Output
Print a single integer — the maximum value Ashish can get by choosing some subsequence of a.

Examples
inputCopy
3
2 1 3
outputCopy
3
inputCopy
3
3 1 4
outputCopy
7
inputCopy
1
1
outputCopy
1
inputCopy
4
7 7 1 1
outputCopy
7
Note
For the first test case, Ashish can pick the subsequence {2,3} of size 2. The binary representation of 2 is 10 and that of 3 is 11. Since max(k−2,1) is equal to 1, the value of the subsequence is 20+21 (both 2 and 3 have 1-st bit set in their binary representation and 3 has 0-th bit set in its binary representation). Note that he could also pick the subsequence {3} or {2,1,3}.

For the second test case, Ashish can pick the subsequence {3,4} with value 7.

For the third test case, Ashish can pick the subsequence {1} with value 1.

For the fourth test case, Ashish can pick the subsequence {7,7} with value 7.*/
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
//	ll t ; cin >> t;
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
	cin >> n ;
	ll a[n];
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	ll ans = 0;
	foi(n) {
		for (ll j = i; j < n; j++) {
			for (ll k = j; k < n; k++) {
				ans = max(ans, a[i] | a[j] | a[k]) ;
			}
		}
	}
	cout << ans;
}
