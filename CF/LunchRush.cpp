/*
A. Lunch Rush
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Having written another programming contest, three Rabbits decided to grab some lunch. The coach gave the team exactly k time units for the lunch break.

The Rabbits have a list of n restaurants to lunch in: the i-th restaurant is characterized by two integers fi and ti. Value ti shows the time the Rabbits need to lunch in the i-th restaurant. If time ti exceeds the time k that the coach has given for the lunch break, then the Rabbits' joy from lunching in this restaurant will equal fi - (ti - k). Otherwise, the Rabbits get exactly fi units of joy.

Your task is to find the value of the maximum joy the Rabbits can get from the lunch, depending on the restaurant. The Rabbits must choose exactly one restaurant to lunch in. Note that the joy value isn't necessarily a positive value.

Input
The first line contains two space-separated integers — n (1 ≤ n ≤ 104) and k (1 ≤ k ≤ 109) — the number of restaurants in the Rabbits' list and the time the coach has given them to lunch, correspondingly. Each of the next n lines contains two space-separated integers — fi (1 ≤ fi ≤ 109) and ti (1 ≤ ti ≤ 109) — the characteristics of the i-th restaurant.

Output
In a single line print a single integer — the maximum joy value that the Rabbits will get from the lunch.

Examples
inputCopy
2 5
3 3
4 5
outputCopy
4
inputCopy
4 6
5 8
3 6
2 3
2 2
outputCopy
3
inputCopy
1 5
1 7
outputCopy
-1

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
	ll f[n], t[n];
	foi(n)
	cin >> f[i] >> t[i];
	ll ans = -111111111111111111;
	foi(n) {
		if (t[i] > k)
			ans = max(ans, f[i] + k - t[i]);
		else
			ans = max(ans, f[i]);
	}
	if (ans == -111111111111111111)
		cout << -1;
	else
		cout << ans;

}
