; 1. For a given tree of type (1) return the path from the root node to a certain given node X

; (transform '(A 2 B 0 C 2 D 0 E 0)) => (A (B) (C (D) (E)))
(defun transform(l)
  (if (null l)
      nil
      (tree-sequence l)))
		
(defun tree-sequence(l)
  (case (cadr l)
    (0 (values (list (car l)) (cddr l)))
    (1 (multiple-value-bind (left-subtree rest-of-list) (tree-sequence (cddr l))
          (values (list (car l) left-subtree) rest-of-list)))
    (t (multiple-value-bind (left-subtree rest-of-list) (tree-sequence (cddr l))
          (multiple-value-bind (right-subtree rest-of-rest) (tree-sequence rest-of-list)
             (values (list (car l) left-subtree right-subtree) rest-of-rest))))))

;  (path '(A (B) (C (D) (E))) 'D)  => (A C D)
(defun path (tree leaf)
  (cond ((null tree) nil)
        ((eq (car tree) leaf) (list leaf))
        (t (mapcan (lambda (subtree)
                     (let ((p (path subtree leaf))) 
                       (when p (cons (car tree) p))))
                   (cdr tree)))))
				   
; (path '(A 2 B 0 C 2 D 0 E 0) 'D) => (A C D)
(defun pathToX (tree leaf)
	(setq tree (transform tree))
	(cond
		((path tree leaf))
	)
)