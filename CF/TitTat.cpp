/*
A. Tit for Tat
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Given an array a of length n, you can do at most k operations of the following type on it:

choose 2 different elements in the array, add 1 to the first, and subtract 1 from the second. However, all the elements of a have to remain non-negative after this operation.
What is lexicographically the smallest array you can obtain?

An array x is lexicographically smaller than an array y if there exists an index i such that xi<yi, and xj=yj for all 1≤j<i. Less formally, at the first index i in which they differ, xi<yi.

Input
The first line contains an integer t (1≤t≤20) – the number of test cases you need to solve.

The first line of each test case contains 2 integers n and k (2≤n≤100, 1≤k≤10000) — the number of elements in the array and the maximum number of operations you can make.

The second line contains n space-separated integers a1, a2, …, an (0≤ai≤100) — the elements of the array a.

Output
For each test case, print the lexicographically smallest array you can obtain after at most k operations.

Example
inputCopy
2
3 1
3 1 4
2 10
1 0
outputCopy
2 1 5 
0 1 
Note
In the second test case, we start by subtracting 1 from the first element and adding 1 to the second. Then, we can't get any lexicographically smaller arrays, because we can't make any of the elements negative.


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
typedef pair<pll, ll>      plll;
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
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
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
void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n], s = k;
	foi(n) {
		cin >> a[i];
	}
	foi(n - 1) {
		if (a[i] >= k and k > 0) {
			a[i] -= k;
			k = 0;
		}
		else {
			k -= a[i];
			a[i] = 0;
		}
		if (k == 0)
			break;
	}
	a[n - 1] += s - k;
	foi(n) {
		cout << a[i] << " ";
	}
}

 
