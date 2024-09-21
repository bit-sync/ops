all: tmp main

tmp:
	@mkdir cache

main: main.o
	@cc cache/main.o -o ops # Runs third
	@echo done

main.o: main.c
	@cc -c main.c -o cache/main.o # Runs second

# Typically blah.c would already exist, but I want to limit any additional required files

clean:
	@rm -rf cache
	@rm -r ops
	@echo done