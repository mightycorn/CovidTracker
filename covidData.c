#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "covidData.h"

void loadData(struct CovidData data[])
{
	int dataCount = 0;
	char buffer[300];
	char delim[] = ",";
	int i, j;
	int start = 0, end = 0;

	FILE* file = fopen("05-15-2021.csv", "r");

	if (file != NULL)
	{		
		fgets(buffer, sizeof(buffer), file);
		memset(buffer, 0, strlen(buffer));

		for (i = 0; !feof(file); i++)
		{
			fgets(buffer, sizeof(buffer), file);

			for (j = 0; j < (int)strlen(buffer); j++)
			{
				if (buffer[j] == ',')
				{
					start = end;
					end = j;

					if (end > start)
					{
						if (start + 1 != end)
							sliceData(data[i].country, buffer, start + 1, end);
					}
				}
			}

			memset(buffer, 0, strlen(buffer));
		}

		fclose(file);
		file = NULL;
	}

	return dataCount;
}

void sliceData(char result[], const char* str, int start, int end)
{
	strncpy(result, str + start, end - start);
}