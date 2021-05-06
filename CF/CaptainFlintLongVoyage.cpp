/*
B. Captain Flint and a Long Voyage
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Captain Flint and his crew keep heading to a savage shore of Byteland for several months already, drinking rum and telling stories. In such moments uncle Bogdan often remembers his nephew Denis. Today, he has told a story about how Denis helped him to come up with an interesting problem and asked the crew to solve it.

In the beginning, uncle Bogdan wrote on a board a positive integer x consisting of n digits. After that, he wiped out x and wrote integer k instead, which was the concatenation of binary representations of digits x consists of (without leading zeroes). For example, let x=729, then k=111101001 (since 7=111, 2=10, 9=1001).

After some time, uncle Bogdan understood that he doesn't know what to do with k and asked Denis to help. Denis decided to wipe last n digits of k and named the new number as r.

As a result, Denis proposed to find such integer x of length n that r (as number) is maximum possible. If there are multiple valid x then Denis is interested in the minimum one.

All crew members, including captain Flint himself, easily solved the task. All, except cabin boy Kostya, who was too drunk to think straight. But what about you?

Note: in this task, we compare integers (x or k) as numbers (despite what representations they are written in), so 729<1999 or 111<1000.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.

Next t lines contain test cases — one per test case. The one and only line of each test case contains the single integer n (1≤n≤105) — the length of the integer x you need to find.

It's guaranteed that the sum of n from all test cases doesn't exceed 2⋅105.

Output
For each test case, print the minimum integer x of length n such that obtained by Denis number r is maximum possible.

Example
inputCopy
2
1
3
outputCopy
8
998
Note
In the second test case (with n=3), if uncle Bogdan had x=998 then k=100110011000. Denis (by wiping last n=3 digits) will obtain r=100110011.

It can be proved that the 100110011 is the maximum possible r Denis can obtain and 998 is the minimum x to obtain it.


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
void solve() {
	ll n;
	cin >> n;
	ll x = (n + 3) / 4;
	foi(n - x) {
		cout << 9;
	}
	foi(x) {
		cout << 8;
	}


}
