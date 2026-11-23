CC := gcc

unamed_pipe_test:unamed_pipe_test.c
	-$(CC) -o $@ $^
	-./$@ "test"
	-rm ./$@

fifo_write_test:fifo_write_test.c
	-$(CC) -o $@ $^

fifo_read_test:fifo_read_test.c
	-$(CC) -o $@ $^

shared_memory:shared_memory.c
	-$(CC) -o $@ $^
	-./$@ "test"
	-rm ./$@

