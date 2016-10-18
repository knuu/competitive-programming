S = input()
hole = "ADOPQR"
print("yes" if all(S[x] not in "B"+hole for x in [0, 1, 3]) and S[2] in hole else "no")
