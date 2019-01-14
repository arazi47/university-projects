; Sa se elimine toate aparitiile unui element E dintr-o lista neliniara

(defun removeE (lst e)
	(cond
		((null lst) nil)
		((and (numberp (car lst)) (= (car lst) e)) (removeE (cdr lst) e))
		((listp (car lst)) (cons (removeE (car lst) e) (removeE (cdr lst) e)))
		(T (cons (car lst) (removeE (cdr lst) e)))
	)
)

(print (removeE '(1 2 3 (3 4 3) (3)) 3)) ; => (1 2 (4) NIL)

; Se da o lista neliniara
; Sa se scrie un program LISP pentru determinarea numarului
; de subliste de la orice nivel pentru care suma atomilor
; numerici de la nivelurile impare este numar par
; nivelul superficial al listei se considera 1.
; Prelucrarea se va face folosind o functie MAP

(defun sum (lst)
	(cond
		((null lst) 0)
		((numberp (car lst)) (+ (car lst) (sum (cdr lst))))
		;((listp (car lst)) (+ (sum (car lst)) (sum (cdr lst))))
		(T (sum (cdr lst)))
	)
)

(defun sum2 (elem)
	(cond
		((numberp elem) elem)
		(T (apply '+ (mapcar 'sum2 elem)))
	)
)

(defun parity (num)
	(cond
		(( = (mod num 2) 0) 1)
		(T 0)
	)
)

(defun solve (elem)
	(cond
		((atom elem) 0)
		
		; if it's not an atom, then it's a list
		(( = (parity (sum elem)) 1) (+ 1 (apply '+ (mapcar 'solve elem))))
		(T (mapcar 'solve elem))
	)
)

(defun main (lst)
	(cond
		(T (sum2 (solve lst)))
	)
)