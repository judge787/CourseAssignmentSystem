judgeJashanA1: judgeJashanA1.o judgeJashanA1Main.o 
	gcc -Wall -std=c99 judgeJashanA1.o judgeJashanA1Main.o -lm -o judgeJashanA1

judgeJashanA1.o: judgeJashanA1.c  givenA1.h
	gcc -Wall -std=c99 -c judgeJashanA1.c

judgeJashanA1Main.o: judgeJashanA1Main.c givenA1.h
	gcc -Wall -std=c99 -c judgeJashanA1Main.c

clean:
	rm *.o judgeJashanA1
