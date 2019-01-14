% 1 - sum of first N natural numbers in two different ways

sumN(0, 0).
sumN(N, R) :-
    N2 is N - 1,
    sumN(N2, R2),
    R is N + R2.

sumN2(0, ACC, ACC).
sumN2(N, ACC, R) :-
    N2 is N - 1,
    ACC2 is N + ACC,
    sumN2(N2, ACC2, R).

% 2

listSum([], 0).
listSum([H | T], R) :-
    listSum(T, TR),
    R is TR + H.

ins(L, E, [E|L]).
ins([H|T], E, R) :- ins(T, E, R2), R = [H | R2].

perm([], []).
perm([H | T], R) :-
    perm(T, RT),
    ins(RT, H, R).

comb(_, 0, []).
comb([H | T], K, [H | TR]) :-
    K > 0,
    K1 is K - 1,
    comb(T, K1, TR).
comb([_ | T], K, R) :-
    K > 0,
    comb(T, K, R).

arr(L, K, R) :-
    comb(L, K, R1),
    perm(R1, R).

oneSolution(L, K, S, R) :-
    arr(L, K, R),
    listSum(R, S).

getPerm(L, R) :-
    findall(RL, perm(L, RL), R).

getComb(L, K, R) :-
    findall(RL, comb(L, K, RL), R).

getArr(L, K, R) :-
    findall(RL, arr(L, K, RL), R).

allSolutions(L, K, S, R) :-
    findall(RL, oneSolution(L, K, S, RL), R).

