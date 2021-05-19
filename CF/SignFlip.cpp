/*
A. Sign Flipping
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given n integers a1,a2,…,an, where n is odd. You are allowed to flip the sign of some (possibly all or none) of them. You wish to perform these flips in such a way that the following conditions hold:

At least n−12 of the adjacent differences ai+1−ai for i=1,2,…,n−1 are greater than or equal to 0.
At least n−12 of the adjacent differences ai+1−ai for i=1,2,…,n−1 are less than or equal to 0.
Find any valid way to flip the signs. It can be shown that under the given constraints, there always exists at least one choice of signs to flip that satisfies the required condition. If there are several solutions, you can find any of them.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤500)  — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (3≤n≤99, n is odd)  — the number of integers given to you.

The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109)  — the numbers themselves.

It is guaranteed that the sum of n over all test cases does not exceed 10000.

Output
For each test case, print n integers b1,b2,…,bn, corresponding to the integers after flipping signs. bi has to be equal to either ai or −ai, and of the adjacent differences bi+1−bi for i=1,…,n−1, at least n−12 should be non-negative and at least n−12 should be non-positive.

It can be shown that under the given constraints, there always exists at least one choice of signs to flip that satisfies the required condition. If there are several solutions, you can find any of them.

Example
inputCopy
5
3
-2 4 3
5
1 1 1 1 1
5
-2 4 7 -6 4
9
9 7 -4 -2 1 -3 9 -4 -5
9
-4 1 9 4 8 9 5 1 -9
outputCopy
-2 -4 3
1 1 1 1 1
-2 -4 7 -6 4
-9 -7 -4 2 1 -3 -9 -4 -5
4 -1 -9 -4 -8 -9 -5 -1 9
Note
In the first test case, the difference (−4)−(−2)=−2 is non-positive, while the difference 3−(−4)=7 is non-negative.

In the second test case, we don't have to flip any signs. All 4 differences are equal to 0, which is both non-positive and non-negative.

In the third test case, 7−(−4) and 4−(−6) are non-negative, while (−4)−(−2) and (−6)−7 are non-positive.

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
void solve() {
	ll n;
	cin >> n;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	for (ll i = 0; i < n; i += 2) {
		if (a[i] > 0)
			a[i] *= -1;
	}
	for (ll i = 1; i < n; i += 2) {
		if (a[i] < 0) {
			a[i] *= -1;
		}
	}
	foi(n)
	cout << a[i] << " ";
}

