vector: vector.o
	g++ -o vector 2_uzduotis_vector.cpp vector.o
list: list.o
	g++ -o list 2_uzduotis_list.cpp list.o
deque: deque.o
	g++ -o deque 2_uzduotis_deque.cpp deque.o
funkcijos:
	g++ -c function.cpp
valymas:
	rm *.o blogi.txt geri.txt vector deque list generavimas
generavimas: generating.o
	g++ -o generavimas generavimas.cpp generating.o
	./generavimas