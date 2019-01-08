; 11. Write a function to determine the depth of a list.

; I feel like this is a hacky way to do it
; When mapcar reaches an atom it returns the current level
; And I apply max on the resulting list to get the maximum depth of the list

(defun listDepthBack (tree level)
	(cond
		((atom tree) level)
		
		((listp tree) (apply 'max (mapcar(lambda (a) (listDepthBack a (+ 1 level))) tree)))
		;((listp tree) (mapcar(lambda (a) (listDepthBack a (+ 1 level))) tree))
	)
)

; (listDepth '(1 2 3 (4 5 6) (7) (8 (9)))) => 3
(defun listDepth (tree) (listDepthBack tree 0))
