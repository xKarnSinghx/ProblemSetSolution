/*
B. Repainting Street
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a street with n houses in a line, numbered from 1 to n. The house i is initially painted in color ci. The street is considered beautiful if all houses are painted in the same color. Tom, the painter, is in charge of making the street beautiful. Tom's painting capacity is defined by an integer, let's call it k.

On one day, Tom can do the following repainting process that consists of two steps:

He chooses two integers l and r such that 1≤l≤r≤n and r−l+1=k.
For each house i such that l≤i≤r, he can either repaint it with any color he wants, or ignore it and let it keep its current color.
Note that in the same day Tom can use different colors to repaint different houses.

Tom wants to know the minimum number of days needed to repaint the street so that it becomes beautiful.

Input
The first line of input contains a single integer t (1≤t≤104), the number of test cases. Description of test cases follows.

In the first line of a test case description there are two integers n and k (1≤k≤n≤105).

The second line contains n space-separated integers. The i-th of these integers represents ci (1≤ci≤100), the color which house i is initially painted in.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
Print t lines, each with one integer: the minimum number of days Tom needs to make the street beautiful for each test case.

Example
inputCopy
3
10 2
1 1 2 2 1 1 2 2 2 1
7 1
1 2 3 4 5 6 7
10 3
1 3 3 3 3 1 2 1 3 3
outputCopy
3
6
2
Note
In the first test case Tom should paint houses 1 and 2 in the first day in color 2, houses 5 and 6 in the second day in color 2, and the last house in color 2 on the third day.

In the second test case Tom can, for example, spend 6 days to paint houses 1, 2, 4, 5, 6, 7 in color 3.

In the third test case Tom can paint the first house in the first day and houses 6, 7, and 8 in the second day in color 3.


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
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}
bool isPrime(ll n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
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
ll fac(ll n) {
	while (n % 4 == 0) {
		n /= 4;
	}
	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % (i * i) == 0) {
			n /= (i * i);
		}
	}
	return n;
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll ans = 1111111111111, a[n];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= 100; i++)
	{
		ll ans1 = 0;
		for (ll j = 1; j <= n; j++)
			if (a[j] != i)
				j += k - 1, ans1++;
		ans = min(ans, ans1);
	}
	cout << ans;
}


