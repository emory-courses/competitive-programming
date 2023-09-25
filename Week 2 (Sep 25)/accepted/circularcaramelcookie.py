from math import floor, sqrt

def count(radius):
    ans = 0
    x = floor(radius)
    while x >= 1:
        ans += 4 * floor(sqrt(radius**2 - x**2))
        x -= 1
    return ans

s = int(input().strip())
l = 0
r = 100000
eps = 0.0000001

while r - l >= eps:
    mid = (l + r) / 2
    if count(mid) > s:
        r = mid
    else:
        l = mid

precision = 10
formatted_number = f"{l:.{precision}f}"
print(formatted_number)
