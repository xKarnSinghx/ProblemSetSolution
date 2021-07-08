/*
C. K-Complete Word
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Word s of length n is called k-complete if

s is a palindrome, i.e. si=sn+1−i for all 1≤i≤n;
s has a period of k, i.e. si=sk+i for all 1≤i≤n−k.
For example, "abaaba" is a 3-complete word, while "abccba" is not.

Bob is given a word s of length n consisting of only lowercase Latin letters and an integer k, such that n is divisible by k. He wants to convert s to any k-complete word.

To do this Bob can choose some i (1≤i≤n) and replace the letter at position i with some other lowercase Latin letter.

So now Bob wants to know the minimum number of letters he has to replace to convert s to any k-complete word.

Note that Bob can do zero changes if the word s is already k-complete.

You are required to answer t test cases independently.

Input
The first line contains a single integer t (1≤t≤105) — the number of test cases.

The first line of each test case contains two integers n and k (1≤k<n≤2⋅105, n is divisible by k).

The second line of each test case contains a word s of length n.

It is guaranteed that word s only contains lowercase Latin letters. And it is guaranteed that the sum of n over all test cases will not exceed 2⋅105.

Output
For each test case, output one integer, representing the minimum number of characters he has to replace to convert s to any k-complete word.

Example
inputCopy
4
6 2
abaaba
6 3
abaaba
36 9
hippopotomonstrosesquippedaliophobia
21 7
wudixiaoxingxingheclp
outputCopy
2
0
23
16
Note
In the first test case, one optimal solution is aaaaaa.

In the second test case, the given word itself is k-complete.

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
	ll t ; cin >> t;
	cout << fixed ;
	cout << setprecision(19);
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
	ll n, k;
	cin >> n >> k;
	graph a(k + 1, vll(26, 0));
	string s;
	cin >> s;
	foi(s.size()) {
		a[i % k][s[i] - 'a']++;
	}
	ll ans = 0;
	foi(k) {
		ll mx = -1, s1 = 0;
		foj(26) {
			mx = max(mx, a[i][j] + a[k - i - 1][j]);
			s1 += a[i][j] + a[k - i - 1][j];
		}
		ans += s1 - mx;
	}
	ans /= 2;
	cout << ans;
}

