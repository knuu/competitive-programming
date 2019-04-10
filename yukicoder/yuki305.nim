import strutils

var
  pin = "0000000000"
  X: int
echo(pin)
X = stdin.readline.split[0].parseInt
proc main =
  if X == 10: return
  for i in 0..<10:
    for j in 1..9:
      var pin_t = pin
      pin_t[i] = chr(ord('0')+j)
      echo(pin_t)
      let X_t = stdin.readline.split[0].parseInt
      if X_t == 10:
        return
      elif X_t < X:
        break
      elif X_t > X:
        X = X_t
        pin = pin_t
        break
main()
