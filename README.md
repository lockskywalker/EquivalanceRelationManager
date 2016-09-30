# EquivalanceRelationManager
Use an array to store the bosses. Write the following functions.

newER(n) returns an array of n+1 integers. Allocate the array in the heap. This array will be used to store the bosses. So, if R has type ER then R[x] is x's boss. (Notice that the C++ notation, R[x], is a little different from what was used above, boss[x].)

In C++, arrays start at index 0. You will use indices 1, … n, so you need to allocate n+1 slots. (Index 0 will not be used.)

Initialize the array so that each value is a leader of its own group. That is, each value is its own boss.

leader(R, x) is the leader of x in equivalence relation R. To compute x's leader, just follow the bosses up to the leader. (You can recognize the leader because its boss is itself.) You are required to use this function any time you want to find the leader of a value.

equivalent(R, x, y) returns true if x and y are currently in the same equivalence class in equivalence relation R. (They are in the same equivalence class if they have the same leader.)

merge(R, x, y) merges the equivalence classes of x and y in R as follows. First, it finds the leaders x′ and y′ of x and y. If x′ and y′ are different (so x and y are not already in the same equivalence class) then y′ becomes the new boss of x′. (How can you changes x′'s boss? So y′ becomes the leader of the combined equivalence class.

destroyER(R) deallocates R.

showER(R, n) prints the entire contents of array R (of size n) in a readable form for debugging.
