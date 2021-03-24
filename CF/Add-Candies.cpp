/*
A. Add Candies
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n bags with candies, initially the i-th bag contains i candies. You want all the bags to contain an equal amount of candies in the end.

To achieve this, you will:

Choose m such that 1≤m≤1000
Perform m operations. In the j-th operation, you will pick one bag and add j candies to all bags apart from the chosen one.

Your goal is to find a valid sequence of operations after which all the bags will contain an equal amount of candies.

It can be proved that for the given constraints such a sequence always exists.

You don't have to minimize m.

If there are several valid sequences, you can output any.

Input
Each test contains multiple test cases.

The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

The first and only line of each test case contains one integer n (2≤n≤100).

Output
For each testcase, print two lines with your answer.

In the first line print m (1≤m≤1000) — the number of operations you want to take.

In the second line print m positive integers a1,a2,…,am (1≤ai≤n), where aj is the number of bag you chose on the j-th operation.

Example
inputCopy
2
2
3
outputCopy
1
2
5
3 3 3 1 2
Note
In the first case, adding 1 candy to all bags except of the second one leads to the arrangement with [2,2] candies.

In the second case, firstly you use first three operations to add 1+2+3=6 candies in total to each bag except of the third one, which gives you [7,8,3]. Later, you add 4 candies to second and third bag, so you have [7,12,7], and 5 candies to first and third bag  — and the result is [12,12,12].


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
	cin >> n ;
	cout << n - 1 << endl;
	for (ll i = 1; i < n; i++) {
		cout << i + 1 << " ";
	}

}

 
