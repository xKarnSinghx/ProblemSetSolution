/*
D. Armchairs
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
There are n armchairs, numbered from 1 to n from left to right. Some armchairs are occupied by people (at most one person per armchair), others are not. The number of occupied armchairs is not greater than n2.

For some reason, you would like to tell people to move from their armchairs to some other ones. If the i-th armchair is occupied by someone and the j-th armchair is not, you can tell the person sitting in the i-th armchair to move to the j-th armchair. The time it takes a person to move from the i-th armchair to the j-th one is |i−j| minutes. You may perform this operation any number of times, but these operations must be done sequentially, i. e. you cannot tell a person to move until the person you asked to move in the last operation has finished moving to their destination armchair.

You want to achieve the following situation: every seat that was initially occupied must be free. What is the minimum time you need to do it?

Input
The first line contains one integer n (2≤n≤5000) — the number of armchairs.

The second line contains n integers a1,a2,…,an (0≤ai≤1). ai=1 means that the i-th armchair is initially occupied, ai=0 means that it is initially free. The number of occupied armchairs is at most n2.

Output
Print one integer — the minimum number of minutes you have to spend to achieve the following situation: every seat that was initially occupied must be free.

Examples
inputCopy
7
1 0 0 1 0 0 1
outputCopy
3
inputCopy
6
1 1 1 0 0 0
outputCopy
9
inputCopy
5
0 0 0 0 0
outputCopy
0
Note
In the first test, you can perform the following sequence:

ask a person to move from armchair 1 to armchair 2, it takes 1 minute;
ask a person to move from armchair 7 to armchair 6, it takes 1 minute;
ask a person to move from armchair 4 to armchair 5, it takes 1 minute.
In the second test, you can perform the following sequence:

ask a person to move from armchair 1 to armchair 4, it takes 3 minutes;
ask a person to move from armchair 2 to armchair 6, it takes 4 minutes;
ask a person to move from armchair 4 to armchair 5, it takes 1 minute;
ask a person to move from armchair 3 to armchair 4, it takes 1 minute.
In the third test, no seat is occupied so your goal is achieved instantly.*/
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
	//while (t--)
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
	ll a[n];
	vll idx;
	foi(n) {
		cin >> a[i];
		if (a[i])
			idx.pb(i + 1);
	}
	graph ans(n + 1, vll(idx.size() + 1, MOD));
	ans[0][0] = 0;
	foi(n) {
		foj(idx.size() + 1) {
			if (ans[i][j] == MOD)
				continue;
			ans[i + 1][j] = min(ans[i + 1][j], ans[i][j]);
			if (j < idx.size() and a[i] == 0) {
				ans[i + 1][j + 1] = min(ans[i + 1][j + 1], ans[i][j] + abs(idx[j] - i - 1));
			}
		}
	}
	cout << ans[n][idx.size()];
	ans.clear(), idx.clear();
}



