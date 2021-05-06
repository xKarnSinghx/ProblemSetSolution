/*
A. Captain Flint and Crew Recruitment
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Despite his bad reputation, Captain Flint is a friendly person (at least, friendly to animals). Now Captain Flint is searching worthy sailors to join his new crew (solely for peaceful purposes). A sailor is considered as worthy if he can solve Flint's task.

Recently, out of blue Captain Flint has been interested in math and even defined a new class of integers. Let's define a positive integer x as nearly prime if it can be represented as p⋅q, where 1<p<q and p and q are prime numbers. For example, integers 6 and 10 are nearly primes (since 2⋅3=6 and 2⋅5=10), but integers 1, 3, 4, 16, 17 or 44 are not.

Captain Flint guessed an integer n and asked you: can you represent it as the sum of 4 different positive integers where at least 3 of them should be nearly prime.

Uncle Bogdan easily solved the task and joined the crew. Can you do the same?

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.

Next t lines contain test cases — one per line. The first and only line of each test case contains the single integer n (1≤n≤2⋅105) — the number Flint guessed.

Output
For each test case print:

YES and 4 different positive integers such that at least 3 of them are nearly prime and their sum is equal to n (if there are multiple answers print any of them);
NO if there is no way to represent n as the sum of 4 different positive integers where at least 3 of them are nearly prime.
You can print each character of YES or NO in any case.
Example
inputCopy
7
7
23
31
36
44
100
258
outputCopy
NO
NO
YES
14 10 6 1
YES
5 6 10 15
YES
6 7 10 21
YES
2 10 33 55
YES
10 21 221 6
Note
In the first and second test cases, it can be proven that there are no four different positive integers such that at least three of them are nearly prime.

In the third test case, n=31=2⋅7+2⋅5+2⋅3+1: integers 14, 10, 6 are nearly prime.

In the fourth test case, n=36=5+2⋅3+2⋅5+3⋅5: integers 6, 10, 15 are nearly prime.

In the fifth test case, n=44=2⋅3+7+2⋅5+3⋅7: integers 6, 10, 21 are nearly prime.

In the sixth test case, n=100=2+2⋅5+3⋅11+5⋅11: integers 10, 33, 55 are nearly prime.

In the seventh test case, n=258=2⋅5+3⋅7+13⋅17+2⋅3: integers 10, 21, 221, 6 are nearly prime.
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
	if (n <= 30) {
		cout << "NO" ;
	}
	else {
		cout << "YES" << endl;
		if (n == 36 || n == 40 || n == 44) {
			cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 31 ;
		}
		else {
			cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 ;
		}
	}


}
