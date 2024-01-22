import random
cases = random.randint(15,40)
print(cases)

def generate_random_string():
    # You can add more characters based on your requirements
    characters = 'abcdefghijklmnopqrstuvwxyz'
    length = random.randint(1, 10)  # random length of the string between 1 and 5
    return ''.join(random.choice(characters) for _ in range(length))

words = []
for i in range(8,13):
    words.append(generate_random_string())

i = 1
while i<=cases:
    print(words[random.randint(0,len(words)-1)]+" : ",end='')
    for j in range(random.randint(2,5)):
        print(words[random.randint(0,len(words)-1)],end=' ')
    print()
    i+=1
print(words[random.randint(0,len(words)-1)])