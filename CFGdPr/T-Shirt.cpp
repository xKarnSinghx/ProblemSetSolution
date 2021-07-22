/*
B. T-Shirt Hunt
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Not so long ago the Codecraft-17 contest was held on Codeforces. The top 25 participants, and additionally random 25 participants out of those who got into top 500, will receive a Codeforces T-shirt.

Unfortunately, you didn't manage to get into top 25, but you got into top 500, taking place p.

Now the elimination round of 8VC Venture Cup 2017 is being held. It has been announced that the Codecraft-17 T-shirt winners will be chosen as follows. Let s be the number of points of the winner of the elimination round of 8VC Venture Cup 2017. Then the following pseudocode will be executed:


i := (s div 50) mod 475
repeat 25 times:
    i := (i * 96 + 42) mod 475
    print (26 + i)
Here "div" is the integer division operator, "mod" is the modulo (the remainder of division) operator.

As the result of pseudocode execution, 25 integers between 26 and 500, inclusive, will be printed. These will be the numbers of places of the participants who get the Codecraft-17 T-shirts. It is guaranteed that the 25 printed integers will be pairwise distinct for any value of s.

You're in the lead of the elimination round of 8VC Venture Cup 2017, having x points. You believe that having at least y points in the current round will be enough for victory.

To change your final score, you can make any number of successful and unsuccessful hacks. A successful hack brings you 100 points, an unsuccessful one takes 50 points from you. It's difficult to do successful hacks, though.

You want to win the current round and, at the same time, ensure getting a Codecraft-17 T-shirt. What is the smallest number of successful hacks you have to do to achieve that?

Input
The only line contains three integers p, x and y (26 ≤ p ≤ 500; 1 ≤ y ≤ x ≤ 20000) — your place in Codecraft-17, your current score in the elimination round of 8VC Venture Cup 2017, and the smallest number of points you consider sufficient for winning the current round.

Output
Output a single integer — the smallest number of successful hacks you have to do in order to both win the elimination round of 8VC Venture Cup 2017 and ensure getting a Codecraft-17 T-shirt.

It's guaranteed that your goal is achievable for any valid input data.

Examples
inputCopy
239 10880 9889
outputCopy
0
inputCopy
26 7258 6123
outputCopy
2
inputCopy
493 8000 8000
outputCopy
24
inputCopy
101 6800 6500
outputCopy
0
inputCopy
329 19913 19900
outputCopy
8
Note
In the first example, there is no need to do any hacks since 10880 points already bring the T-shirt to the 239-th place of Codecraft-17 (that is, you). In this case, according to the pseudocode, the T-shirts will be given to the participants at the following places:


475 422 84 411 453 210 157 294 146 188 420 367 29 356 398 155 102 239 91 133 365 312 449 301 343
In the second example, you have to do two successful and one unsuccessful hack to make your score equal to 7408.

In the third example, you need to do as many as 24 successful hacks to make your score equal to 10400.

In the fourth example, it's sufficient to do 6 unsuccessful hacks (and no successful ones) to make your score equal to 6500, which is just enough for winning the current round and also getting the T-shirt.


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
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
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
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
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
bool win(ll x, ll y) {
	x = (x / 50) % 475;
	foi(25) {
		x *= 96;
		x += 42;
		x %= 475;
		if (x + 26 == y)
			return true;
	}
	return false;
}
void solve() {
	ll p, x, y;
	cin >> p >> x >> y;
	ll t = x;
	while (t - 50 >= y) {
		t -= 50;
	}
	while (!win(t, p)) {
		t += 50;
	}
	if (t <= x) {
		cout << 0;
		return;
	}
	ll ans = 0;
	cout << ceils((t - x), 100);
}
 
