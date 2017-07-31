smsh1: smsh1.o execute.o splitline.o process.o controlflow.o varlib.o buildin.o
				cc -o smsh smsh1.o execute.o splitline.o process.o controlflow.o varlib.o buildin.o
smsh1.o: smsh1.c smsh.h varlib.h
					cc -c smsh1.c
varlib.o: varlib.c varlib.h
					cc -c varlib.c
execute.o: execute.c varlib.h
						cc -c execute.c
splitline.o: splitline.c smsh.h
							cc -c splitline.c
process.o: process.c smsh.h
						cc -c process.c
controlflow.o: controlflow.c smsh.h
								cc -c controlflow.c
buildin.o: buildin.c smsh.h varlib.h
					cc -c buildin.c
clean:
				rm *.o
