smsh1: smsh1.o execute.o splitline.o
				cc -o smsh smsh1.o execute.o splitline.o
smsh1.o: smsh1.c smsh.h
					cc -c smsh1.c
execute.o: execute.c
						cc -c execute.c
splitline.o: splitline.c smsh.h
							cc -c splitline.c
clean:
				rm *.o
