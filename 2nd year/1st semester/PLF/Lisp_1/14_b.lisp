;  Write a function to return the product of all numerical atoms in a list, at any level
; (prod '(1 2 3 (1 2 a (3)))) => 36

(defun prod (lst)
	(cond
		( (NULL lst) 1)
		( (NUMBERP (CAR lst)) (* (CAR lst) ( prod (CDR lst) ) ) )
		( (LISTP (CAR lst)) (* ( prod (CAR lst) ) ( prod (CDR lst) ) ) )
		
		; ATOM returns true for numbers, too
		; that's why I have to put it last
		( ( ATOM (CAR lst) ) ( prod (CDR lst) ) )
	)
)
