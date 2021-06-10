/*
B. Two Arrays And Swaps
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two arrays a and b both consisting of n positive (greater than zero) integers. You are also given an integer k.

In one move, you can choose two indices i and j (1≤i,j≤n) and swap ai and bj (i.e. ai becomes bj and vice versa). Note that i and j can be equal or different (in particular, swap a2 with b2 or swap a3 and b9 both are acceptable moves).

Your task is to find the maximum possible sum you can obtain in the array a if you can do no more than (i.e. at most) k such moves (swaps).

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤200) — the number of test cases. Then t test cases follow.

The first line of the test case contains two integers n and k (1≤n≤30;0≤k≤n) — the number of elements in a and b and the maximum number of moves you can do. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤30), where ai is the i-th element of a. The third line of the test case contains n integers b1,b2,…,bn (1≤bi≤30), where bi is the i-th element of b.

Output
For each test case, print the answer — the maximum possible sum you can obtain in the array a if you can do no more than (i.e. at most) k swaps.

Example
inputCopy
5
2 1
1 2
3 4
5 5
5 5 6 6 5
1 2 5 4 3
5 3
1 2 3 4 5
10 9 10 10 9
4 0
2 2 4 3
2 4 2 3
4 4
1 2 2 1
4 4 5 4
outputCopy
6
27
39
11
17
Note
In the first test case of the example, you can swap a1=1 and b2=4, so a=[4,2] and b=[3,1].

In the second test case of the example, you don't need to swap anything.

In the third test case of the example, you can swap a1=1 and b1=10, a3=3 and b3=10 and a2=2 and b4=10, so a=[10,10,10,4,5] and b=[1,9,3,2,9].

In the fourth test case of the example, you cannot swap anything.

In the fifth test case of the example, you can swap arrays a and b, so a=[4,4,5,4] and b=[1,2,2,1].
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
typedef map<pair<ll, ll>, ll>  mplll;
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
struct cmp {
	bool operator() (const pll &a, const pll &b) const {
		ll fir = a.ss - a.ff + 1;
		ll sec = b.ss - b.ff + 1;
		if (fir == sec)
			return a.ff < b.ff;
		return fir > sec;
	}
};
void solve() {
	ll n, k;
	cin >> n >> k;
	ll s = 0;
	vll a(n, 0), b(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
		s += x;
	}
	foi(n) {
		ll x;
		cin >> x;
		b[i] = x;
	}
	sort(all(a));
	sort(all(b));
	ll j = 0;
	for (ll i = n - 1; i > -1; i--) {
		if (b[i] > a[j] and k > 0) {
			s -= a[j];
			s += b[i];
			j++;
			k--;
		}
	}
	cout << s;

}
