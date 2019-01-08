; 16. Write a function that produces the linear list of all atoms of a given list, from all levels
; and written in the same order. Eg.: (((A B) C) (D E)) --> (A B C D E)

; (linearizeList '(1 2 (3 A (B 4 (C))))) => (1 2 3 A B 4 C)
(defun linearizeList (elem)
	(cond
		; atom
		; If we don't write (list elem),
		; only the last element will be returned (that is C)
		; This is needed when working with mapcan
		((atom elem) (list elem))
		
		; list
		((listp elem) (mapcan 'linearizeList elem))
	)
)
