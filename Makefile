CXX = g++
CXXFLAGS = -std=c++17 -O2

all: test_DyV testCambio testMochila

test_DyV: test_DyV.cpp DyV.h
	$(CXX) $(CXXFLAGS) -o test_DyV test_DyV.cpp

testCambio: monedas.cpp
	$(CXX) $(CXXFLAGS) -o testCambio monedas.cpp

testMochila: mochila.cpp
	$(CXX) $(CXXFLAGS) -o testMochila mochila.cpp

run_all: test_DyV testCambio testMochila
	./test_DyV
	./testCambio
	./testMochila

clean:
	rm -f test_DyV testCambio testMochila DyV.h.gch

