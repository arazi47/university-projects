; Write a function to sort a linear list with keeping the double values

; removes e from lst
; only removes the first occurence
(defun removeFromList (e lst)
	(cond
		( (null lst) nil )
		
		; remove all occurences
		;( (equal e (car lst)) ( removeFromList e (cdr lst) ) )
		
		; remove only the first occurence
		( (equal e (car lst)) (cdr lst) )
		
		
		( (cons (car lst) ( removeFromList e (cdr lst) ) ) )
	)
)

; Don't call this one
(defun minListBack (lst currMin)
	( cond
		( (null lst) currMin )
		( (< (car lst) currMin) ( minListBack (cdr lst) (car lst) ) )
		( (minListBack (cdr lst) currMin) )
	)
)

; Wrapper for minListBack
(defun minList (lst)
	(cond
		( (minListBack lst 99999) )
	)
)

; (sortList '(5 4 3 2 1)) => (1 2 3 4 5)
(defun sortList (lst)
	(setq minL (minList lst))
	;(write lst)
	;(write minL)
	(setq lst (removeFromList minL lst))
	(cond
		( (null lst) (list minL) )
		;((and (not (null (car lst))) (null (cdr lst))) lst)
		( (cons minL (sortList lst) ) )
	)
)