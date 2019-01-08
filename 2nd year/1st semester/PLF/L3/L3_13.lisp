; 13. Define a function that returns the depth of a tree represented as
; (root list_of_nodes_subtree1 ... list_of_nodes_subtreen)

; I feel like this is a hacky way to do it
; When mapcar reaches an atom it returns the current level
; And I apply max on the resulting list to get the maximum depth of the list

(defun treeDepthBack (tree level)
	(cond
		((atom tree) level)
		
		((listp tree) (apply 'max (mapcar(lambda (a) (treeDepthBack a (+ 1 level))) tree)))
		;((listp tree) (mapcar(lambda (a) (treeDepthBack a (+ 1 level))) tree))
	)
)

; (treeDepth '(A (B (C)) (D) (E (F)))) => 3
(defun treeDepth (tree) (treeDepthBack tree 0))
