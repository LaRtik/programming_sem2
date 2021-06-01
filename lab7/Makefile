main: main.cpp list.cpp HotelTracer.cpp
	g++ main.cpp list.cpp HotelTracer.cpp -Wall -pedantic -o main

#test: binary_search_tree.cpp tree_test.cpp
#	g++ binary_search_tree.cpp tree_test.cpp -Wall -pedantic -o tree_test

main_cov: main.cpp list.cpp HotelTracer.cpp test.cpp
	g++ test.cpp main.cpp list.cpp HotelTracer.cpp -Dmain=codsfksofdsko -fprofile-arcs -fprofile-arcs -ftest-coverage -lgcov -g -o test