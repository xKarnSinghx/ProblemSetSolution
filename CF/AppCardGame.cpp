/*
B. Appleman and Card Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Appleman has n cards. Each card has an uppercase letter written on it. Toastman must choose k cards from Appleman's cards. Then Appleman should give Toastman some coins depending on the chosen cards. Formally, for each Toastman's card i you should calculate how much Toastman's cards have the letter equal to letter on ith, then sum up all these quantities, such a number of coins Appleman should give to Toastman.

Given the description of Appleman's cards. What is the maximum number of coins Toastman can get?

Input
The first line contains two integers n and k (1 ≤ k ≤ n ≤ 105). The next line contains n uppercase letters without spaces — the i-th letter describes the i-th card of the Appleman.

Output
Print a single integer – the answer to the problem.

Examples
inputCopy
15 10
DZFDFZDFDDDDDDF
outputCopy
82
inputCopy
6 4
YJSNPI
outputCopy
4
Note
In the first test example Toastman can choose nine cards with letter D and one additional card with any letter. For each card with D he will get 9 coins and for the additional card he will get 1 coin.


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
	vll count(26);
	foi(26)
	count[i] = 0;
	string s;
	cin >> s;
	foi(n)
	{
		count[s[i] - 'A']++;
	}
	sort(count.begin(), count.end());
	ll ans = 0;
	for (ll i = count.size() - 1; i >= 0; i--)
	{
		if (k >= count[i] && k > 0)
		{
			ans += count[i] * count[i];
			k = k - count[i];
		}
		else if (k < count[i] && k > 0)
		{
			ans += k * k;
			k = 0;
		}
		if (k == 0)
		{
			break;
		}
	}
	cout << ans;

}
