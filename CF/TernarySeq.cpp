/*
B. Ternary Sequence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two sequences a1,a2,…,an and b1,b2,…,bn. Each element of both sequences is either 0, 1 or 2. The number of elements 0, 1, 2 in the sequence a is x1, y1, z1 respectively, and the number of elements 0, 1, 2 in the sequence b is x2, y2, z2 respectively.

You can rearrange the elements in both sequences a and b however you like. After that, let's define a sequence c as follows:

ci=⎧⎩⎨aibi0−aibiif ai>biif ai=biif ai<bi
You'd like to make ∑ni=1ci (the sum of all elements of the sequence c) as large as possible. What is the maximum possible sum?

Input
The first line contains one integer t (1≤t≤104) — the number of test cases.

Each test case consists of two lines. The first line of each test case contains three integers x1, y1, z1 (0≤x1,y1,z1≤108) — the number of 0-s, 1-s and 2-s in the sequence a.

The second line of each test case also contains three integers x2, y2, z2 (0≤x2,y2,z2≤108; x1+y1+z1=x2+y2+z2>0) — the number of 0-s, 1-s and 2-s in the sequence b.

Output
For each test case, print the maximum possible sum of the sequence c.

Example
inputCopy
3
2 3 2
3 3 1
4 0 1
2 3 0
0 0 1
0 0 1
outputCopy
4
2
0
Note
In the first sample, one of the optimal solutions is:

a={2,0,1,1,0,2,1}
b={1,0,1,0,2,1,0}
c={2,0,0,0,0,2,0}
In the second sample, one of the optimal solutions is:

a={0,2,0,0,0}
b={1,1,0,1,0}
c={0,2,0,0,0}
In the third sample, the only possible solution is:

a={2}
b={2}
c={0}

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
string to_oct(ll n) {
	string s;
	while (n) {
		s = to_string(n % 8) + s;
		n /= 8;
	}
	return s;
}
void solve() {
	ll x, y, z, x1, y1, z1;
	cin >> x >> y >> z >> x1 >> y1 >> z1;
	ll a = min(z, y1);
	z -= a;
	y1 -= a;
	if (y1 > 0) {
		ll b = min(y, y1);
		y -= b;
		y1 -= b;
	}
	if (y > 0) {
		ll c = min(y, x1);
		y -= c;
		x1 -= c;
	}
	cout << a * 2 - y * 2;


}

