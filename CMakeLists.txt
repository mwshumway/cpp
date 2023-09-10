cmake_minimum_required(VERSION 3.25)
project(CS235)

set(CMAKE_CXX_STANDARD 17)

add_executable(CS235 Basics/calculator.cpp Basics/numbers_divisible_by.cpp Basics/longest_line.cpp Basics/reformat.cpp Basics/head.cpp Basics/sort.cpp STL-Structures/uniq.cpp STL-Structures/VectorSet.cpp STL-Structures/pqueues.cpp Sorts/Maze/maze.cpp Sorts/insertion_sort.cpp Sorts/QS.h Lists/singly_linked_list.h Lists/doubly_linked_list.h Lists/Vector.h Lists/vector_iterators.h Trees/BST.h Trees/AVL_rebalance.h Trees/AVL.h HashTables/HashSet.h)
