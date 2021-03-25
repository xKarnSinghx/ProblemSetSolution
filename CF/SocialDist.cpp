/*
C. Social Distance
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp and his friends want to visit a new restaurant. The restaurant has n tables arranged along a straight line. People are already sitting at some tables. The tables are numbered from 1 to n in the order from left to right. The state of the restaurant is described by a string of length n which contains characters "1" (the table is occupied) and "0" (the table is empty).

Restaurant rules prohibit people to sit at a distance of k or less from each other. That is, if a person sits at the table number i, then all tables with numbers from i−k to i+k (except for the i-th) should be free. In other words, the absolute difference of the numbers of any two occupied tables must be strictly greater than k.

For example, if n=8 and k=2, then:

strings "10010001", "10000010", "00000000", "00100000" satisfy the rules of the restaurant;
strings "10100100", "10011001", "11111111" do not satisfy to the rules of the restaurant, since each of them has a pair of "1" with a distance less than or equal to k=2.
In particular, if the state of the restaurant is described by a string without "1" or a string with one "1", then the requirement of the restaurant is satisfied.

You are given a binary string s that describes the current state of the restaurant. It is guaranteed that the rules of the restaurant are satisfied for the string s.

Find the maximum number of free tables that you can occupy so as not to violate the rules of the restaurant. Formally, what is the maximum number of "0" that can be replaced by "1" such that the requirement will still be satisfied?

For example, if n=6, k=1, s= "100010", then the answer to the problem will be 1, since only the table at position 3 can be occupied such that the rules are still satisfied.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases in the test. Then t test cases follow.

Each test case starts with a line containing two integers n and k (1≤k≤n≤2⋅105) — the number of tables in the restaurant and the minimum allowed distance between two people.

The second line of each test case contains a binary string s of length n consisting of "0" and "1" — a description of the free and occupied tables in the restaurant. The given string satisfy to the rules of the restaurant — the difference between indices of any two "1" is more than k.

The sum of n for all test cases in one test does not exceed 2⋅105.

Output
For each test case output one integer — the number of tables that you can occupy so as not to violate the rules of the restaurant. If additional tables cannot be taken, then, obviously, you need to output 0.

Example
inputCopy
6
6 1
100010
6 2
000000
5 1
10101
3 1
001
2 2
00
1 1
0
outputCopy
1
2
0
1
1
1
Note
The first test case is explained in the statement.

In the second test case, the answer is 2, since you can choose the first and the sixth table.

In the third test case, you cannot take any free table without violating the rules of the restaurant.


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
typedef pair<ll, pll>      plll;
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
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}
bool isPrime(ll n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
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
ll fac(ll n) {
	while (n % 4 == 0) {
		n /= 4;
	}
	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % (i * i) == 0) {
			n /= (i * i);
		}
	}
	return n;
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll  f = 0, ans = 0;
	string s;
	cin >> s;
	for (ll i = 0; i < n;) {
		ll j = i + 1;

		for (; j < n && s[j] != '1'; j++);

		ll left = s[i] == '1' ? k : 0;
		ll right = j < n && s[j] == '1' ? k : 0;
		ll len = j - i;

		if (left == k) {
			len--;
		}

		len -= left + right;

		if (len > 0) {
			ans += (len + k) / (k + 1);
		}

		i = j;
	}
	cout << ans;

}

 
