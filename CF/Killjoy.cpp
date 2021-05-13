/*
C. Killjoy
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A new agent called Killjoy invented a virus COVID-2069 that infects accounts on Codeforces. Each account has a rating, described by an integer (it can possibly be negative or very large).

Killjoy's account is already infected and has a rating equal to x. Its rating is constant. There are n accounts except hers, numbered from 1 to n. The i-th account's initial rating is ai. Any infected account (initially the only infected account is Killjoy's) instantly infects any uninfected account if their ratings are equal. This can happen at the beginning (before any rating changes) and after each contest. If an account is infected, it can not be healed.

Contests are regularly held on Codeforces. In each contest, any of these n accounts (including infected ones) can participate. Killjoy can't participate. After each contest ratings are changed this way: each participant's rating is changed by an integer, but the sum of all changes must be equal to zero. New ratings can be any integer.

Find out the minimal number of contests needed to infect all accounts. You can choose which accounts will participate in each contest and how the ratings will change.

It can be proven that all accounts can be infected in some finite number of contests.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases. The next 2t lines contain the descriptions of all test cases.

The first line of each test case contains two integers n and x (2≤n≤103, −4000≤x≤4000) — the number of accounts on Codeforces and the rating of Killjoy's account.

The second line of each test case contains n integers a1,a2,…,an (−4000≤ai≤4000) — the ratings of other accounts.

Output
For each test case output the minimal number of contests needed to infect all accounts.

Example
inputCopy
3
2 69
68 70
6 4
4 4 4 4 4 4
9 38
-21 83 50 -59 -77 15 -71 -78 20
outputCopy
1
0
2
Note
In the first test case it's possible to make all ratings equal to 69. First account's rating will increase by 1, and second account's rating will decrease by 1, so the sum of all changes will be equal to zero.

In the second test case all accounts will be instantly infected, because all ratings (including Killjoy's account's rating) are equal to 4.

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
void solve() {
	ll n, x;
	cin >> n >> x;
	ll a[n];
	foi(n)
	cin >> a[i];
	ll s = 0, c = 0, f = 0;
	foi(n) {
		if (a[i] == x)
			c++, f = 1;
		s += x - a[i];
	}
	if (c == n) {
		cout << 0;
		return;
	}
	if (s == 0 or f == 1)
		cout << 1;
	else
		cout << 2;
}
