/*
A. From Zero To Y
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two positive (greater than zero) integers x and y. There is a variable k initially set to 0.

You can perform the following two types of operations:

add 1 to k (i. e. assign k:=k+1);
add x⋅10p to k for some non-negative p (i. e. assign k:=k+x⋅10p for some p≥0).
Find the minimum number of operations described above to set the value of k to y.

Input
The first line contains one integer t (1≤t≤2⋅104) — the number of test cases.

Each test case consists of one line containing two integer x and y (1≤x,y≤109).

Output
For each test case, print one integer — the minimum number of operations to set the value of k to y.

Example
inputCopy
3
2 7
3 42
25 1337
outputCopy
4
5
20
Note
In the first test case you can use the following sequence of operations:

add 1;
add 2⋅100=2;
add 2⋅100=2;
add 2⋅100=2.
1+2+2+2=7.
In the second test case you can use the following sequence of operations:

add 3⋅101=30;
add 3⋅100=3;
add 3⋅100=3;
add 3⋅100=3;
add 3⋅100=3.
30+3+3+3+3=42.

*/
import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
    var tc = readInt()
    for (q in 0 until tc) {
        var (x, y) = readInts()
        var cnt=y%x
        var que=y/x
        while(que>0){
        cnt+=que%10
        que/=10
    }
    println(cnt)
    }
}
