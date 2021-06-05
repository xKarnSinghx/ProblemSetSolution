/*
A. Uncowed Forces
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kevin Sun has just finished competing in Codeforces Round #334! The round was 120 minutes long and featured five problems with maximum point values of 500, 1000, 1500, 2000, and 2500, respectively. Despite the challenging tasks, Kevin was uncowed and bulldozed through all of them, distinguishing himself from the herd as the best cowmputer scientist in all of Bovinia. Kevin knows his submission time for each problem, the number of wrong submissions that he made on each problem, and his total numbers of successful and unsuccessful hacks. Because Codeforces scoring is complicated, Kevin wants you to write a program to compute his final score.

Codeforces scores are computed as follows: If the maximum point value of a problem is x, and Kevin submitted correctly at minute m but made w wrong submissions, then his score on that problem is . His total score is equal to the sum of his scores for each problem. In addition, Kevin's total score gets increased by 100 points for each successful hack, but gets decreased by 50 points for each unsuccessful hack.

All arithmetic operations are performed with absolute precision and no rounding. It is guaranteed that Kevin's final score is an integer.

Input
The first line of the input contains five space-separated integers m1, m2, m3, m4, m5, where mi (0 ≤ mi ≤ 119) is the time of Kevin's last submission for problem i. His last submission is always correct and gets accepted.

The second line contains five space-separated integers w1, w2, w3, w4, w5, where wi (0 ≤ wi ≤ 10) is Kevin's number of wrong submissions on problem i.

The last line contains two space-separated integers hs and hu (0 ≤ hs, hu ≤ 20), denoting the Kevin's numbers of successful and unsuccessful hacks, respectively.

Output
Print a single integer, the value of Kevin's final score.

Examples
inputCopy
20 40 60 80 100
0 1 2 3 4
1 0
outputCopy
4900
inputCopy
119 119 119 119 119
0 0 0 0 0
10 0
outputCopy
4930
Note
In the second sample, Kevin takes 119 minutes on all of the problems. Therefore, he gets  of the points on each problem. So his score from solving problems is . Adding in 10·100 = 1000 points from hacks, his total score becomes 3930 + 1000 = 4930.


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
//	while (t--)
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
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}
void solve() {
	ll m[5];
	foi(5) {
		ll x;
		cin >> x;
		m[i] = x;
	}
	ll s[5];
	foi(5) {
		ll x;
		cin >> x;
		s[i] = x;
	}
	ll sh, ush;
	cin >> sh >> ush;
	vll point = {500, 1000, 1500, 2000, 2500};
	ll ans = 0;
	foi(5) {
		ans += max(3 * point[i] / 10, (250 - m[i]) * point[i] / 250 - 50 * s[i]);
	}
	ans += sh * 100.0 - ush * 50.0;
	ll fin = ans;
	cout << fin;

}
