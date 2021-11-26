CC = clang
C_OPTS = -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
check:
	clang-format --verbose -dry-run --Werror src/*
	cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1  -v --suppress=unreadVariable:*/main.c --suppress=knownConditionTrueFalse:*/main.c --check-config  --suppress=unmatchedSuppression:*/main.c .

all: clean prep compile check

# TODO: clang-tidy; scan-build
