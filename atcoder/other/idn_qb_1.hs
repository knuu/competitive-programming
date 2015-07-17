main :: IO ()
main = do
  p1 <- getLine
  p2 <- getLine
  let [x1, y1] = map (\x -> read x :: Int) (words p1)
      [x2, y2] = map (\x -> read x :: Int) (words p2)
  print $ abs (x1 - x2) + abs (y1 - y2) + 1
