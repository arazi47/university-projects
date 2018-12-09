; Build a list which contains positions
; of a minimum numeric element from a given linear list

; Don't call this one
(defun minListBack (lst currMin)
	( cond
		( (null lst) currMin )
		( (and (numberp (car lst)) (< (car lst) currMin)) ( minListBack (cdr lst) (car lst) ) )
		( (minListBack (cdr lst) currMin) )
	)
)

; Wrapper for minListBack
(defun minList (lst)
	(cond
		( (minListBack (cdr lst) (car lst)) )
	)
)


; Don't call this one
(defun indexEInListBack (e lst currIndex)
	(cond
		( (null lst) () )
		( (equal e (car lst)) (cons currIndex (indexEInListBack e (cdr lst) (+ currIndex 1))) )
		( (indexEInListBack e (cdr lst) (+ currIndex 1)) )
	)
)

; (indexEInList '(1 2 3 1 4 5 1)) => (0 3 6)
(defun indexEInList (lst)
	(cond
		((indexEInListBack (minList lst) lst 0))
	)
)