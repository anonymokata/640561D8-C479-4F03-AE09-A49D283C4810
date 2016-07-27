#include <string.h>

int romanToDecimal(char *roman) {
	const char *romanSymbols[6];

	romanSymbols[1] = "I";
	romanSymbols[2] = "II";
	romanSymbols[3] = "III";
	romanSymbols[4] = "IV";
	romanSymbols[5] = "V";

	for(int i=1; i<=5; ++i) {
		if (!strcmp(roman, romanSymbols[i])) {
			return i;
		}
	}
}

size_t decimalToRoman(int decimal, char *decimalBuffer, size_t decimalBufferLength) {
	size_t usedDecimalBufferLength;

	if(decimal == 1) {
		usedDecimalBufferLength = 1;
		if(usedDecimalBufferLength <= decimalBufferLength){
			strncpy(decimalBuffer, "I", decimalBufferLength);
		}
	}
	else if(decimal == 2) {
		usedDecimalBufferLength = 2;
		if(usedDecimalBufferLength <= decimalBufferLength){
			strncpy(decimalBuffer, "II", decimalBufferLength);
		}
	}
	else if (decimal == 3) {
		usedDecimalBufferLength = 3;
		if(usedDecimalBufferLength <= decimalBufferLength){
			strncpy(decimalBuffer, "III", decimalBufferLength);
		}
	}
	else if (decimal == 4) {
		usedDecimalBufferLength = 2;
		if(usedDecimalBufferLength <= decimalBufferLength){
			strncpy(decimalBuffer, "IV", decimalBufferLength);
		}
	}
	else if (decimal == 5) {
		usedDecimalBufferLength = 1;
		if(usedDecimalBufferLength <= decimalBufferLength){
			strncpy(decimalBuffer, "V", decimalBufferLength);
		}
	}
	else if (decimal == 6) {
		usedDecimalBufferLength = 2;
		if(usedDecimalBufferLength <= decimalBufferLength){
			strncpy(decimalBuffer, "VI", decimalBufferLength);
		}
	}
	return usedDecimalBufferLength;
}

size_t addRomanNumerals(char *term1, char *term2, char *sumBuffer, size_t sumBufferLength) {
	int term1Decimal = romanToDecimal(term1);
	int term2Decimal = romanToDecimal(term2);
	int sumDecimal = term1Decimal + term2Decimal;

	size_t usedSumBufferLength = decimalToRoman(sumDecimal, sumBuffer, sumBufferLength);

	return usedSumBufferLength;
}
