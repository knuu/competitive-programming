N = int(input())
tweet = input()[:-1].split()

checkWords = ['TAKAHASHIKUN', 'Takahashikun', 'takahashikun']
print(sum([1 for w in tweet if w in checkWords]))
