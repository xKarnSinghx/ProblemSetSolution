/*
C. Perfect Keyboard
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp wants to assemble his own keyboard. Layouts with multiple rows are too complicated for him — his keyboard will consist of only one row, where all 26 lowercase Latin letters will be arranged in some order.

Polycarp uses the same password s on all websites where he is registered (it is bad, but he doesn't care). He wants to assemble a keyboard that will allow to type this password very easily. He doesn't like to move his fingers while typing the password, so, for each pair of adjacent characters in s, they should be adjacent on the keyboard. For example, if the password is abacaba, then the layout cabdefghi... is perfect, since characters a and c are adjacent on the keyboard, and a and b are adjacent on the keyboard. It is guaranteed that there are no two adjacent equal characters in s, so, for example, the password cannot be password (two characters s are adjacent).

Can you help Polycarp with choosing the perfect layout of the keyboard, if it is possible?

Input
The first line contains one integer T (1≤T≤1000) — the number of test cases.

Then T lines follow, each containing one string s (1≤|s|≤200) representing the test case. s consists of lowercase Latin letters only. There are no two adjacent equal characters in s.

Output
For each test case, do the following:

if it is impossible to assemble a perfect keyboard, print NO (in upper case, it matters in this problem);
otherwise, print YES (in upper case), and then a string consisting of 26 lowercase Latin letters — the perfect layout. Each Latin letter should appear in this string exactly once. If there are multiple answers, print any of them.
Example
inputCopy
5
ababa
codedoca
abcda
zxzytyz
abcdefghijklmnopqrstuvwxyza
outputCopy
YES
bacdefghijklmnopqrstuvwxyz
YES
edocabfghijklmnpqrstuvwxyz
NO
YES
xzytabcdefghijklmnopqrsuvw
NO

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
ld PI = 3.1415926535897;
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
void solve() {
	string s;
	cin >> s;
	vll vis(26, 0);
	string ans = "";
	ll id = 0;
	foi(s.size()) {
		if (i == 0) {
			ans += s[i];
			vis[s[i] - 'a']++;
			continue;
		}
		if (vis[s[i] - 'a']) {
			if (id > 0 and ans[id - 1] == s[i])
				id--;
			else if (id < ans.size() - 1 and ans[id + 1] == s[i] )
				id++;
			else {
				cout << "NO";
				return;
			}
		}
		else {
			vis[s[i] - 'a']++;
			if (id == 0) {
				ans = s[i] + ans;
			}
			else if (id == ans.size() - 1) {
				ans += s[i], id++;
			}
			else {
				cout << "NO";
				return;
			}
		}
	}
	foi(26) {
		if (vis[i])
			continue;
		else
			ans += char(i + 'a');
	}
	cout << "YES" << endl;
	cout << ans;
}


