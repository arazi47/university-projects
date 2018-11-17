% factorial(N: Int, R: Int)
% factorial(i, i, o)
factorial(0, 1).
factorial(N, R) :- N2 is N - 1, factorial(N2, R2), R is N * R2.

% inloc(LST: List, POZ: Int, R: List)
% inloc(i, i, o)
inloc([], _, []).
inloc([_|T], POZ, R) :- POZ mod 2 =:= 1, inloc(T, POZ + 1, R2), factorial(POZ, FACT), R = [FACT|R2].
inloc([H|T], POZ, R) :- inloc(T, POZ + 1, R2), R = [H|R2].

% main(LST: List, R: List)
% main(i, o)
main(LST, R) :- inloc(LST, 1, R).
