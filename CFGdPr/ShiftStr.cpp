/*
F. Shifting String
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp found the string s and the permutation p. Their lengths turned out to be the same and equal to n.

A permutation of n elements — is an array of length n, in which every integer from 1 to n occurs exactly once. For example, [1,2,3] and [4,3,5,1,2] are permutations, but [1,2,4], [4,3,2,1,2] and [0,1,2] are not.

In one operation he can multiply s by p, so he replaces s with string new, in which for any i from 1 to n it is true that newi=spi. For example, with s=wmbe and p=[3,1,4,2], after operation the string will turn to s=s3s1s4s2=bwem.

Polycarp wondered after how many operations the string would become equal to its initial value for the first time. Since it may take too long, he asks for your help in this matter.

It can be proved that the required number of operations always exists. It can be very large, so use a 64-bit integer type.

Input
The first line of input contains one integer t (1≤t≤5000) — the number of test cases in input.

The first line of each case contains single integer n (1≤n≤200) — the length of string and permutation.

The second line of each case contains a string s of length n, containing lowercase Latin letters.

The third line of each case contains n integers — permutation p (1≤pi≤n), all pi are different.

Output
Output t lines, each of which contains the answer to the corresponding test case of input. As an answer output single integer — the minimum number of operations, after which the string s will become the same as it was before operations.

Example
inputCopy
3
5
ababa
3 4 5 2 1
5
ababa
2 1 4 5 3
10
codeforces
8 6 1 7 5 2 9 3 10 4
outputCopy
1
6
12
Note
In the first sample operation doesn't change the string, so it will become the same as it was after 1 operations.

In the second sample the string will change as follows:

s = babaa
s = abaab
s = baaba
s = abbaa
s = baaab
s = ababa
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
	string s;
	cin >> s;
	vll a(n);
	foi(n) {
		cin >> a[i];
		a[i]--;
	}
	string t = s;
	ll ans = 1;
	vll vis(n, 0);
	foi(n) {
		if (vis[i])
			continue;
		ll cur = i;
		vll cyc;
		while (!vis[cur]) {
			vis[cur]++, cyc.pb(cur), cur = a[cur];
		}
		ll step = 0, done = 0;
		while (!done) {
			char c = s[cyc[0]];
			foi(cyc.size() - 1) {
				s[cyc[i]] = s[cyc[i + 1]];
			}
			s[cyc[cyc.size() - 1]] = c, done++;
			foi(cyc.size()) {
				if (t[cyc[i]] != s[cyc[i]]) {
					done = 0;
					break;
				}
			}
			step++;
		}
		ans = lcm(ans, step);
	}
	cout << ans;
}
