#dvir.opa@gmail.com
CXX=g++
CXXFLAGS=-std=c++2a

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
MAIN = main.o
TESTS_SRCS = $(wildcard Test/*.cpp)
DEMO = demo

all : $(DEMO)

run : $(DEMO)
	./$(DEMO)

$(DEMO) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


testAlgo : $(OBJS) Test/test_Algorithms.cpp
	$(CXX) $(CXXFLAGS) $(filter-out main.o, $(OBJS)) ./Test/test_Algorithms.cpp -o  $@
#runtesta:./testAlgo

testGraph : $(OBJS) Test/test_graph.cpp
	$(CXX) $(CXXFLAGS) $(filter-out main.o, $(OBJS)) ./Test/test_graph.cpp -o  $@
#runtestg:./testGraph
valgrind: testAlgo
	valgrind ./testAlgo



clean: 
	rm -f $(DEMO) $(OBJS)


tidy:
	clang-tidy *.cpp -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,hicpp-*,performance-*,portability-*,readability-* --warnings-as-errors=* --
