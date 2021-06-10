/*
A. Most Unstable Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two integers n and m. You have to construct the array a of length n consisting of non-negative integers (i.e. integers greater than or equal to zero) such that the sum of elements of this array is exactly m and the value ∑i=1n−1|ai−ai+1| is the maximum possible. Recall that |x| is the absolute value of x.

In other words, you have to maximize the sum of absolute differences between adjacent (consecutive) elements. For example, if the array a=[1,3,2,5,5,0] then the value above for this array is |1−3|+|3−2|+|2−5|+|5−5|+|5−0|=2+1+3+0+5=11. Note that this example doesn't show the optimal answer but it shows how the required value for some array is calculated.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The only line of the test case contains two integers n and m (1≤n,m≤109) — the length of the array and its sum correspondingly.

Output
For each test case, print the answer — the maximum possible value of ∑i=1n−1|ai−ai+1| for the array a consisting of n non-negative integers with the sum m.

Example
inputCopy
5
1 100
2 2
5 5
2 1000000000
1000000000 1000000000
outputCopy
0
2
10
1000000000
2000000000
Note
In the first test case of the example, the only possible array is [100] and the answer is obviously 0.

In the second test case of the example, one of the possible arrays is [2,0] and the answer is |2−0|=2.

In the third test case of the example, one of the possible arrays is [0,2,0,3,0] and the answer is |0−2|+|2−0|+|0−3|+|3−0|=10.


Co*/
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
struct cmp {
	bool operator() (const pll &a, const pll &b) const {
		ll fir = a.ss - a.ff + 1;
		ll sec = b.ss - b.ff + 1;
		if (fir == sec)
			return a.ff < b.ff;
		return fir > sec;
	}
};
void solve() {
	ll n, x;
	cin >> n >> x;
	if (n == 1) {
		cout << 0;
		return;
	}
	if (n == 2) {
		cout << x;
		return;
	}
	cout << 2 * x;

}
