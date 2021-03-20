/*
F. Equalize the Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp was gifted an array a of length n. Polycarp considers an array beautiful if there exists a number C, such that each number in the array occurs either zero or C times. Polycarp wants to remove some elements from the array a to make it beautiful.

For example, if n=6 and a=[1,3,2,1,4,2], then the following options are possible to make the array a array beautiful:

Polycarp removes elements at positions 2 and 5, array a becomes equal to [1,2,1,2];
Polycarp removes elements at positions 1 and 6, array a becomes equal to [3,2,1,4];
Polycarp removes elements at positions 1,2 and 6, array a becomes equal to [2,1,4];
Help Polycarp determine the minimum number of elements to remove from the array a to make it beautiful.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The first line of each test case consists of one integer n (1≤n≤2⋅105) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — array a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output one integer — the minimum number of elements that Polycarp has to remove from the array a to make it beautiful.

Example
inputCopy
3
6
1 3 2 1 4 2
4
100 100 4 100
8
1 2 3 3 3 2 6 6
outputCopy
2
1
2

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
	ll n;
	cin >> n;
	ll ans = n;
	mll mp, gr;
	foi(n) {
		ll x;
		cin >> x;
		mp[x]++, gr[mp[x]]++;
		cout << mp[x] << " " << gr[mp[x]] << " ";
		ans = min(ans, n - mp[x] * gr[mp[x]]);
	}
	cout << ans;
}
