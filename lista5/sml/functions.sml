(* how to run: *)
(*   sml *)
(*   use "functions.sml"; *)
(*   functionName(arg1, arg2, ..., argN); *)

(* list is [num1, num2, ..., numN] *)

(*how to quit: *)
(*   ctrl + D *)

(* helper functions *)
fun intSqrt(n: int): int = floor (Math.sqrt (Real.fromInt n))

fun rowPascalsTriangle(n: int): int list =
    if n < 0 then [~1]
    else if n = 0 then [1]
    else let
        val previousRow = rowPascalsTriangle(n - 1)
        val rowWithZeroFront = 0 :: previousRow
        val rowWithZeroBack = previousRow @ [0]
    in
        ListPair.map op+ (rowWithZeroFront, rowWithZeroBack)
    end

fun merge([], ys) = ys
  | merge(xs, []) = xs
  | merge(x::xs, y::ys) =
      if x <= y then x :: merge(xs, y::ys)
      else y :: merge(x::xs, ys)

fun gcdExtended(0, b) = (b, 0, 1)
  | gcdExtended(a, b) =
      let
          val (g, x1, y1) = gcdExtended (b mod a, a)
      in
          (g, y1 - (b div a) * x1, x1)
      end

fun isPrime(n: int): bool =
    let
        fun isDivisible(n: int, currentDivisor: int): bool =
            if currentDivisor > intSqrt(n) then false
            else if n mod currentDivisor = 0 then true
            else isDivisible(n, currentDivisor + 1)
    in
        n >= 2 andalso not(isDivisible(n, 2))
    end

fun smallestDivisor(n: int, start: int): int =
    let
        val limit = intSqrt(n)
        fun findDivisor(current: int): int =
            if current > limit then n
            else if n mod current = 0 then current
            else findDivisor(current + 1)
    in
        findDivisor(start)
    end

fun factorize(n: int, d: int): int list =
    if n < 2 then []
    else if isPrime n then [n]
    else if n mod d = 0 then d :: factorize(n div d, d)
    else factorize(n, smallestDivisor(n, d + 1))

fun gcd(a: int, b: int): int =
    if b = 0 then a else gcd(b, a mod b)

fun removeDuplicates([]) = []
  | removeDuplicates(x::xs) = x :: removeDuplicates(List.filter (fn y => y <> x) xs)

fun product([]) = 1.0
  | product(x::xs) = x * product(xs)

fun primesHelper(n: int, i: int): int list =
    if n <= 1 then []
    else if isPrime i then i :: primesHelper(n - 1, i + 1)
    else primesHelper(n - 1, i + 1)



(* 1. binomial(n, k); *)(* faster *)
fun binomial(n: int, k: int): int =
    if n < 0 orelse k < 0 orelse k > n 
    then ~1
    else if k = 0 orelse n = k 
        then 1
        else 
        binomial(n - 1, k) + binomial(n - 1, k - 1)

(* 2. binomial2(n, k); *)(* slower *)
fun binomial2(n: int, k: int): int =
    if n < 0 orelse k < 0 orelse k > n then ~1
    else List.nth(rowPascalsTriangle(n), k)

(* 3. mergeSort(L);*)
fun mergeSort([]) = []
  | mergeSort([x]) = [x]
  | mergeSort(xs) =
      let
          val halfListLength = length(xs) div 2
          val firstHalf = List.take(xs, halfListLength)
          val secondHalf = List.drop(xs, halfListLength)
      in
          merge(mergeSort(firstHalf), mergeSort(secondHalf))
      end

(* 4. diophantineEq(a, b); *)
fun diophantineEq(a: int, b: int): (int * int * int) =
    let
        val (g, x, y) = gcdExtended(abs(a), abs(b))
        val x0 = if a >= 0 then x else ~x
        val y0 = if b >= 0 then y else ~y
    in
        (x0, y0, g)
    end

(* 5. primeFactors(n); *)
fun primeFactors(n: int): int list = factorize(n, 2)

(* 6. totient(n); *)(* slower *)
fun totient(n : int) : int =
        let
            fun countCoPrimes(0, counter) = counter
                | countCoPrimes(i, counter) =
                    if gcd(n, i) = 1 then countCoPrimes(i - 1, counter + 1)
                    else countCoPrimes(i - 1, counter)
        in
            countCoPrimes(n, 0)
        end;

(* 7. totient2(n); *)(* faster *)
fun totient2(n: int): int =
    let
        val factors = List.map Real.fromInt (removeDuplicates (primeFactors n))
    in
        floor ((Real.fromInt n) * (product (map (fn p => (1.0 - (1.0 / p))) factors)))
    end

(* 8. primes(n); *)
fun primes(n: int): int list = primesHelper(n, 2)






