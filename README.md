# Codam_libft

## Summary

This repository contains a library of functions used throughout my curriculum at Codam.  
It contains most of the [libft](https://github.com/jmolenaa/libft) functions, the [ft_printf](https://github.com/jmolenaa/ft_printf) function, the [get_next_line](https://github.com/jmolenaa/get_next_line) function and many more that I've coded myself.

## Compilation

To compile the library clone the repository, go into the folder and type make. To use it just link it during compilation including the header file.

### Added functions

Aside from the functions from my other projects this library also contains:
- several functions dealing with doubly linked lists, similar to the ones already in the library for singular lists
- functions dealing with arrays, including:
  - size of array
  - free array
  - array duplicate
  - insert into array
- multiple variants of strjoin that free either the first, second or both strings depending on need
- a calloc function that exits on malloc failure
- a free function that sets the given pointer to NULL
