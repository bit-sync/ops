tmp:
	mkdir cache
	make blah

blah: blah.o
	@cc cache/main.o -o ops # Runs third
	@echo done

blah.o: main.c
	@cc -c main.c -o cache/main.o # Runs second

# Typically blah.c would already exist, but I want to limit any additional required files

clean:
	rm -rf cache