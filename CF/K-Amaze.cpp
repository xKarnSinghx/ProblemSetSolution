/*
C. k-Amazing Numbers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a consisting of n integers numbered from 1 to n.

Let's define the k-amazing number of the array as the minimum number that occurs in all of the subsegments of the array having length k (recall that a subsegment of a of length k is a contiguous part of a containing exactly k elements). If there is no integer occuring in all subsegments of length k for some value of k, then the k-amazing number is −1.

For each k from 1 to n calculate the k-amazing number of the array a.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The first line of each test case contains one integer n (1≤n≤3⋅105) — the number of elements in the array. The second line contains n integers a1,a2,…,an (1≤ai≤n) — the elements of the array.

It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

Output
For each test case print n integers, where the i-th integer is equal to the i-amazing number of the array.

Example
inputCopy
3
5
1 2 3 4 5
5
4 4 4 4 2
6
1 3 1 5 3 1
outputCopy
-1 -1 3 2 1 
-1 4 4 4 2 
-1 -1 1 1 1 1 
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
vector<int> G[100005];
ll b[100005], f;
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

void solve()
{
	ll n;
	cin >> n ;
	vll a(n + 1);
	vll big(n + 1, 0), last(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		big[a[i]] = max(big[a[i]], i - last[a[i]]);
		last[a[i]] = i;
	}
	vll ans(n + 1, -1);
	for (ll x = 1; x <= n; x++) {
		big[x] = max(big[x], n - last[x] + 1);
		for (ll i = big [x]; i <= n && ans [i] == -1; ++i) {
			ans[i] = x;
		}
	}
	for (ll i = 1; i <= n; ++i)
		cout << ans [i] << ' ';

}
 
