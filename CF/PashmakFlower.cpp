/*
B. Pashmak and Flowers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Pashmak decided to give Parmida a pair of flowers from the garden. There are n flowers in the garden and the i-th of them has a beauty number bi. Parmida is a very strange girl so she doesn't want to have the two most beautiful flowers necessarily. She wants to have those pairs of flowers that their beauty difference is maximal possible!

Your task is to write a program which calculates two things:

The maximum beauty difference of flowers that Pashmak can give to Parmida.
The number of ways that Pashmak can pick the flowers. Two ways are considered different if and only if there is at least one flower that is chosen in the first way and not chosen in the second way.
Input
The first line of the input contains n (2 ≤ n ≤ 2·105). In the next line there are n space-separated integers b1, b2, ..., bn (1 ≤ bi ≤ 109).

Output
The only line of output should contain two integers. The maximum beauty difference and the number of ways this may happen, respectively.

Examples
inputCopy
2
1 2
outputCopy
1 1
inputCopy
3
1 4 5
outputCopy
4 1
inputCopy
5
3 1 2 3 1
outputCopy
2 4
Note
In the third sample the maximum beauty difference is 2 and there are 4 ways to do this:

choosing the first and the second flowers;
choosing the first and the fifth flowers;
choosing the fourth and the second flowers;
choosing the fourth and the fifth flowers.

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

	
		solve();
		

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
void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];
	sort(a, a + n);
	ll s = 1, s1 = 1;
	ll ans = a[n - 1] - a[0];
	for (ll i = 1; i < n - 1; i++) {
		if (a[i] == a[0])
			s++;
		else if (a[i] == a[n - 1])
			s1++;

	}
	if (ans)
		cout << ans << " " << s1*s;
	else
		cout << ans << " " << n*(n - 1) / 2;

}
