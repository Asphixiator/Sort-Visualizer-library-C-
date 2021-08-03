This is a light weight library that can visualize a sorting algorithm passed to the visualizer
Make sure to inlcude the correct path for the library.
For ease of use, write codes in the same folder

INSTRUCTIONS

//For compiling and generating object file for the program
g++ -c <filename>

//For compiling with the sort visualizer library
g++ -o quicksort quicksort.o lib_sort_visualizer.a -lglut -lGL -lGLU
