main: main.cpp list.cpp HotelTracer.cpp files.cpp
	g++ main.cpp list.cpp HotelTracer.cpp files.cpp -Wall -pedantic -o main

#test: binary_search_tree.cpp tree_test.cpp
#	g++ binary_search_tree.cpp tree_test.cpp -Wall -pedantic -o tree_test

main_cov: list.cpp HotelTracer.cpp test.cpp files.cpp
	g++ test.cpp list.cpp HotelTracer.cpp files.cpp -fprofile-arcs -fprofile-arcs -ftest-coverage -lgcov -g -o test