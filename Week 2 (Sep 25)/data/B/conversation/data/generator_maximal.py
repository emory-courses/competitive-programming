#!/usr/bin/env python
import random
import string

m = 10**4
print m

def gen_word(length):
    return ''.join(random.choice(string.ascii_lowercase) for i in range(length))

for i in range(m):
    username = 20
    message = (10**6) / m - username
    print gen_word(username) + ' ' + ' '.join(gen_word(1) for i in range(message))
