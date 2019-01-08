; 4. Write a function that returns the product of numeric atoms in a list, at any level.

; (naProduct '(1 2 (3 A (B 4 (C))))) => 24
(defun naProduct (elem)
	(cond
		; number
		((numberp elem) elem)
		
		; atom
		((atom elem) 1)
		
		; listp
		((listp elem) (apply '* (mapcar 'naProduct elem)))
	)
)