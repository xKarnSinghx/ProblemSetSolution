/*
D. Madoka and the Best School in Russia
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Madoka is going to enroll in "TSUNS PTU". But she stumbled upon a difficult task during the entrance computer science exam:

A number is called good if it is a multiple of d.
A number is called beatiful if it is good and it cannot be represented as a product of two good numbers.
Notice that a beautiful number must be good.

Given a good number x, determine whether it can be represented in at least two different ways as a product of several (possibly, one) beautiful numbers. Two ways are different if the sets of numbers used are different.

Solve this problem for Madoka and help her to enroll in the best school in Russia!

Input
The first line contains a single integer t (1≤t≤100) — number of test cases. Below comes their description.

Each test case consists of two integers x and d, separated by a space (2≤x,d≤109). It is guaranteed that x is a multiple of d.

Output
For each set of input data, output "NO" if the number cannot be represented in at least two ways. Otherwise, output "YES".

You can output each letter in any case (for example, "YES", "Yes", "yes", "yEs", "yEs" will be recognized as a positive answer).

Example
inputCopy
8
6 2
12 2
36 2
8 2
1000 10
2376 6
128 4
16384 4
outputCopy
NO
NO
YES
NO
YES
YES
NO
YES
Note
In the first example, 6 can be represented as 6, 1⋅6, 2⋅3. But 3 and 1 are not a good numbers because they are not divisible by 2, so there is only one way.

In the second example, 12 can be represented as 6⋅2, 12, 3⋅4, or 3⋅2⋅2. The first option is suitable. The second is— no, because 12 is not beautiful number (12=6⋅2). The third and fourth are also not suitable, because 3 is not good number.

In the third example, 36 can be represented as 18⋅2 and 6⋅6. Therefore it can be decomposed in at least two ways.

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
const ll N = 100010;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t; cin >> t;
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
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
void solve() {
	ll x, d;
	cin >> x >> d;
	ll cnt = 0, n = x;
	while (n % d == 0) {
		cnt++, n /= d;
	}
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0 and cnt > 1) {
			cout << "Yes";
			return;
		}
	}
	if (cnt < 3) {
		cout << "No";
		return;
	}
	for (ll i = 2; i * i <= d; i++) {
		if (d % i == 0) {
			if (n != d / i or i != n or cnt > 3) {
				cout << "Yes";
				return;
			}
		}
	}
	cout << "No";
}

