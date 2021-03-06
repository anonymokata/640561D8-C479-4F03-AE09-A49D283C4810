test: testRomanNumeralCalculator
	./test/testRomanNumeralCalculator

testmem: testRomanNumeralCalculator
	valgrind --leak-check=yes ./test/testRomanNumeralCalculator

testRomanNumeralCalculator: .checkmk
	gcc ./test/testRomanNumeralCalculator.c ./src/romanNumeralCalculator.c -std=c90 -g -O0 -lcheck -lc -lm -o ./test/testRomanNumeralCalculator

.checkmk: ./test/testRomanNumeralCalculator.check
	checkmk ./test/testRomanNumeralCalculator.check > ./test/testRomanNumeralCalculator.c

clean :
	rm -f ./romanNumeralCalculator.o ./testRomanNumeralCalculator.o
	rm -f ./test/testRomanNumeralCalculator ./test/testRomanNumeralCalculator.c
