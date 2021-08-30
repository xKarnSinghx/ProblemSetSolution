/*
D. Take a Guess
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output

This is an interactive task

William has a certain sequence of integers a1,a2,…,an in his mind, but due to security concerns, he does not want to reveal it to you completely. William is ready to respond to no more than 2⋅n of the following questions:

What is the result of a bitwise AND of two items with indices i and j (i≠j)
What is the result of a bitwise OR of two items with indices i and j (i≠j)
You can ask William these questions and you need to find the k-th smallest number of the sequence.

Formally the k-th smallest number is equal to the number at the k-th place in a 1-indexed array sorted in non-decreasing order. For example in array [5,3,3,10,1] 4th smallest number is equal to 5, and 2nd and 3rd are 3.

Input
It is guaranteed that for each element in a sequence the condition 0≤ai≤109 is satisfied.

Interaction
In the first line you will be given two integers n and k (3≤n≤104,1≤k≤n), which are the number of items in the sequence a and the number k.

After that, you can ask no more than 2⋅n questions (not including the "finish" operation).

Each line of your output may be of one of the following types:

"or i j" (1≤i,j≤n,i≠j), where i and j are indices of items for which you want to calculate the bitwise OR.
"and i j" (1≤i,j≤n,i≠j), where i and j are indices of items for which you want to calculate the bitwise AND.
"finish res", where res is the kth smallest number in the sequence. After outputting this line the program execution must conclude.
In response to the first two types of queries, you will get an integer x, the result of the operation for the numbers you have selected.

After outputting a line do not forget to output a new line character and flush the output buffer. Otherwise you will get the "Idleness limit exceeded". To flush the buffer use:

fflush(stdout) in C++
System.out.flush() in Java
stdout.flush() in Python
flush(output) in Pascal
for other languages refer to documentation
If you perform an incorrect query the response will be −1. After receiving response −1 you must immediately halt your program in order to receive an "Incorrect answer" verdict.

Hacking

To perform a hack you will need to use the following format:

The first line must contain two integers n and k (3≤n≤104,1≤k≤n), which are the number of items in the sequence a and the number k.

The second line must contain n integers a1,a2,…,an (0≤ai≤109), the sequence a.

Example
inputCopy
7 6

2

7
outputCopy
and 2 5

or 5 6

finish 5
Note
In the example, the hidden sequence is [1,6,4,2,3,5,4].

Below is the interaction in the example.

Query (contestant's program)	Response (interactor)	Notes
and 2 5	2	a2=6, a5=3. Interactor returns bitwise AND of the given numbers.
or 5 6	7	a5=3, a6=5. Interactor returns bitwise OR of the given numbers.
finish 5		5 is the correct answer. Note that you must find the value and not the index of the kth smallest number.
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
bool is_sorted(vector<ll>a) {
	ll x = 0;
	for (ll i = 0; i < a.size() - 1; i++) {
		if (a[i] < a[i + 1])
			x++;
	}
	return x == a.size() - 1;
}
bool check(string a, string b) {
	ll n = a.size(), m = b.size();
	if (a < b) {
		return true;
	}
	if (a > b) {
		return false;
	}
	foi(a.size()) {
		if (a[i] > b[i]) {
			return false;
		}
		else if (a[i] < b[i]) {
			return true;
		}
	}
	return false;
}
bool isSubSequence(string a, string b, ll m, ll n) {
	ll j = 0;
	for (ll i = 0; i < n and j < m; i++)
		if (a[j] == b[i])
			j++;
	return (j == m);
}
ll get(ll x, ll y) {
	cout << "and" << ' ' << x + 1 << ' ' << y + 1 << endl;
	ll x1;
	cin >> x1;
	return x1;
}
ll get1(ll x, ll y) {
	cout << "or" << ' ' << x + 1 << ' ' << y + 1 << endl;
	ll x1;
	cin >> x1;
	return x1;
}
void solve() {
	ll n, y;
	cin >> n >> y;
	vll a(n, 0);
	ll z = get(0, 1) + get1(0, 1);
	ll z1 = get(1, 2) + get1(1, 2);
	ll z2 = get(0, 2) + get1(0, 2);
	a[1] = ( z + z1  - z2 ) / 2;
	a[0] = z - a[1];
	a[2] = z1 - a[1];
	foi(n - 3) {
		a[i + 3] = get(i + 2, i + 3) + get1(i + 2, i + 3) - a[i + 2];
	}
	sort(all(a));
	cout << "finish " << a[y - 1];
}



 
