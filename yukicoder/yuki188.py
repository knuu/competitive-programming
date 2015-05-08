print(sum([sum(1 for j in range([31,28,31,30,31,30,31,31,30,31,30,31][i]) if i+1 == sum(int(k) for k in str(j+1))) for i in range(12)]))
