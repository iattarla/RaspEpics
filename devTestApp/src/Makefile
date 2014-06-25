TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = devTest
# devTest.dbd will be created and installed
DBD += devTest.dbd

# devTest.dbd will be made up from these files:
devTest_DBD += base.dbd

# Include dbd files from all support applications:
devTest_DBD += deviceSupport.dbd

# Add all the support libraries needed by this IOC
devTest_LIBS += wiringPi

# devTest_registerRecordDeviceDriver.cpp derives from devTest.dbd
devTest_SRCS += devTest_registerRecordDeviceDriver.cpp
devTest_SRCS += main.c
# Build the main IOC entry point on workstation OSs.
devTest_SRCS_DEFAULT += devTestMain.cpp
devTest_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#devTest_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
devTest_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

