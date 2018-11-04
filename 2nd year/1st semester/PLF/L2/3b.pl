maxOfTwo(X, Y, X) :-
    X >= Y.
maxOfTwo(X, Y, Y) :-
    X < Y.

maxL([], 0).
maxL([X], X).
maxL([H | T], X) :-
    maxL(T, I),
        maxOfTwo(H, I, X).

% Counts the number of times Element appears in List
% noElems(List, Element, Result)
% noElems(i, i, o)
noElems([], _, 0).
noElems([H|T], E, R) :- H =\= E, noElems(T, E, R).
noElems([H|T], E, R) :- H =:= E, noElems(T, E, R2), R is R2 + 1.

% rmv backend
% removeMaxVal(List, Element, Result)
% removeMaxVal(i, i, o)
removeMaxVal([], _, []).
removeMaxVal([H|T], E, R) :- H =:= E, removeMaxVal(T, E, R).
removeMaxVal([H|T], E, R) :- H =\= E, removeMaxVal(T, E, R2), R = [H|R2].

% remove max value wrapper
rmv(LST, R) :- maxList(LST, MAXEL), removeMaxVal(LST, MAXEL, R2), R = R2.


% same as remove max val
removeEl([], _, []).
removeEl([H|T], E, R) :- H =:= E, removeEl(T, E, R).
removeEl([H|T], E, R) :- H =\= E, removeEl(T, E, R2), R = [H|R2].

removeAllRepetitive([], []).
removeAllRepetitive([H|T], R) :- noElems([H|T], H, ECNT), ECNT > 1, removeEl([H|T], H, RESLST), removeAllRepetitive(RESLST, R), R = RESLST.
removeAllRepetitive([H|T], R) :- noElems([H|T], H, ECNT), ECNT =:= 1, removeAllRepetitive(T, R2), R = [H|R2].

maxList([], 0).
maxList([H], H).
maxList([H|T], R) :- maxList(T, R2), maxOfTwo(H, R2, R).
