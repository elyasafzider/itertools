#!make -f

CXX=clang++-10 
CXXFLAGS=-std=c++2a

HEADERS=accumulate.hpp compress.hpp filterfalse.hpp range.hpp
OBJECTS=
# NOTE: there are no objects -- all code is in the header files, since this is template code! 

run: test
	./$^

# demo: Demo.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o Test_snir.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o test
