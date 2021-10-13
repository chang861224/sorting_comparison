CC = g++
CPPFLAGS = -lm
EXE = main.exe
OBJS = main.o utils.o sorting/MergeSort.o sorting/HeapSort.o sorting/QuickSort.o sorting/BubbleSort.o sorting/InsertionSort.o

$(EXE) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(EXE) $(OBJS)

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean :
	rm $(EXE) $(OBJS)
