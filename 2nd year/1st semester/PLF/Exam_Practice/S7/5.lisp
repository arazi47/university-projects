; flatten the list
(defun transform (lst)
	(cond
		((null lst) nil)
		((numberp (car lst)) (cons (car lst) (transform (cdr lst))))
		((atom (car lst)) (transform (cdr lst)))
		(t (append (transform (car lst)) (transform (cdr lst))))
	)
)

(defun maxList (lst)
	(cond
		((atom lst) lst)
		(t (apply 'max (mapcar 'maxList lst)))
	)
)

; Verificam daca elem max din lista e par
(defun verif (lst)
	(cond
		((null (transform lst)) nil)
		((= (mod (maxList (transform lst)) 2) 0) T)
		(T nil)
	)
)

; maximal numeric atom on all odd levels is even
(defun cntSubListe (lst level)
	(cond
		((atom lst) 0)
		((and (verif lst) (= (mod level 2) 1)) (+ 1 (apply '+ (mapcar(lambda (a) (cntSubListe a (+ 1 level))) lst))))
		(T (apply '+ (mapcar(lambda (a) (cntSubListe a (+ 1 level))) lst)))
	)
)

(defun solveMain (lst) (cntSubListe lst 1))
