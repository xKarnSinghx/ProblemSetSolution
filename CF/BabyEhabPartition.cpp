/*
C. Baby Ehab Partitions Again
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Baby Ehab was toying around with arrays. He has an array a of length n. He defines an array to be good if there's no way to partition it into 2 subsequences such that the sum of the elements in the first is equal to the sum of the elements in the second. Now he wants to remove the minimum number of elements in a so that it becomes a good array. Can you help him?

A sequence b is a subsequence of an array a if b can be obtained from a by deleting some (possibly zero or all) elements. A partitioning of an array is a way to divide it into 2 subsequences such that every element belongs to exactly one subsequence, so you must use all the elements, and you can't share any elements.

Input
The first line contains an integer n (2≤n≤100) — the length of the array a.

The second line contains n integers a1, a2, …, an (1≤ai≤2000) — the elements of the array a.

Output
The first line should contain the minimum number of elements you need to remove.

The second line should contain the indices of the elements you're removing, separated by spaces.

We can show that an answer always exists. If there are multiple solutions, you can print any.

Examples
inputCopy
4
6 3 9 12
outputCopy
1
2
inputCopy
2
1 2
outputCopy
0
Note
In the first example, you can partition the array into [6,9] and [3,12], so you must remove at least 1 element. Removing 3 is sufficient.

In the second example, the array is already good, so you don't need to remove any elements.

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
void solve() {
	ll n;
	cin >> n;
	ll a[n], s = 0;
	foi(n) {
		cin >> a[i];
		s += a[i];
	}
	if (s % 2) {
		cout << 0;
		return;
	}
	ll sum[200001] = {};
	foi(n) {
		for (ll j = s / 2; j >= a[i]; j-- ) {
			sum[j] = max(sum[j], sum[j - a[i]] + a[i]);
		}
	}
	if (sum[s / 2] != s / 2) {
		cout << 0;
		return;
	}
	cout << 1 << endl;
	foi(n) {
		if ((s - a[i]) % 2 or sum[(s - a[i]) / 2] != (s - a[i]) / 2) {
			cout << i + 1;
			return;
		}

	}

}


 
