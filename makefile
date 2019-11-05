hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/sayi.o -c ./src/Sayi.cpp
	g++ -I ./include/ -o ./bin/test ./lib/sayi.o ./src/test.cpp

calistir:
	./bin/test
