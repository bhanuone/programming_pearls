## If memory were not scarce, how would you implement a sort in a language with libraries for representing and sorting sets?

- Since a Set contains a unique elements and no associated data with each element, though the memory were not scarce, We can use a Bitmap to represent the Set elements.
- Sorting can be done easily by traversing the bit map from left to right and checking for a set bit.
