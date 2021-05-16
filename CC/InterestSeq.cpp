/*
Zanka finds fun in everyday simple things. One fine day he got interested in a very trivial sequence. Given a natural number k, he considers the sequence Ai=k+i2

so that the terms are

k+1,k+4,k+9,k+16,…

Now to make things more interesting, he considers the gcd
of consecutive terms in the sequence, then takes the sum of the first 2k

values. More formally, he wants to compute

∑i=12kgcd(Ai,Ai+1)

Denote this sum by S
. Zanka wants you to print the number S for each k

.
Input

    The first line contains an integer T

, the number of test cases. Descriptions of test cases follow.
The only line of each test case contains a single integer k

    .

Output

For each test case, output a single line containing the sum S
for the given k

.
Constraints

    1≤T≤106

1≤k≤106
*/
