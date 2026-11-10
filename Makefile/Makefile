# Makefile组成：
# target: prerequisites
# <TAB>command

# 第一个是默认目标
main:main.o hello.o
	gcc main.o hello.o -o main

main.o:hello.h
	gcc -c main.c -o main.o

hello.o:hello.h
	gcc -c hello.c -o hello.o

clean:
	rm main main.o hello.o
