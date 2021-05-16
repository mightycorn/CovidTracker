#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "covidData.h"

#define MAX_DATA 5000

int main(void)
{
	struct CovidData* data = (struct CovidData*)malloc(MAX_DATA * sizeof(struct CovidData));
	
	loadData(data);

	return 0;
}
