/*

B. Subsequence Hate
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Shubham has a binary string s. A binary string is a string containing only characters "0" and "1".

He can perform the following operation on the string any amount of times:

Select an index of the string, and flip the character at that index. This means, if the character was "0", it becomes "1", and vice versa.
A string is called good if it does not contain "010" or "101" as a subsequence  — for instance, "1001" contains "101" as a subsequence, hence it is not a good string, while "1000" doesn't contain neither "010" nor "101" as subsequences, so it is a good string.

What is the minimum number of operations he will have to perform, so that the string becomes good? It can be shown that with these operations we can make any string good.

A string a is a subsequence of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters.

Input
The first line of the input contains a single integer t (1≤t≤100) — the number of test cases.

Each of the next t lines contains a binary string s (1≤|s|≤1000).

Output
For every string, output the minimum number of operations required to make it good.

Example
inputCopy
7
001
100
101
010
0
1
001100
outputCopy
0
0
1
1
0
0
2
Note
In test cases 1, 2, 5, 6 no operations are required since they are already good strings.

For the 3rd test case: "001" can be achieved by flipping the first character  — and is one of the possible ways to get a good string.

For the 4th test case: "000" can be achieved by flipping the second character  — and is one of the possible ways to get a good string.

For the 7th test case: "000000" can be achieved by flipping the third and fourth characters  — and is one of the possible ways to get a good string.


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

	string s;
	cin >> s;
	ll o = 0, z = 0;
	foi(s.size()) {
		if (s[i] == '1')
			o++;
		else
			z++;
	}
	ll ans = min(o, z);
	ll o1 = 0, z1 = 0;
	foi(s.size()) {
		if (s[i] == '1')
			o1++, o--;
		else
			z1++, z--;
		ans = min(ans, min(z1 + o, z + o1));
	}
	cout << ans;
}
