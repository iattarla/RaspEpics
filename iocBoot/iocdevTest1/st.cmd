#!../../bin/linux-arm/devTest

## You may have to change devTest to something else
## everywhere it appears in this file

< envPaths

cd ${TOP}

## Register all support components
dbLoadDatabase "dbd/devTest.dbd"
devTest_registerRecordDeviceDriver pdbbase

## Load record instances
#dbLoadRecords("db/prng.db","user=piHost")
dbLoadRecords("db/prng.db","P=test:devTest,D=Random,S=324235")

cd ${TOP}/iocBoot/${IOC}
iocInit

## Start any sequence programs
#seq sncxxx,"user=piHost"
