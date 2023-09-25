#!/usr/bin/env python

occur = {}
freq = {}

for line in range(int(raw_input())):
    msg = raw_input().split(' ')
    user = msg.pop(0)
    if user not in occur:
        occur[user] = []
    for i in msg:
        if i not in freq:
            freq[i] = 0
        freq[i] += 1
    occur[user] += msg

res = None
for words in occur.values():
    if res is None:
        res = set(words)
    else:
        res.intersection_update(set(words))

for i in sorted(res, key=lambda x: (-freq[x], x)):
    print i

if len(res) == 0:
    print 'ALL CLEAR'

