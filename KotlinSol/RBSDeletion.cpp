/*
B. RBS Deletion
time limit per test3 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
A bracket sequence is a string containing only characters "(" and ")". A regular bracket sequence (or, shortly, an RBS) is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example:

bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)");
bracket sequences ")(", "(" and ")" are not.
You are given a string s, which is an RBS. You can apply any number of operations to this string. Each operation can have one of the following types:

choose some non-empty prefix of s and remove it from s, so s is still an RBS. For example, we can apply this operation as follows: "(())()(())()()" → "()()" (the first 10 characters are removed);
choose some contiguous non-empty substring of s and remove it from s, so s is still an RBS. For example, we can apply this operation as follows: "(())()(())()()" → "(())()()()" (the characters from the 7-th to the 10-th are removed).
The operation 2 can be applied at most k times. Calculate the maximum number of operations you can apply until s becomes empty.

Input
The first line contains one integer t (1≤t≤105) — the number of test cases.

Each test case is described by two lines. The first line contains two integers n and k (2≤n≤2⋅105; 1≤k≤n; n is even) — the length of s and the maximum number of operations of type 2 you can apply.

The second line contains a string s of n characters '(' and ')'. This string is an RBS.

The sum of n over all test cases doesn't exceed 2⋅105.

Output
For each test case, print one integer — the maximum number of operations you can apply.

Example
inputCopy
3
12 2
(()())((()))
6 3
()()()
8 1
(((())))
outputCopy
4
3
2

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
        var s=readLn()
        var ans=y
        var cnt=0
        for(ch in s){
        if(ch==')')
        cnt--
        else
        cnt++
        if(cnt==0)
        ans++
        }
        if(ans>x/2)
        ans=x/2
        println(ans)
    }
}
