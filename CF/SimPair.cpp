/*
C. Similar Pairs
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
We call two numbers x and y similar if they have the same parity (the same remainder when divided by 2), or if |x−y|=1. For example, in each of the pairs (2,6), (4,3), (11,7), the numbers are similar to each other, and in the pairs (1,4), (3,12), they are not.

You are given an array a of n (n is even) positive integers. Check if there is such a partition of the array into pairs that each element of the array belongs to exactly one pair and the numbers in each pair are similar to each other.

For example, for the array a=[11,14,16,12], there is a partition into pairs (11,12) and (14,16). The numbers in the first pair are similar because they differ by one, and in the second pair because they are both even.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

Each test case consists of two lines.

The first line contains an even positive integer n (2≤n≤50) — length of array a.

The second line contains n positive integers a1,a2,…,an (1≤ai≤100).

Output
For each test case print:

YES if the such a partition exists,
NO otherwise.
The letters in the words YES and NO can be displayed in any case.

Example
inputCopy
7
4
11 14 16 12
2
1 8
4
1 1 1 1
4
1 2 5 6
2
12 13
6
1 6 3 10 5 8
6
1 12 3 10 5 8
outputCopy
YES
NO
YES
YES
YES
YES
NO
Note
The first test case was explained in the statement.

In the second test case, the two given numbers are not similar.

In the third test case, any partition is suitable.


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
	ll e = 0, o = 0;
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
		if (x % 2)
			o++;
		else
			e++;
	}
	if (o % 2 == 0) {
		cout << "Yes";
		return;
	}
	sort(all(a));
	ll one = 0;
	foi(n - 1) {
		if (abs(a[i] - a[i + 1]) == 1) {
			one++;
		}
	}
	if (o % 2 == e % 2 and one > 0)
		cout << "Yes";
	else
		cout << "No";
}
