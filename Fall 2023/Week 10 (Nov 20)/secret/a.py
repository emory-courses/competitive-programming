import os
import time
for i in range(1, 100):
    os.system(f'python3 gen_in.py > {i}.in')
    time.sleep(0.03)
    os.system(f'python3 bookoo.py < {i}.in > {i}.out')
