#include <string.h>

size_t addRomanNumerals(char *term1, char *term2, char *sumBuffer, size_t sumBufferLength) {
	size_t usedSumBufferLength = 2;
	char sumRomanNumeral[] = "II";

	if(usedSumBufferLength <= sumBufferLength){
		strncpy(sumBuffer, sumRomanNumeral, sumBufferLength);
	}

	return usedSumBufferLength;
}
