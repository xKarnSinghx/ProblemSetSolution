/*
A. Diplomas and Certificates
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n students who have taken part in an olympiad. Now it's time to award the students.

Some of them will receive diplomas, some wiil get certificates, and others won't receive anything. Students with diplomas and certificates are called winners. But there are some rules of counting the number of diplomas and certificates. The number of certificates must be exactly k times greater than the number of diplomas. The number of winners must not be greater than half of the number of all students (i.e. not be greater than half of n). It's possible that there are no winners.

You have to identify the maximum possible number of winners, according to these rules. Also for this case you have to calculate the number of students with diplomas, the number of students with certificates and the number of students who are not winners.

Input
The first (and the only) line of input contains two integers n and k (1 ≤ n, k ≤ 1012), where n is the number of students and k is the ratio between the number of certificates and the number of diplomas.

Output
Output three numbers: the number of students with diplomas, the number of students with certificates and the number of students who are not winners in case when the number of winners is maximum possible.

It's possible that there are no winners.

Examples
inputCopy
18 2
outputCopy
3 6 9
inputCopy
9 10
outputCopy
0 0 9
inputCopy
1000000000000 5
outputCopy
83333333333 416666666665 500000000002
inputCopy
1000000000000 499999999999
outputCopy
1 499999999999 500000000000

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
ll TT = 1;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


	//ll tc ; cin >> tc;
	//while (tc--)
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
ll sod(ll n) {
	ll s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}
void solve()
{
	ll n, k;
	cin >> n >> k;
	ll loser = ceils(n, 2);
	ll winners = n - loser;
	ll deploma = winners / (k + 1);
	ll certi = winners - deploma;
	certi = k * deploma;
	loser = n - certi - deploma;
	cout << deploma << " " << certi << " " << loser;
}

 
