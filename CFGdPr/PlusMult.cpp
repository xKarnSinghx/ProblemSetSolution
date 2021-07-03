/*
B. Plus and Multiply
time limit per test3 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
There is an infinite set generated as follows:

1 is in this set.
If x is in this set, x⋅a and x+b both are in this set.
For example, when a=3 and b=6, the five smallest elements of the set are:

1,
3 (1 is in this set, so 1⋅a=3 is in this set),
7 (1 is in this set, so 1+b=7 is in this set),
9 (3 is in this set, so 3⋅a=9 is in this set),
13 (7 is in this set, so 7+b=13 is in this set).
Given positive integers a, b, n, determine if n is in this set.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤105) — the number of test cases. The description of the test cases follows.

The only line describing each test case contains three integers n, a, b (1≤n,a,b≤109) separated by a single space.

Output
For each test case, print "Yes" if n is in this set, and "No" otherwise. You can print each letter in any case.

Example
inputCopy
5
24 3 5
10 3 6
2345 1 4
19260817 394 485
19260817 233 264
outputCopy
Yes
No
Yes
No
Yes
Note
In the first test case, 24 is generated as follows:

1 is in this set, so 3 and 6 are in this set;
3 is in this set, so 9 and 8 are in this set;
8 is in this set, so 24 and 13 are in this set.
Thus we can see 24 is in this set.

The five smallest elements of the set in the second test case is described in statements. We can see that 10 isn't among them.


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
	ll n, a, b;
	cin >> n >> a >> b;
	if (a == 1) {
		n--;
		if (n % b == 0) {
			cout << "Yes";
		}
		else
			cout << "No";
		return;
	}
	ll ans = 1;
	while (ans <= n) {
		if ((n - ans) % b == 0) {
			cout << "Yes";
			return;
		}
		ans *= a;
	}
	cout << "No";
}
 
