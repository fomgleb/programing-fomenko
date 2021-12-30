CC = clang

all: clean prepare format check compile

clean:
	rm -rf dist

prepare:
	mkdir dist

format:
	clang-format -i src/main.c src/lib.c

check:
	clang-format --verbose -dry-run --Werror src/*
	cppcheck --enable=all --inconclusive --addon=cert \
		--error-exitcode=1 -v --suppress=unreadVariable:*/main.c \
		--suppress=knownConditionTrueFalse:*/main.c --suppress=missingIncludeSystem \
		--check-config --suppress=unmatchedSuppression:*/main.c .
	rm -rf src/*.dump

compile: main.bin

main.bin: src/main.c src/lib.c
	$(CC) src/main.c src/lib.c -g -o dist/main.bin

doxygen:
	doxygen Doxyfile