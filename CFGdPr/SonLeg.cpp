/*
E. Sonya and Problem Wihtout a Legend
time limit per test5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sonya was unable to think of a story for this problem, so here comes the formal description.

You are given the array containing n positive integers. At one turn you can pick any element and increase or decrease it by 1. The goal is the make the array strictly increasing by making the minimum possible number of operations. You are allowed to change elements in any way, they can become negative or equal to 0.

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 3000) — the length of the array.

Next line contains n integer ai (1 ≤ ai ≤ 109).

Output
Print the minimum number of operation required to make the array strictly increasing.

Examples
inputCopy
7
2 1 5 11 5 9 11
outputCopy
9
inputCopy
5
5 4 3 2 1
outputCopy
12
Note
In the first sample, the array is going to look as follows:

2 3 5 6 7 9 11

|2 - 2| + |1 - 3| + |5 - 5| + |11 - 6| + |5 - 7| + |9 - 9| + |11 - 11| = 9

And for the second sample:

1 2 3 4 5

|5 - 1| + |4 - 2| + |3 - 3| + |2 - 4| + |1 - 5| = 12


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
typedef vector<ld>          vld;
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
typedef  map<vll, ll>             mvlll;
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
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000001;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
// 	ll t; cin >> t;
// 	while (t--)
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
multiset<ll> Lis(vll a) {
	multiset<ll> S;
	multiset<ll>::iterator it;
	foi(a.size()) {
		S.insert(a[i]);
		it = S.lower_bound(a[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}

void solve() {
	ll n;
	cin >> n;
	vll a(n);
	foi(n) {
		cin >> a[i];
		a[i] -= i;
	}
	pq q;
	ll ans = 0;
	q.push(a[0]);
	foi(n) {
		if (i == 0)
			continue;
		q.push(a[i]);
		if (q.top() > a[i]) {
			ans += q.top() - a[i];
			q.pop();
			q.push(a[i]);
		}
	}
	cout << ans;

}
