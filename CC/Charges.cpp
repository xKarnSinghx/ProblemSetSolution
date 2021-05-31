/*
There are N subatomic particles lined up in a row. There are two types: protons and electrons. Protons have a positive charge and are represented by 1, while electrons have a negative charge and are represented by 0.

Our current understanding of physics gives us a way to predict how the particles will be spaced out, if we know their charges. Two adjacent particles will be separated by 1 unit if they have opposite charges, and 2 units if they have the same charge.

When Chef is not in the kitchen, he is doing physics experiments on subatomic particles. He is testing the hypothesis by having N particles in a row, and he will change the charge of a particle K times. In the i-th update, he will change the charge of the Qi-th particle. After each update, find the distance between the first and last particle.

Note: Each update is persistent for further updates.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains three lines of input.
The first line contains two integers N, K.
The second line contains a string S of length N, where Si represents the initial charge on i-th particle.
The third line contains K integers Q1,Q2,…,QK, the positions of the changed particles.
Output
For each test case, output K lines, where the i-th line contains the answer after the updates Q1,…,Qi have been made.

Constraints
1≤T≤5
1≤N,K≤105
S contains only 0 and 1 characters.
1≤Qi≤N
The sum of K over all testcases is at most 2⋅105
Subtasks
Subtask #1 (100 points): original constraints

Sample Input
1
3 3
010
2 1 3
Sample Output
4
3
2
Explanation
Update 1: After reversing the parity of particle 2, the new configuration is 000. Since all the particles have a similar charge, each is separated from the previous by a distance of 2 units. So the location of particle 3 is 2+2=4 units from the first particle.

Update 2: After reversing the parity of particle 1, the new configuration is 100. Here, the charges of particles 1 and 2 differ, so they are separated by 1 unit. The charges of particles 2 and 3 agree, so they are separated by 2 units. So, the location of particle 3 is 1+2=3 units from the first particle.

Update 3: After reversing the charge of particle 3, the new configuration is 101. Here, particles 1 and 2 are separated by 1 unit and particles 2 and 3 are separated by 1 unit. So the location of particle 3 is 1+1=2 units from the first particle.
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
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
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
void solve() {
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll ans = 0;
	foj(s.size() - 1 ) {
		if (s[j] != s[j + 1])
			ans++;
		else
			ans += 2;
	}
	foi(k) {
		ll x;
		cin >> x;
		if (x == 1 and s.size() > 1) {
			if (s[x - 1] == '1' and s[x] == '1')
				s[x - 1] = '0', ans--;
			else if (s[x - 1] == '1' and s[x] == '0')
				s[x - 1] = '0', ans++;
			else if (s[x - 1] == '0' and s[x] == '1')
				s[x - 1] = '1', ans++;
			else if (s[x - 1] == '0' and s[x] == '0')
				s[x - 1] = '1', ans--;
		}
		else if (x == n and s.size() > 1) {
			if (s[x - 1] == '1' and s[x - 2] == '1')
				s[x - 1] = '0', ans--;
			else if (s[x - 1] == '1' and s[x - 2] == '0')
				s[x - 1] = '0', ans++;
			else if (s[x - 1] == '0' and s[x - 2] == '1')
				s[x - 1] = '1', ans++;
			else if (s[x - 1] == '0' and s[x - 2] == '0')
				s[x - 1] = '1', ans--;
		}
		else {
			if (s[x - 1] == '1' and s[x - 2] == '1' and s[x] == '1')
				s[x - 1] = '0', ans -= 2;
			else if (s[x - 1] == '1' and s[x - 2] == '0' and s[x] == '1')
				s[x - 1] = '0';
			else if (s[x - 1] == '1' and s[x - 2] == '1' and s[x] == '0')
				s[x - 1] = '0';
			else if (s[x - 1] == '1' and s[x - 2] == '0' and s[x] == '0')
				s[x - 1] = '0', ans += 2;
			else if (s[x - 1] == '0' and s[x - 2] == '1' and s[x] == '1')
				s[x - 1] = '1', ans += 2;
			else if (s[x - 1] == '0' and s[x - 2] == '0' and s[x] == '1')
				s[x - 1] = '1';
			else if (s[x - 1] == '0' and s[x - 2] == '1' and s[x] == '0')
				s[x - 1] = '1';
			else if (s[x - 1] == '0' and s[x - 2] == '0' and s[x] == '0')
				s[x - 1] = '1', ans -= 2;
		}

		cout << ans << endl;

	}

}



