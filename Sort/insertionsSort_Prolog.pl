insertion_sort([H|T], Result) :- insertion_sort(T, Sorted), insert(H, Sorted, Result),
write("insert "),
write(H), write(" : "),
write(Result),nl.
insertion_sort([], []) :- !.

insert(A, [B|L], [A, B|L]) :- A<B, !.
insert(A, [B|L], [B|R]) :- insert(A, L, R).
insert(X, [], [X]) :- !.