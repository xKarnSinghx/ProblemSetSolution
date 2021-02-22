/*
C. Constanze's Machine
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Constanze is the smartest girl in her village but she has bad eyesight.

One day, she was able to invent an incredible machine! When you pronounce letters, the machine will inscribe them onto a piece of paper. For example, if you pronounce 'c', 'o', 'd', and 'e' in that order, then the machine will inscribe "code" onto the paper. Thanks to this machine, she can finally write messages without using her glasses.

However, her dumb friend Akko decided to play a prank on her. Akko tinkered with the machine so that if you pronounce 'w', it will inscribe "uu" instead of "w", and if you pronounce 'm', it will inscribe "nn" instead of "m"! Since Constanze had bad eyesight, she was not able to realize what Akko did.

The rest of the letters behave the same as before: if you pronounce any letter besides 'w' and 'm', the machine will just inscribe it onto a piece of paper.

The next day, I received a letter in my mailbox. I can't understand it so I think it's either just some gibberish from Akko, or Constanze made it using her machine. But since I know what Akko did, I can just list down all possible strings that Constanze's machine would have turned into the message I got and see if anything makes sense.

But I need to know how much paper I will need, and that's why I'm asking you for help. Tell me the number of strings that Constanze's machine would've turned into the message I got.

But since this number can be quite large, tell me instead its remainder when divided by 109+7.

If there are no strings that Constanze's machine would've turned into the message I got, then print 0.

Input
Input consists of a single line containing a string s (1≤|s|≤105) — the received message. s contains only lowercase Latin letters.

Output
Print a single integer — the number of strings that Constanze's machine would've turned into the message s, modulo 109+7.

Examples
inputCopy
ouuokarinn
outputCopy
4
inputCopy
banana
outputCopy
1
inputCopy
nnn
outputCopy
3
inputCopy
amanda
outputCopy
0
Note
For the first example, the candidate strings are the following: "ouuokarinn", "ouuokarim", "owokarim", and "owokarinn".

For the second example, there is only one: "banana".

For the third example, the candidate strings are the following: "nm", "mn" and "nnn".

For the last example, there are no candidate strings that the machine can turn into "amanda", since the machine won't inscribe 'm'.
*/
#include<bits/stdc++.h>
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
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

	solve();

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()

{

	string s;
	cin >> s;
	ll n = s.size();
	if (s.find('m') != -1 || s.find('w') != -1)
		cout << "0";
	else {
		vll dp(n + 1);
		dp[0] = 1;
		dp[1] = 1;
		for (ll i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1];
			if (s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
				dp[i] = (dp[i] + dp[i - 2])%MOD;
		}

		cout << dp[n] ;
	}
}
 
