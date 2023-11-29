CC=gcc -g
CFLAGS= -Wall -Werror -Wshadow 
CFILES = s21_calcul.c s21_back_for_credit_calculator.c tests.c
OBJ = $(CFILES:.c=.o)
ifeq ($(shell uname), Linux)
	CHKFLAGS=-lcheck -lrt -lpthread -lm -lsubunit
else
	CHKFLAGS=-lcheck
endif

all: clean linter s21_calcul.o s21_back_for_credit_calculator.o test gcov_report
		

clean:
	@find . -type f -name "*.a" -delete
	@find . -type f -name "*.o" -delete
	@find . -type f -name "*.out" -delete
	@rm -rf test *.html *.gcda *.gcno gcov_report *.css
	@rm -rf test test.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(CHKFLAGS)

test: $(OBJ)
	@echo 'test'
	$(CC) $(CFILES:.c=.o) -o $@ $(CHKFLAGS)
	./$@

gcov_report:
	@echo 'gcov_report'
	$(CC) $(CFLAGS) --coverage s21_calcul.c -c -o s21_calcul_coverage.o 
	$(CC) $(CFLAGS) --coverage s21_back_for_credit_calculator.c -c -o s21_back_for_credit_calculator.o
	$(CC) $(CFLAGS) tests.c -c -o test_coverage.o
	$(CC) s21_calcul_coverage.o s21_back_for_credit_calculator.o test_coverage.o -o $@ $(CHKFLAGS) -lgcov
	./$@
	gcovr --html --html-details -o report.html
	open report.html

linter:
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c
	@clang-format -n *.c
	@rm -f .clang-format

leaks:
	leaks -atExit -- ./test
.PHONY: clean linter test gcov_report

install:
	make -C build
	cp -rf build/Calculator.app /Users/$(USER)/Desktop

uninstall:
	rm -rf build/*.cpp build/*.o build/*.h build/Calculator.app /Users/$(USER)/Desktop/Calculator.app
