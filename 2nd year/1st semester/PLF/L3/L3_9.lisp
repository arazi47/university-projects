; 9. Write a function that removes all occurrences of an atom from any level of a list.

; (removeOccurence '(1 2 (3 4 2 (5 1 2)) 1 (2) 3) 2) => (1 NIL (3 4 NIL (5 1 NIL)) 1 (NIL) 3)
; The actual result should be (1 (3 4 (5 1)) 1 () 3)

; mapcar will always return a list of the same length we provided
; So, instead of the element being removed, we'll see it being replaced with NIL
; We can use mapcan, but that will also flatten the lists

(defun removeOccurence (elem elemToBeRemoved)
	(cond
		((and (atom elem) (/= elem elemToBeRemoved)) elem)
		((listp elem) (mapcar (lambda (x) (removeOccurence x elemToBeRemoved)) elem))
	)
)
