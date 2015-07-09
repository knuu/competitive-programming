while True:
    N = int(input())
    if not N: break
    seeds = []
    for i in range(N):
        plant = input().split()
        name, price = plant[0], int(plant[1])
        seed_to_leaf, leaf_to_fruit = sum(map(int, plant[2:5])), sum(map(int, plant[5:7]))
        num_per, sold, mult = int(plant[7]), int(plant[8]), int(plant[9])
        seeds.append((-(num_per * sold * mult - price) / (seed_to_leaf + leaf_to_fruit * mult), name))
    for _, name in sorted(seeds):
        print(name)
    print('#')
