GCC := g++ -Wall -Werror -Wextra -std=c++20 -lstdc++

all:
	$(GCC) AVLtree.cc -o AVLtree
	./AVLtree
vg:
	valgrind -s --log-file=mylog.txt --tool=memcheck --leak-check=yes ./AVLtree