/*
D. Unmerge
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let a and b be two arrays of lengths n and m, respectively, with no elements in common. We can define a new array merge(a,b) of length n+m recursively as follows:

If one of the arrays is empty, the result is the other array. That is, merge(∅,b)=b and merge(a,∅)=a. In particular, merge(∅,∅)=∅.
If both arrays are non-empty, and a1<b1, then merge(a,b)=[a1]+merge([a2,…,an],b). That is, we delete the first element a1 of a, merge the remaining arrays, then add a1 to the beginning of the result.
If both arrays are non-empty, and a1>b1, then merge(a,b)=[b1]+merge(a,[b2,…,bm]). That is, we delete the first element b1 of b, merge the remaining arrays, then add b1 to the beginning of the result.
This algorithm has the nice property that if a and b are sorted, then merge(a,b) will also be sorted. For example, it is used as a subroutine in merge-sort. For this problem, however, we will consider the same procedure acting on non-sorted arrays as well. For example, if a=[3,1] and b=[2,4], then merge(a,b)=[2,3,1,4].

A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

There is a permutation p of length 2n. Determine if there exist two arrays a and b, each of length n and with no elements in common, so that p=merge(a,b).

Input
The first line contains a single integer t (1≤t≤1000)  — the number of test cases. Next 2t lines contain descriptions of test cases.

The first line of each test case contains a single integer n (1≤n≤2000).

The second line of each test case contains 2n integers p1,…,p2n (1≤pi≤2n). It is guaranteed that p is a permutation.

It is guaranteed that the sum of n across all test cases does not exceed 2000.

Output
For each test case, output "YES" if there exist arrays a, b, each of length n and with no common elements, so that p=merge(a,b). Otherwise, output "NO".

Example
inputCopy
6
2
2 3 1 4
2
3 1 2 4
4
3 2 6 1 5 7 8 4
3
1 2 3 4 5 6
4
6 1 3 7 4 5 8 2
6
4 3 2 5 1 11 9 12 8 6 10 7
outputCopy
YES
NO
YES
YES
NO
NO
Note
In the first test case, [2,3,1,4]=merge([3,1],[2,4]).

In the second test case, we can show that [3,1,2,4] is not the merge of two arrays of length 2.

In the third test case, [3,2,6,1,5,7,8,4]=merge([3,2,8,4],[6,1,5,7]).

In the fourth test case, [1,2,3,4,5,6]=merge([1,3,6],[2,4,5]), for example.


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
	vll v;
	ll n;
	cin >> n;
	ll a[5000] = {}, z[2500] = {};
	for (ll i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}
	ll l = 1, r = 1;
	for (ll i = 2; i <= 2 * n; ++i) {
		if (a[i] > a[l]) {
			v.pb(r - l + 1);
			l = r = i;
		} else {
			r = i;
		}
	}
	z[0] = 1;
	for (ll i = 1; i <= n; ++i) {
		z[i] = 0;
	}
	for (ll i = 0; i < v.size(); ++i) {
		for (ll j = n - v[i]; j >= 0; --j) {
			z[j + v[i]] |= z[j];
		}
	}
	if (z[n])
		cout << "YES";
	else
		cout << "NO";
}


