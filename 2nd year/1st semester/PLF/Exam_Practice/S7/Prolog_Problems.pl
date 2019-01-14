% 2 - remove all duplicates

cntElems([], _, 0).
cntElems([H|T], E, R) :-
    H =:= E,
    cntElems(T, E, R2),
    R is R2 + 1.
cntElems([_|T], E, R) :-
    cntElems(T, E, R).

makeSet([], []).
makeSet([H|T], R) :-
    cntElems([H|T], H, R2),
    R2 > 1,
    makeSet(T, R).
makeSet([H|T], R) :-
    makeSet(T, R2), R = [H | R2].

makeSet2([], ACC, ACC).
makeSet2([H|T], ACC, R) :-
    cntElems([H|T], H, R2),
    R2 > 1,
    makeSet2(T, ACC, R).
makeSet2([H|T], ACC, R) :-
    ACC2 = [H | ACC],
    makeSet2(T, ACC2, R).
