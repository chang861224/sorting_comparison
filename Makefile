CC = g++
CPPFLAGS = -lm
EXE = main.exe
OBJS = main.o utils.o sorting/MergeSort.o sorting/HeapSort.o

$(EXE) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(EXE) $(OBJS)

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean :
	rm $(EXE) $(OBJS)
