# Makefile组成：
# target: prerequisites
# <TAB>command

obj := main.o \
	hello.o

# 第一个是默认目标
main:$(obj)
	gcc $(obj) -o main

main.o:hello.h
	gcc -c main.c -o main.o

hello.o:hello.h
	gcc -c hello.c -o hello.o

clean:
	rm main $(obj)
