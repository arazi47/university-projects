; se da o lista formata din numere si atomi
; sa se determine lista elementelor divizibile cu 3 din lista initiala
; de la orice nivel, in ordine inversa si o singura data

; map, mapcar in principal

; flatten list and remove atoms that are not numbers
; flattenList(l1,...,ln) =
; { 0, N = 0 }
(defun flattenList (lst)
	(cond
		((null lst) nil)
		((numberp lst) (list lst))
		((listp lst) (mapcan 'flattenList lst))
	)
)

; appearsInLst(l1,...,ln, e) =
; { 0, N = 0 }
; { e, l1 == e }
; { appearsInLst(l2,...,ln, e), otherwise }
(defun appearsInLst (lst e)
	(cond
		((null lst) nil)
		(( = (car lst) e) e)
		(T (appearsInLst (cdr lst) e))
	)
)

; removv (l1,...,ln) = 
; { 0, N = 0 }
; { l1 U removv(l2,...ln), l1 % 3 == 0 }
; { removv(l2,...,ln) }
(defun removv (lst)
	(cond
		((null lst) nil)
		((= (mod (car lst) 3) 0) (cons (car lst) (removv (cdr lst))))
		(T (removv (cdr lst)))
	)
)

; reverseLst (l1, ..., ln) =
; { 0, N = 0 }
; { reverseLst(l2,...ln) U l1, otherwise }
(defun reverseLst (lst)
	(cond
		((null lst) nil)
		(t (append (reverseLst (cdr lst)) (list (car lst))))
	)
)

; makeSet (l1,..., ln) = 
; { 0, N = 0 }
; { l1 U makeSet(l2,...,ln), appearsInLst(l2,...,ln, l1) == l1 }
(defun makeSet (lst)
	(cond
		((null lst) nil)
		((appearsInLst (cdr lst) (car lst)) (makeSet (cdr lst)))
		(T (cons (car lst) (makeSet (cdr lst))))
	)
)

; (solve '(3 a (b 9 ( 9 c (6 (d 15) b 20)) 7))) => (15 6 9 3)
(defun solve (lst)
	(cond
		((null lst) nil)
		(T (makeSet (reverseLst (removv (flattenList lst)))))
	)
)