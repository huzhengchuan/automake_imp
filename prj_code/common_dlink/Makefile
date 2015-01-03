
all: task


lib:oper_list.c
	gcc -c -o oper_list.o oper_list.c
main_lib:main.c
	gcc -c -o main.o main.c
task:lib main_lib
	gcc -o task  oper_list.o main.o

clean:
	rm *.o  task 
