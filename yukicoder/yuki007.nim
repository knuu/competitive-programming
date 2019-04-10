{.checks: off, optimization: speed.}
import strutils, sequtils
let N = stdin.readline.parseInt
var
  sieve = newSeq[bool](N+1)
  primes = newSeq[int]()
for i in 2..N:
  if not sieve[i]:
    primes.add(i)
    for j in countup(2 * i, N, i):
      sieve[j] = true

var dp = newSeq[bool](N+1)
dp[0] = true
dp[1] = true
for i in 2..N:
  for p in primes:
    if p > i:
      break
    dp[i] = dp[i] or not dp[i-p]
echo(if dp[N]: "Win" else: "Lose")
