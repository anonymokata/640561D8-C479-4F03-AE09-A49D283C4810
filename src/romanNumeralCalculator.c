#include <string.h>

char *onesRomanSymbols[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char *tensRomanSymbols[] = { "", "X"};
int romanSymbolLength[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
int symbolSearchOrder[] = {0, 9, 8, 7, 6, 4, 5, 3, 2, 1};

int romanToDecimal(char *roman) {
	char *foundRomanPointer;
	char *shiftingRomanPointer;
	int decimal = 0;
	int i;
	int symbolWasFound;

	shiftingRomanPointer = roman;

	symbolWasFound = 0;
	for(i=1; i<=1 && !symbolWasFound; ++i) {
		foundRomanPointer = strstr(shiftingRomanPointer, tensRomanSymbols[i]);
		if(foundRomanPointer != NULL) {
			symbolWasFound = 1;
			if(shiftingRomanPointer == foundRomanPointer) {
				decimal += i*10;
				shiftingRomanPointer = foundRomanPointer + 1;
			}
		}
	}

	symbolWasFound = 0;
	for(i=1; i<=9 && !symbolWasFound; ++i) {
		foundRomanPointer = strstr(shiftingRomanPointer, onesRomanSymbols[symbolSearchOrder[i]]);
		if(foundRomanPointer != NULL) {
			symbolWasFound = 1;
			decimal += symbolSearchOrder[i];
		}
	}

	return decimal;
}

size_t decimalToRoman(int decimal, char *decimalBuffer, size_t decimalBufferLength) {
	size_t romanLength = 0;
	int tensDigit = decimal/10;
	int onesDigit = decimal - tensDigit*10;

	if((romanSymbolLength[tensDigit] + romanLength) <= decimalBufferLength){
		strncpy(decimalBuffer, tensRomanSymbols[tensDigit], decimalBufferLength);
		romanLength += romanSymbolLength[tensDigit];
	}
	if((romanSymbolLength[onesDigit] + romanLength) <= decimalBufferLength){
		strcat(decimalBuffer, onesRomanSymbols[onesDigit]);
		romanLength += romanSymbolLength[onesDigit];
	}

	return romanLength;
}

size_t addRomanNumerals(char *term1, char *term2, char *sumBuffer, size_t sumBufferLength) {
	int term1Decimal = romanToDecimal(term1);
	int term2Decimal = romanToDecimal(term2);
	int sumDecimal = term1Decimal + term2Decimal;

	size_t usedSumBufferLength = decimalToRoman(sumDecimal, sumBuffer, sumBufferLength);

	return usedSumBufferLength;
}
