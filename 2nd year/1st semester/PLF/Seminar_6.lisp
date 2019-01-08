; (triple '(1 2 3 (A 4))) => (3 6 9 (A 12))
(defun triple (x)
	(cond
		( (numberp x) (* 3 x) )
		( (atom x) x )
		( t (mapcar 'triple x) )
	)
)

; (product '(1 2 3 (A 4))) => 24
(defun product (x)
	(cond
		( (numberp x) x )
		( (atom x) 1 )
		( t (apply '* (mapcar 'product x)) )
	)
)

;;;;;;;;;;;;;;;;;;;
; Eliminam atomii si liniarizam lista
; (transform '(1 2 3 (A 5 4 (B 6 7)))) => (1 2 3 4 5 6 7)
(defun transform (lst)
	(cond
		((null lst) nil)
		((numberp (car lst)) (cons (car lst) (transform (cdr lst))))
		((atom (car lst)) (transform (cdr lst)))
		(t (append (transform (car lst)) (transform (cdr lst))))
	)
)

; Verificam daca primul element din lista e 5
(defun verif (lst)
	(cond
		((null (transform lst)) nil)
		((= (car (transform lst)) 5) T)
		(T nil)
	)
)

; Numara cate subliste au primul numar 5
; (poate sa aiba alti atomi in fata, cat timp nu sunt numere)
; (numara '(1 2 3 (A 5 4 (5 B 6 7)))) => 2
(defun numara (lst)
	(cond
		((atom lst) 0)
		((verif lst) (+ 1 (apply '+ (mapcar 'numara lst))))
		(T (apply '+ (mapcar 'numara lst)))
	)
)

;;;;;;;;;;;;;;;
; Numara nodurile de pe nivele pare
; (cntNodes '(A (B C))) => 2
(defun evenNodes (tree level)
	(cond
		((and (atom tree) (= (mod level 2) 0)) 1)
		((atom tree) 0)
		(T (apply '+ (mapcar(lambda (a) (evenNodes a (+ 1 level))) tree)))
	)
)

(defun cntNodes (tree) (evenNodes tree 0))
