# A

1x + 2x + 4x ... (2^(k-1))x is equal to (2^(k-1) - 1)x

Since input n is less than or equal to 10^9, k is must be less 30.

It can be solved by brute force.

# B

If n devide by 2 is equal to odd number, always cannot make balanced array.

Because odd numbers - even numbers is only odd number.

That's it and add difference to last of odd numbers

# C

When need to find a negative number, select a minimum number in a negative subsequence.

When need to find a positive number, select a maximum number in a positive subsequence.

First, select a first number as a positive integer.

Second, select a first number as a negative integer.

Finally, compare each length of both array or each sum of array.
