; 15. Write a function that reverses a list together with all its sublists elements, at any level.

; (reverseList '(1 2 3 (4 5 (6 A 7)))) => (((7 A 6) 5 4) 3 2 1)
(defun reverseList (x)
	(cond
		( (atom x) x )
		( (listp x) (mapcar 'reverseList (reverse x)) )
	)
)