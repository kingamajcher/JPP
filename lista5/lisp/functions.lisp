;; how to run:
;;   clisp
;;   (load "functions.lisp")
;;   (functionName arg1 arg2 ... argN)

;; list is '(num1 num2 ... numN)

;; how to quit:
;;   (quit)

;; helper functions
(defun row-pascals-triangle (n)
  (cond ((< n 0) '(-1))
        ((= n 0) '(1))
        (t (mapcar #'+ (cons 0 (row-pascals-triangle (1- n)))
                        (append (row-pascals-triangle (1- n)) '(0))))))

(defun merge-lists (xs ys)
  (cond ((null xs) ys)
        ((null ys) xs)
        ((<= (car xs) (car ys)) (cons (car xs) (merge-lists (cdr xs) ys)))
        (t (cons (car ys) (merge-lists xs (cdr ys))))))

(defun gcd-extended (a b)
  (if (= a 0)
      (list b 0 1)
      (let* ((result (gcd-extended (mod b a) a))
             (g (first result))
             (x (second result))
             (y (third result)))
        (list g (- y (* (floor (/ b a)) x)) x))))

(defun int-square-root (n)
  (floor (sqrt n)))

(defun is-prime (n)
  (cond ((< n 2) nil)
        (t (null (remove-if-not (lambda (x) (= (mod n x) 0))
                                (number-sequence 2 (int-square-root n)))))))

(defun smallest-divisor (n start)
  (car (remove-if-not (lambda (x) (= (mod n x) 0))
                      (number-sequence start (int-square-root n)))))

(defun factorize (n d)
  (cond ((< n 2) nil)
        ((is-prime n) (list n))
        ((= (mod n d) 0) (cons d (factorize (/ n d) d)))
        (t (factorize n (smallest-divisor n (1+ d))))))

(defun number-sequence (start end)
  (loop for i from start to end collect i))



;; 1. (binomial n k) -- faster
(defun binomial (n k)
  (cond ((or (< n 0) (< k 0) (> k n)) -1)
        ((or (= k 0) (= n k)) 1)
        (t (+ (binomial (1- n) k)
              (binomial (1- n) (1- k))))))

;; 2. (binomial2 n k) -- slower
(defun binomial2 (n k)
  (if (or (< n 0) (< k 0) (> k n))
      -1
      (nth k (row-pascals-triangle n))))

;; 3. (merge-sort L)
(defun merge-sort (list)
    (let ((len (list-length list)))
    (cond ((null list) list)
          ((= len 1) list)
          (t (merge-lists (merge-sort (subseq list 0 (ceiling len 2))) (merge-sort (subseq list (ceiling len 2))))))))

;; 4. (diophantine-eq a b)
(defun diophantine-eq (a b)
  (let* ((result (gcd-extended (abs a) (abs b)))
         (g (first result))
         (x (second result))
         (y (third result))
         (x0 (if (>= a 0) x (- x)))
         (y0 (if (>= b 0) y (- y))))
    (list x0 y0 g)))

;; 5. (prime-factors n)
(defun prime-factors (n)
  (factorize n 2))

;; 6. (totient n) -- slower
(defun totient (n)
  (length (remove-if-not (lambda (x) (= (gcd n x) 1))
                         (number-sequence 1 n))))

;; 7. (totient2 n) -- faster
(defun totient2 (n)
    (nth-value 0 (floor (* n (reduce #'* (mapcar #'(lambda (p) (- 1 (/ 1 p))) (remove-duplicates (prime-factors n))))))))

;; 8. (primes n)
(defun primes (n)
  (remove-if-not #'is-prime (number-sequence 2 n)))




