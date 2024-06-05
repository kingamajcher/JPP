import Data.List

-- 1. binomial n k -- faster
binomial :: Int -> Int -> Int
binomial n k
  | n < 0 || k < 0 || k > n = -1
  | k == 0 || n == k = 1
  | otherwise = binomial (n - 1) k + binomial (n - 1) (k - 1)


-- 2. binomial2 n k -- slower
binomial2 :: Int -> Int -> Int
binomial2 n k
  | n < 0 || k < 0 || k > n = -1
  | otherwise = rowPascalsTriangle n !! k


-- 3. mergeSort L
mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs =
  let (firstHalf, secondHalf) = splitAt (length xs `div` 2) xs
  in merge (mergeSort firstHalf) (mergeSort secondHalf)


-- 4. diophantineEq a b
diophantineEq :: Int -> Int -> (Int, Int, Int)
diophantineEq a b =
  let (g, x, y) = gcdExtended (abs a) (abs b)
      x0 = if a >= 0 then x else -x
      y0 = if b >= 0 then y else -y
   in (x0, y0, g)


-- 5. primeFactors n
primeFactors :: Int -> [Int]
primeFactors n = factorize n 2


-- 6. totient n -- slower
totient :: Int -> Int
totient n = length [x | x <- [1 .. n], gcd n x == 1]


-- 7. totient2 n -- faster
totient2 :: Int -> Int
totient2 n = floor (fromIntegral n * product [1 - (1 / fromIntegral p) | p <- nub (primeFactors n)])


-- 8. primes n
primes :: Int -> [Int]
primes n = [x | x <- [2 .. n], isPrime x]


-- additional functions used in implementation
rowPascalsTriangle :: Int -> [Int]
rowPascalsTriangle n
  | n < 0 = [-1]
  | n == 0 = [1]
  |otherwise = zipWith (+) ([0] ++ rowPascalsTriangle (n - 1)) (rowPascalsTriangle (n - 1) ++ [0])


merge :: Ord a => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys)
  | x <= y    = x : merge xs (y:ys)
  | otherwise = y : merge (x:xs) ys


gcdExtended :: Int -> Int -> (Int, Int, Int) -- returns (gcd, x, y)
gcdExtended 0 b = (b, 0, 1)
gcdExtended a b =
  let (gcd, x, y) = gcdExtended (b `mod` a) a
   in (gcd, y - (b `div` a) * x, x)


intSquareRoot :: Int -> Int
intSquareRoot = floor . sqrt . fromIntegral


isPrime :: Int -> Bool
isPrime n
  | n < 2 = False
  | otherwise = null [ x | x <- [2 .. intSquareRoot n], n `mod` x == 0 ]


smallestDivisor :: Int -> Int -> Int
smallestDivisor n start = head [ x | x <- [start .. intSquareRoot n], n `mod` x == 0 ]


factorize :: Int -> Int -> [Int]
factorize n d
  | n < 2           = []
  | isPrime n       = [n]
  | n `mod` d == 0  = d : factorize (n `div` d) d
  | otherwise       = factorize n (smallestDivisor n (d + 1))

-- how to run:
--   ghci functions.hs
--   functionName arg1 arg2 ... argNbi

-- list is [num1, num2, num3, ..., numN]

-- how to quit:
--   :q