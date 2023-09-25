#!/bin/python3

n = int(input())

A = [int(input()) for _ in range(n)]
A.sort(reverse=True)

H = 0
for i in range(n):
    if A[i] >= i+1:
        H = i+1

print(H)
