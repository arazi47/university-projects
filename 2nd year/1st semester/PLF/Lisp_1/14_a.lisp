; Write a function to return the union of two sets
; (setUnion '(1 2 3) '(2 3 4) => (1 2 3 4)

; (inList '(1 2 3 4 5) 3) => 1
; (inList '(1 2 3 4 5) 10) => NIL
(defun inList (lst e)
	(cond
		( (NULL lst) nil )
		( (equal (CAR lst) e) 1)
		( (inList (CDR lst) e) )
	)
)

; (setUnion '(1 3 2) '(2 334 5 4)) => (334 5 4 1 3 2)
(defun setUnion (L1 L2)
	(cond
		( (NULL L2) L1 )
		( ( NOT (member (CAR L2) L1) ) (append (cons (CAR L2) (setUnion L1 (CDR L2)))) )
		( (setUnion L1 (CDR L2) ) )
	)
)
