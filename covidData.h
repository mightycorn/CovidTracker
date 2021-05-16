#ifndef COVIDDATA_H
#define COVIDDATA_H

#include <stdlib.h>

#define MAX_COUNTRY_LEN 30
#define MAX_PROV_STATE_LEN 45
#define MAX_COUNTY_LEN 30
#define MAX_LASTUPDATE_LEN 19

struct CovidData
{
	char country[MAX_COUNTRY_LEN + 1];
	char provinceState[MAX_PROV_STATE_LEN + 1];
	char county[MAX_COUNTY_LEN + 1];
	char lastUpdate[MAX_LASTUPDATE_LEN + 1];
	int confirmedCases;
	int deaths;
	int recovered;
	int active;
	double indicidentRate;
	double caseFatalityRatio;
};

void loadData(struct CovidData data[]);
void sliceData(char result[], const char* str, int start, int end);

#endif
