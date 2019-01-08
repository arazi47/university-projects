; 6. Write a function that returns the maximum of numeric atoms in a list, at any level.

; (naMax '(5 3 (8 A (B 2 (C))))) => 8
(defun naMax (elem)
	(cond
		; number
		((numberp elem) elem)
		
		; atom
		((atom elem) 0)
		
		; list
		((listp elem) (apply 'max (mapcar 'naMaxBack elem)))
		
	)
)
