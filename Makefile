CC = g++
EXE = main.exe
OBJS = main.o utils.o sorting/MergeSort.o sorting/HeapSort.o

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

%.o : %.cpp
	$(CC) -c -o $@ $<

clean :
	rm $(EXE) $(OBJS)
