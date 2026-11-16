CC := gcc

fork_test:fork_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fork_fd_test:fork_fd_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

target_exe:target_exe.c
	-$(CC) -o $@ $^

execve_test:execve_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fork_execve_test:fork_execve_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@





