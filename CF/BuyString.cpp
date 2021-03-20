/*
A. Buy the String
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given four integers n, c0, c1 and h and a binary string s of length n.

A binary string is a string consisting of characters 0 and 1.

You can change any character of the string s (the string should be still binary after the change). You should pay h coins for each change.

After some changes (possibly zero) you want to buy the string. To buy the string you should buy all its characters. To buy the character 0 you should pay c0 coins, to buy the character 1 you should pay c1 coins.

Find the minimum number of coins needed to buy the string.

Input
The first line contains a single integer t (1≤t≤10) — the number of test cases. Next 2t lines contain descriptions of test cases.

The first line of the description of each test case contains four integers n, c0, c1, h (1≤n,c0,c1,h≤1000).

The second line of the description of each test case contains the binary string s of length n.

Output
For each test case print a single integer — the minimum number of coins needed to buy the string.

Example
inputCopy
6
3 1 1 1
100
5 10 100 1
01010
5 10 1 1
11111
5 1 10 1
11111
12 2 1 10
101110110101
2 100 1 10
00
outputCopy
3
52
5
10
16
22
Note
In the first test case, you can buy all characters and pay 3 coins, because both characters 0 and 1 costs 1 coin.

In the second test case, you can firstly change 2-nd and 4-th symbols of the string from 1 to 0 and pay 2 coins for that. Your string will be 00000. After that, you can buy the string and pay 5⋅10=50 coins for that. The total number of coins paid will be 2+50=52.


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
	ll n, c, c1, h;
	cin >> n >> c >> c1 >> h;
	string s;
	cin >> s;
	ll f = 0, f1 = 0, ans = 0;
	foi(s.size()) {
		if (s[i] == '0')
			f++;
		else
			f1++;
	}
	if (c1 == c)
		cout << s.size()*c1;
	else if (c1 > c and c1 > h + c) {
		cout << f1*h + n*c;
	}
	else if (c > c1 and c > h + c1)
		cout << f*h + c1*n;
	else
		cout << f1*c1 + f*c;

}
