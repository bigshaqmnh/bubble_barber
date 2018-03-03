#Makefile для проекта new

launch: main.o calculating.o desktop.o allinone.o queue.o exception.o exception_i.o
	g++ -o launch main.o calculating.o desktop.o allinone.o queue.o exception.o exception_i.o

calculating.o: CalculatingMachine.cpp
	g++ -o calculating.o -c CalculatingMachine.cpp

desktop.o: DesktopComputer.cpp
	g++ -o desktop.o -c DesktopComputer.cpp

allinone.o: AllInOne.cpp
	g++ -o allinone.o -c AllInOne.cpp

queue.o: Queue.cpp
	g++ -o queue.o -c Queue.cpp

exception_i.o: Exception_input.cpp
	g++ -o exception_i.o -c Exception_input.cpp

exception.o: Exception.cpp
	g++ -o exception.o -c Exception.cpp

clean:
	rm -f *.o launch
