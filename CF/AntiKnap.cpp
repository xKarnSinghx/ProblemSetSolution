/*
A. Anti-knapsack
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two integers n and k. You are asked to choose maximum number of distinct integers from 1 to n so that there is no subset of chosen numbers with sum equal to k.

A subset of a set is a set that can be obtained from initial one by removing some (possibly all or none) elements of it.

Input
The first line contains the number of test cases T (1≤T≤100).

Each of the next T lines contains two integers n and k (1≤k≤n≤1000) — the description of test cases.

Output
For each test case output two lines. In the first line output a single integer m — the number of chosen integers.

In the second line output m distinct integers from 1 to n — the chosen numbers.

If there are multiple answers, print any. You can print the numbers in any order.

Example
inputCopy
3
3 2
5 3
1 1
outputCopy
2
3 1 
3
4 5 2 
0
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

	ll n, k;
	cin >> n >> k;
	ll ans = 0;

	ans = n - k ;
	if (k % 2 == 0)
	{
		ans += k - k / 2;
	}
	else
	{
		ans += k - k / 2 - 1;
	}
	cout << ans << endl;
	for (int i = k + 1; i <= n; ++i)
	{
		cout << i << " ";
	}
	if (k % 2 == 0)
	{
		for (ll i = k / 2; i < k; i++)
			cout << i << " ";
	}
	else
	{
		for (ll i = k / 2 + 1; i < k; i++)
			cout << i << " ";
	}


}


 
