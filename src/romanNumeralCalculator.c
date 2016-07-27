#include <string.h>

int romanToDecimal(char *roman) {
	if(!strcmp(roman,"I")) {
		return 1;
	}
	else if (!strcmp(roman,"II")) {
		return 2;
	}
	else if (!strcmp(roman,"III")) {
		return 3;
	}
	else if (!strcmp(roman,"IV")) {
		return 4;
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
	return usedDecimalBufferLength;
}

size_t addRomanNumerals(char *term1, char *term2, char *sumBuffer, size_t sumBufferLength) {
	int term1Decimal = romanToDecimal(term1);
	int term2Decimal = romanToDecimal(term2);
	int sumDecimal = term1Decimal + term2Decimal;

	size_t usedSumBufferLength = decimalToRoman(sumDecimal, sumBuffer, sumBufferLength);

	return usedSumBufferLength;
}
