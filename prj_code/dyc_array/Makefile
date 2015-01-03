
all: task


lib:dyc_array.c
	gcc -c -o dyc_array.o dyc_array.c
main_lib:main.c
	gcc -c -o main.o main.c
task:lib main_lib
	gcc -o task  dyc_array.o main.o

clean:
	rm *.o  task 
