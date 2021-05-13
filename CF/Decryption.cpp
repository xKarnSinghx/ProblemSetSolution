/*
E. Decryption
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
An agent called Cypher is decrypting a message, that contains a composite number n. All divisors of n, which are greater than 1, are placed in a circle. Cypher can choose the initial order of numbers in the circle.

In one move Cypher can choose two adjacent numbers in a circle and insert their least common multiple between them. He can do that move as many times as needed.

A message is decrypted, if every two adjacent numbers are not coprime. Note that for such constraints it's always possible to decrypt the message.

Find the minimal number of moves that Cypher should do to decrypt the message, and show the initial order of numbers in the circle for that.

Input
The first line contains an integer t (1≤t≤100) — the number of test cases. Next t lines describe each test case.

In a single line of each test case description, there is a single composite number n (4≤n≤109) — the number from the message.

It's guaranteed that the total number of divisors of n for all test cases does not exceed 2⋅105.

Output
For each test case in the first line output the initial order of divisors, which are greater than 1, in the circle. In the second line output, the minimal number of moves needed to decrypt the message.

If there are different possible orders with a correct answer, print any of them.

Example
inputCopy
3
6
4
30
outputCopy
2 3 6 
1
2 4 
0
2 30 6 3 15 5 10 
0
Note
In the first test case 6 has three divisors, which are greater than 1: 2,3,6. Regardless of the initial order, numbers 2 and 3 are adjacent, so it's needed to place their least common multiple between them. After that the circle becomes 2,6,3,6, and every two adjacent numbers are not coprime.

In the second test case 4 has two divisors greater than 1: 2,4, and they are not coprime, so any initial order is correct, and it's not needed to place any least common multiples.

In the third test case all divisors of 30 greater than 1 can be placed in some order so that there are no two adjacent numbers that are coprime.


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
	set<ll>s;
	s.insert(n / 1);
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			s.insert(i);
			s.insert(n / i);
		}
	}
	ll ans[s.size() + 1], x = s.size();
	ans[0] = *s.begin();
	ll k = 1;
	s.erase(ans[0]);
	while (s.size() != 0)
	{
		ll p = ans[k - 1];
		for (auto it = s.begin(); it != s.end(); it++)
		{
			if (gcd(p, *it) != 1)
			{
				ans[k] = *it;
				s.erase(*it);
				break;
			}
		}
		k++;
	}
	foi(x)
	cout << ans[i] << " ";
	cout << "\n";
	if (gcd(ans[0], ans[x - 1]) != 1)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
}
