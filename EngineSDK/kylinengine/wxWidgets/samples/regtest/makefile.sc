#Digital Mars (was Symantec) C++ makefile 
WXDIR = ..\..
EXTRALIBS=
TARGET=regtest
OBJECTS = $(TARGET).obj
include $(WXDIR)\src\makeprog.sc
