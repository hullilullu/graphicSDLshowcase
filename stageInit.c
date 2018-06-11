#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "util.h"


#define MAX_BALLS 20

int currentTimeAsInt(){
	time_t now;
    struct tm *tm;

    now = time(0);

    if ((tm = localtime (&now)) == NULL) {
        printf ("Error extracting time\n");
        return 1;
    }

    printf ("%04d-%02d-%02d %02d:%02d:%02d\n",
        tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
        tm->tm_hour, tm->tm_min, tm->tm_sec);

	return (int) tm->tm_min*tm->tm_hour + tm->tm_sec;
}


void initStage(struct stageData *data){
	for (int i = 0; i < MAX_BALLS; i++){
		data->balls[i].active = false;
	}

}