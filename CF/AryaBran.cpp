/*
A. Arya and Bran
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bran and his older sister Arya are from the same house. Bran like candies so much, so Arya is going to give him some Candies.

At first, Arya and Bran have 0 Candies. There are n days, at the i-th day, Arya finds ai candies in a box, that is given by the Many-Faced God. Every day she can give Bran at most 8 of her candies. If she don't give him the candies at the same day, they are saved for her and she can give them to him later.

Your task is to find the minimum number of days Arya needs to give Bran k candies before the end of the n-th day. Formally, you need to output the minimum day index to the end of which k candies will be given out (the days are indexed from 1 to n).

Print -1 if she can't give him k candies during n given days.

Input
The first line contains two integers n and k (1 ≤ n ≤ 100, 1 ≤ k ≤ 10000).

The second line contains n integers a1, a2, a3, ..., an (1 ≤ ai ≤ 100).

Output
If it is impossible for Arya to give Bran k candies within n days, print -1.

Otherwise print a single integer — the minimum number of days Arya needs to give Bran k candies before the end of the n-th day.

Examples
inputCopy
2 3
1 2
outputCopy
2
inputCopy
3 17
10 10 10
outputCopy
3
inputCopy
1 9
10
outputCopy
-1
Note
In the first sample, Arya can give Bran 3 candies in 2 days.

In the second sample, Arya can give Bran 17 candies in 3 days, because she can give him at most 8 candies per day.

In the third sample, Arya can't give Bran 9 candies, because she can give him at most 8 candies per day and she must give him the candies within 1 day.

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
typedef pair< ll, pll>      plll;
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
typedef priority_queue <ll> pq;
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


//	ll t ; cin >> t;
	//while (t--)
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
void solve() {
	ll n, k;
	cin >> n >> k;
	ll  s = 0, t = 0;
	foi(n) {
		ll x;
		cin >> x;
		t += x;
		s += min(8LL, t);
		t -= min(8LL, t);
		if (s >= k) {
			cout << i + 1;
			return;
		}
	}
	cout << -1;
}
