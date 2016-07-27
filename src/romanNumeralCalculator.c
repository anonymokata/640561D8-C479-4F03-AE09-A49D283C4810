#include <string.h>

char *romanSymbols[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI"};
int romanSymbolLength[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2, 1, 2};

int romanToDecimal(char *roman) {
	for(int i=1; i<=11; ++i) {
		if (!strcmp(roman, romanSymbols[i])) {
			return i;
		}
	}
}

size_t decimalToRoman(int decimal, char *decimalBuffer, size_t decimalBufferLength) {
	if(romanSymbolLength[decimal] <= decimalBufferLength){
		strncpy(decimalBuffer, romanSymbols[decimal], decimalBufferLength);
	}
	return romanSymbolLength[decimal];
}

size_t addRomanNumerals(char *term1, char *term2, char *sumBuffer, size_t sumBufferLength) {
	int term1Decimal = romanToDecimal(term1);
	int term2Decimal = romanToDecimal(term2);
	int sumDecimal = term1Decimal + term2Decimal;

	size_t usedSumBufferLength = decimalToRoman(sumDecimal, sumBuffer, sumBufferLength);

	return usedSumBufferLength;
}
