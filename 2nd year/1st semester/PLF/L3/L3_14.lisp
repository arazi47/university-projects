; 14. Write a function that returns the number of atoms in a list, at any level

; (atomsCnt '(1 2 (3 A (B 4 (C))))) => 7
(defun atomsCnt (elem)
	(cond
		; atom
		((atom elem) 1)
		
		; listp
		((listp elem) (apply '+ (mapcar 'atomsCnt elem)))
	)
)
