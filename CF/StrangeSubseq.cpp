/*
B. Sifid and Strange Subsequences
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A sequence (b1,b2,…,bk) is called strange, if the absolute difference between any pair of its elements is greater than or equal to the maximum element in the sequence. Formally speaking, it's strange if for every pair (i,j) with 1≤i<j≤k, we have |ai−aj|≥MAX, where MAX is the largest element of the sequence. In particular, any sequence of length at most 1 is strange.

For example, the sequences (−2021,−1,−1,−1) and (−1,0,1) are strange, but (3,0,1) is not, because |0−1|<3.

Sifid has an array a of n integers. Sifid likes everything big, so among all the strange subsequences of a, he wants to find the length of the longest one. Can you help him?

A sequence c is a subsequence of an array d if c can be obtained from d by deletion of several (possibly, zero or all) elements.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤105) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109) — the elements of the array a.

It is guaranteed that the sum of n over all test cases doesn't exceed 105.

Output
For each test case output a single integer — the length of the longest strange subsequence of a.

Example
inputCopy
6
4
-1 -2 0 0
7
-3 4 -2 0 -4 6 1
5
0 5 -3 2 -5
3
2 3 1
4
-3 0 2 0
6
-3 -2 -1 1 1 1
outputCopy
4
5
4
1
3
4
Note
In the first test case, one of the longest strange subsequences is (a1,a2,a3,a4)
In the second test case, one of the longest strange subsequences is (a1,a3,a4,a5,a7).

In the third test case, one of the longest strange subsequences is (a1,a3,a4,a5).

In the fourth test case, one of the longest strange subsequences is (a2).

In the fifth test case, one of the longest strange subsequences is (a1,a2,a4).


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
typedef pair< ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
void solve();
const ll N = 1e6 + 1;
ll pairx[N];
ll dp[N][2];
const ll modx = 998244353;
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
void solve() {
	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];
	sort(a, a + n);
	mll m;
	ll mx = -111111111111, cnt = 0, f = 1111111111111, mx1 = 11111111111, dif = 111111111111;
	foi(n) {
		if (a[i] <= 0) {
			cnt++;
			mx1 = mx;
			mx = max(mx, a[i]);
			dif = min(dif, abs(mx1 - mx));
		}
		else {
			f = min(f, a[i]);
		}
	}
	if (dif >= f and f > 0)
		cnt++;
	cout << cnt;
}


