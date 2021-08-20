/*
E. Polycarp and String Transformation
time limit per test3.0 s
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp has a string s. Polycarp performs the following actions until the string s is empty (t is initially an empty string):

he adds to the right to the string t the string s, i.e. he does t=t+s, where t+s is a concatenation of the strings t and s;
he selects an arbitrary letter of s and removes from s all its occurrences (the selected letter must occur in the string s at the moment of performing this action).
Polycarp performs this sequence of actions strictly in this order.

Note that after Polycarp finishes the actions, the string s will be empty and the string t will be equal to some value (that is undefined and depends on the order of removing).

E.g. consider s="abacaba" so the actions may be performed as follows:

t="abacaba", the letter 'b' is selected, then s="aacaa";
t="abacabaaacaa", the letter 'a' is selected, then s="c";
t="abacabaaacaac", the letter 'c' is selected, then s="" (the empty string).
You need to restore the initial value of the string s using only the final value of t and find the order of removing letters from s.

Input
The first line contains one integer T (1≤T≤104) — the number of test cases. Then T test cases follow.

Each test case contains one string t consisting of lowercase letters of the Latin alphabet. The length of t doesn't exceed 5⋅105. The sum of lengths of all strings t in the test cases doesn't exceed 5⋅105.

Output
For each test case output in a separate line:

−1, if the answer doesn't exist;
two strings separated by spaces. The first one must contain a possible initial value of s. The second one must contain a sequence of letters — it's in what order one needs to remove letters from s to make the string t. E.g. if the string "bac" is outputted, then, first, all occurrences of the letter 'b' were deleted, then all occurrences of 'a', and then, finally, all occurrences of 'c'. If there are multiple solutions, print any one.
Example
inputCopy
7
abacabaaacaac
nowyouknowthat
polycarppoycarppoyarppyarppyrpprppp
isi
everywherevrywhrvryhrvrhrvhv
haaha
qweqeewew
outputCopy
abacaba bac
-1
polycarp lcoayrp
is si
everywhere ewyrhv
-1
-1
Note
The first test case is considered in the statement.

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
const ll N = 200010;
ull pows(ull x1, ll y1, ll mod)
{
	ull r1 = 1;
	x1 = x1 % mod;
	while (y1 > 0)	{
		if (y1 & 1)
			r1 = (r1 * x1) % mod;
		y1 = y1 >> 1;
		x1 = (x1 * x1) % mod;
	}
	return r1;
}
ull f[N];
ull mi(ull x, ll mod) {
	return pows(x, mod - 2, mod);
}
ull ncr(ull x, ll y, ll mod) {
	if (x < y)
		return 0;
	if (y == 0)
		return 1;
	ll ans = f[x] * mi(f[y], mod) % mod;
	ll z = (ans * mi(f[x - y], mod) % mod) % mod;
	return z % mod;
}
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
	/*foi(N) {
		if (i == 0) {
			f[i] = 1;
			continue;
		}
		f[i] = (f[i - 1] * i) % MOD;
	}*/
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
string ask(ll x, ll y) {
	cout << x + 1 << " " << y + 1;
	string s;
	cin >> s;
	return s;
}
void solve() {
	string t;
	cin >> t;
	vll c(26, 0);
	string ans = "";
	for (ll i = t.size() - 1; i > -1; i--) {
		if (c[t[i] - 'a'] == 0) {
			ans.pb(t[i]);
		}
		c[t[i] - 'a']++;
	}
	ll l = 0;
	foi(ans.size()) {
		l += c[ans[i] - 'a'] / (ans.size() - i);
		if (c[ans[i] - 'a'] % (ans.size() - i)) {
			cout << -1;
			return;
		}
	}
	string s = "";
	reverse(all(ans));
	foi(l) {
		s += t[i];
	}
	string s1 = s, t1 = s;
	foj(ans.size()) {
		string temp = "";
		foi(s1.size()) {
			if (ans[j] == s1[i])
				continue;
			temp += s1[i], t1 += s1[i];
		}
		s1 = temp;
	}
	if (t1 != t) {
		cout << -1;
		return;
	}
	cout << s << " " << ans;


}


 
