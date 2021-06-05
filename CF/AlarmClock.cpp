/*

A. Alarm Clock
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp has spent the entire day preparing problems for you. Now he has to sleep for at least a minutes to feel refreshed.

Polycarp can only wake up by hearing the sound of his alarm. So he has just fallen asleep and his first alarm goes off in b minutes.

Every time Polycarp wakes up, he decides if he wants to sleep for some more time or not. If he's slept for less than a minutes in total, then he sets his alarm to go off in c minutes after it is reset and spends d minutes to fall asleep again. Otherwise, he gets out of his bed and proceeds with the day.

If the alarm goes off while Polycarp is falling asleep, then he resets his alarm to go off in another c minutes and tries to fall asleep for d minutes again.

You just want to find out when will Polycarp get out of his bed or report that it will never happen.

Please check out the notes for some explanations of the example.

Input
The first line contains one integer t (1≤t≤1000) — the number of testcases.

The only line of each testcase contains four integers a,b,c,d (1≤a,b,c,d≤109) — the time Polycarp has to sleep for to feel refreshed, the time before the first alarm goes off, the time before every succeeding alarm goes off and the time Polycarp spends to fall asleep.

Output
For each test case print one integer. If Polycarp never gets out of his bed then print -1. Otherwise, print the time it takes for Polycarp to get out of his bed.

Example
inputCopy
7
10 3 6 4
11 3 6 4
5 9 4 10
6 5 2 3
1 1 1 1
3947465 47342 338129 123123
234123843 13 361451236 361451000
outputCopy
27
27
9
-1
1
6471793
358578060125049
Note
In the first testcase Polycarp wakes up after 3 minutes. He only rested for 3 minutes out of 10 minutes he needed. So after that he sets his alarm to go off in 6 minutes and spends 4 minutes falling asleep. Thus, he rests for 2 more minutes, totaling in 3+2=5 minutes of sleep. Then he repeats the procedure three more times and ends up with 11 minutes of sleep. Finally, he gets out of his bed. He spent 3 minutes before the first alarm and then reset his alarm four times. The answer is 3+4⋅6=27.

The second example is almost like the first one but Polycarp needs 11 minutes of sleep instead of 10. However, that changes nothing because he gets 11 minutes with these alarm parameters anyway.

In the third testcase Polycarp wakes up rested enough after the first alarm. Thus, the answer is b=9.

In the fourth testcase Polycarp wakes up after 5 minutes. Unfortunately, he keeps resetting his alarm infinitely being unable to rest for even a single minute :(


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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a - b > 0 and c <= d) {
		cout << -1;
		return;
	}
	if (a - b <= 0) {
		cout << b;
		return;
	}
	cout << b + c*ceils(a - b, c - d);

}
