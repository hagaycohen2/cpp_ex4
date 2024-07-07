# EX4 - Tamplates, GUI, Iterators
## Structure overview
The tree container is a Knary tree, which is a tree with a max k children for each node. The tree is implemented using a template class, which allows the user to define the type of data to be stored. The tree is implemented using a linked structure, where each node has a pointer to its parent and an array of pointers to its children. the Node class is implemented in `node.hpp` and the tree class is implemented in `tree.hpp`. 

## GUI
The GUI is implemented using the SFML library. The GUI allows the user to display the tree, considering the number of children each node has. This project hase a default font and scale values that can be modified for personal preference. 

The GUI draws the tree recursively, starting from the root node by using the `drawNode` function.

## Complex 
The complex class is implemented in `complex.hpp`. Each complex number is represented by two doubles, one for the real part and one for the imaginary part. The order of the complex numbers is determined by norm of the complex number. As shown in the `main.cpp` file, the complex numbers can be used in the tree class.

## Iterators
All the iterators are implemented in the `iterators.hpp` file. The iterators are implemented as classes.
### Index Iterator
The index iterator is a simple iterator that iterates over a node and its children. When the iterator is created with a suplied index, it will iterate over the children of the node from left to right and after iterating over index children, it will iterate over the root node and then the rest of the children. The iterator is implemented as a template class, which allows the user to define the type of data to be stored.

By using this iterator, we can iterate over the tree in a inorder traversal(index = k/2), preorder traversal(index = 0) or postorder traversal(index = k). where k is the order of the tree.
That means that any tree can be traversed in the three different ways by using the index iterator, and also change the index to traverse the tree in a different way.(eg. index = k/3).

### DFS Iterator
The DFS iterator is a depth first search iterator that iterates over the tree in a depth first search manner. The iterator is implemented as a template class, which allows the user to define the type of data to be stored.

### BFS Iterator
The BFS iterator is a breadth first search iterator that iterates over the tree in a breadth first search manner. The iterator is implemented as a template class, which allows the user to define the type of data to be stored.

### Min heap iterator
The min heap iterator is an iterator that iterates over the tree in a min heap manner. The iterator is implemented as a template class, which allows the user to define the type of data to be stored.
Note that for Complex numbers, the min heap is defined by the norm of the complex number.


## Gui screenshot
![alt text](<Screenshot 2024-07-07 134103.png>)

### Author
Hagay Cohen
Hagaycohen2@gmail.com
