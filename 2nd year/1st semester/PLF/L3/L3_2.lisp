; 2. Write a function that returns the sum of numeric atoms in a list, at any level.

; (naSum '(1 2 3 A B 4 (32 (5) (3) (1 (1)) C))) => 52
(defun naSum (elem)
	(cond
		; number
		((numberp elem) elem)
		
		; atom
		((atom elem) 0)
		
		; listp
		((listp elem) (apply '+ (mapcar 'naSum elem)))
	)
)