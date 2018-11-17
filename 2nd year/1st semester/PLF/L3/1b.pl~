minOfTwo(X, Y, Y) :- X >= Y.
minOfTwo(X, Y, X) :- X < Y.

minList([], 0).
minList([H], H).
minList([H|T], R) :- minList(T, R2), minOfTwo(H, R2, R).

% same as remove max val
removeEl([], _, []).
removeEl([H|T], E, R) :- H =:= E, removeEl(T, E, R).
removeEl([H|T], E, R) :- H =\= E, removeEl(T, E, R2), R = [H|R2].

% this already removes duplicates without needing to call pointA
% (because removeEl removes all occurences of an element in a list)
sortInc([], []).
sortInc([H|T], R) :- minList([H|T], MINEL), removeEl([H|T], MINEL, NEWLST), sortInc(NEWLST, R2), R = [MINEL|R2].

%  [1, 2, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7]
pointB([], []).
pointB([H|T], R) :- is_list(H), sortInc(H, R2), pointB(T, R3), R = [R2|R3].
pointB([H|T], R) :- pointB(T, R2), R = [H|R2].
