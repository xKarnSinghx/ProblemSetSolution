/*
B. Saving the City
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bertown is a city with n buildings in a straight line.

The city's security service discovered that some buildings were mined. A map was compiled, which is a string of length n, where the i-th character is "1" if there is a mine under the building number i and "0" otherwise.

Bertown's best sapper knows how to activate mines so that the buildings above them are not damaged. When a mine under the building numbered x is activated, it explodes and activates two adjacent mines under the buildings numbered x−1 and x+1 (if there were no mines under the building, then nothing happens). Thus, it is enough to activate any one mine on a continuous segment of mines to activate all the mines of this segment. For manual activation of one mine, the sapper takes a coins. He can repeat this operation as many times as you want.

Also, a sapper can place a mine under a building if it wasn't there. For such an operation, he takes b coins. He can also repeat this operation as many times as you want.

The sapper can carry out operations in any order.

You want to blow up all the mines in the city to make it safe. Find the minimum number of coins that the sapper will have to pay so that after his actions there are no mines left in the city.

Input
The first line contains one positive integer t (1≤t≤105) — the number of test cases. Then t test cases follow.

Each test case begins with a line containing two integers a and b (1≤a,b≤1000) — the cost of activating and placing one mine, respectively.

The next line contains a map of mines in the city — a string consisting of zeros and ones.

The sum of the string lengths for all test cases does not exceed 105.

Output
For each test case, output one integer — the minimum number of coins that the sapper will have to pay.

Example
inputCopy
2
1 1
01000010
5 1
01101110
outputCopy
2
6
Note
In the second test case, if we place a mine under the fourth building and then activate it, then all mines on the field are activated. The cost of such operations is six, b=1 coin for placing a mine and a=5 coins for activating.


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
vb is_prime(1e6 + 1, true);

ll binomialCoeffSpaceEff(ll n, ll k)
{
	ll C[k + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // nC0 is 1

	for (ll i = 1; i <= n; i++) {
		// Compute next row of pascal triangle using
		// the previous row
		for (ll j = min(i, k); j > 0; j--)
			C[j] = (C[j] + C[j - 1]) % MOD;
	}
	return C[k];
}
ll primeFactors(ll n)
{
	vll ar;
	ll i = 2;
	while (n > 0)
	{
		if (i > n) break;
		if (n % i == 0)
		{
			ar.pb(i);
			while (n > 0 and n % i == 0) n = n / i;
		}
		i++;
	}
	return ar.size();
}

vpll primeFactorsFreq(ll n)
{
	vpll ar;
	ll i = 2;
	while (n > 0)
	{
		// cout<<n<<" ";
		if (i > n) break;
		if (n % i == 0)
		{
			ll cnt = 0;
			while (n > 0 and n % i == 0) n = n / i, cnt++;
			ar.pb(mp(i, cnt));
		}
		i++;
	}
	return ar;
}
void seive()
{
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= 1e6 + 1; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= 1e6 + 1; j += i)
				is_prime[j] = false;
		}
	}
}

bool isSorted(vll &ar)
{
	ll n = ar.size();

	for (ll i = 0; i < n - 1; i++)
	{
		if (ar[i + 1] < ar[i]) return false;
	}

	return true;
}

ll fastPower(ll x, ll y)
{
	ll res = 1;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % MOD;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % MOD; // Change x to x^2
	}
	return res;
}

ll kadanesAlgo(vll ar)
{
	int n = ar.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		currMax += ar[i];

		if (currMax <= ar[i])
		{
			currMax = ar[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}

pll kadanesAlgoIdx(vll ar)
{
	int n = ar.size();

	ll currMax = 0;
	ll mx = INT_MIN;
	int a = 0, b;
	for (int i = 0; i < n; i++)
	{
		currMax += ar[i];

		if (currMax <= ar[i])
		{
			currMax = ar[i];
			a = i;
		}

		if (mx < currMax)
		{
			mx = currMax;
			b = i;
		}
	}
	return mp(a, b);
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
ll findLCS(string a, string b, ll m, ll n)
{

	ll LCS[m + 1][n + 1];
	ll result = 0;
	for (ll i = 0; i <= m; i++)
	{
		for (ll j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				LCS[i][j] = 0;

			else if (a[i - 1] == b[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				result = max(result, LCS[i][j]);
			}
			else
				LCS[i][j] = 0;
		}
	}
	return result;
}

void solve()
{
	ll a, b, x = 11111111;
	cin >> a >> b;
	string s;
	cin >> s;
	ll n = s.size();
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			ans += min(a, b * x);
			x = 0;
		}
		else x++;
	}


	cout << ans ;


}


