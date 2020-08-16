FLAGS=##``
LIBS=##``
OPTION=##
CXX = clang++
##CXXFLAGS = -v -Wall -c -stdlib=libc++ -std=c++11 -lm $(FLAGS) $(OPTION)
CXXFLAGS = -v -Wall -g -o0 -c -stdlib=libc++ -std=c++11 -lm $(FLAGS) $(OPTION)
LDFLAGS = $(LIBS) $(OPTION)
TARGET=%.cpp %.hpp makefile
OBJS=UVWTrans.o CrossRoller.o  UVWStage.o
EXE = MyApp

%.o:$(TARGET)
	$(CXX) $(CXXFLAGS) $< -o $@

$(EXE): $(OBJS)
	$(CXX) -g  -o0 $(LDFLAGS) $^ -o $@

run: ${EXE} makefile
	./${EXE}

clean:
	rm -vrf *.o && rm $(EXE)