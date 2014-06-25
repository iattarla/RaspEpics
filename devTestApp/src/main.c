#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/sysinfo.h>

#include "alarm.h"
#include "cvtTable.h"
#include "dbDefs.h"
#include "dbAccess.h"
#include "recGbl.h"
#include "recSup.h"
#include "devSup.h"
#include "link.h"

#include "longinRecord.h"
#include "longoutRecord.h"
#include "aoRecord.h"
#include "aiRecord.h"
#include "calcoutRecord.h"

#include "epicsExport.h"
#include "epicsThread.h"
#include "epicsVersion.h"
//#include <wiringPi.h>
#include "tarlaGpio.h"

static long setPort();
static long getPort();
static long init_record();



struct { 
	long		number;
	DEVSUPFUN	report;
	DEVSUPFUN	init;
	DEVSUPFUN	init_record; 
	DEVSUPFUN	get_ioint_info;
	DEVSUPFUN	setPort;
} integer_converter={
        5,
        NULL,
        NULL,
        init_record,
        NULL,
        setPort
};
epicsExportAddress(dset,integer_converter);

struct { 
	long	    number;
	DEVSUPFUN	report;
	DEVSUPFUN	init;
	DEVSUPFUN	init_record; 
	DEVSUPFUN	get_ioint_info;
	DEVSUPFUN	getPort;
} saveCoordinate={
        5,
        NULL,
        NULL,
        init_record,
        NULL,
        getPort
};
epicsExportAddress(dset,saveCoordinate);



static long setPort(calcoutRecord *ao){

	int port = ao->a;
	int status = ao->b;

	//wiringPiSetup () ;
  	pinMode (port, "out");
	
	digitalWrite(port, status) ;

	printf("%d port set to %d .",port,status);

return 0;
}

static long getPort(calcoutRecord *ao){

	int port = ao->a;

	//wiringPiSetup () ;
  	pinMode (port,"out") ;
	int status = digitalRead(port);

	printf("%d port status is %d .\n",port,status);
	ao->b = status;
	
	
return 0;
}

static long init_record(calcoutRecord *ao){

  printf("init record...\n");

  return 0;
}
