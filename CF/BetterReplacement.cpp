/*
B. Partial Replacement
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a number k and a string s of length n, consisting of the characters '.' and '*'. You want to replace some of the '*' characters with 'x' characters so that the following conditions are met:

The first character '*' in the original string should be replaced with 'x';
The last character '*' in the original string should be replaced with 'x';
The distance between two neighboring replaced characters 'x' must not exceed k (more formally, if you replaced characters at positions i and j (i<j) and at positions [i+1,j−1] there is no "x" symbol, then j−i must be no more than k).
For example, if n=7, s=.**.*** and k=3, then the following strings will satisfy the conditions above:

.xx.*xx;
.x*.x*x;
.xx.xxx.
But, for example, the following strings will not meet the conditions:
.**.*xx (the first character '*' should be replaced with 'x');
.x*.xx* (the last character '*' should be replaced with 'x');
.x*.*xx (the distance between characters at positions 2 and 6 is greater than k=3).
Given n, k, and s, find the minimum number of '*' characters that must be replaced with 'x' in order to meet the above conditions.

Input
The first line contains one integer t (1≤t≤500). Then t test cases follow.

The first line of each test case contains two integers n and k (1≤k≤n≤50).

The second line of each test case contains a string s of length n, consisting of the characters '.' and '*'.

It is guaranteed that there is at least one '*' in the string s.

It is guaranteed that the distance between any two neighboring '*' characters does not exceed k.

Output
For each test case output the minimum number of '*' characters that must be replaced with 'x' characters in order to satisfy the conditions above.

Example
inputCopy
5
7 3
.**.***
5 1
..*..
5 2
*.*.*
3 2
*.*
1 1
*
outputCopy
3
1
3
2
1

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
	string s;
	cin >> s;
	ll ans = 0, x = 0, y = n - 1;
	foi(n) {
		if (s[i] == '*') {
			x = i;
			break;
		}
	}
	forrr(i, n - 1, -1) {
		if (s[i] == '*') {
			y = i;
			break;
		}
	}
	if (x == y)
		ans = 1;
	else
		ans = 2;
	forrrr(i, x + k, y, k) {
		while (s[i] == '.')
			i--;
		ans++;
	}
	cout << ans ;


}


