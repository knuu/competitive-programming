import sequtils
let c = stdin.readline
echo(if "aiueo".anyIt(c[0] == it): "vowel" else: "consonant")
