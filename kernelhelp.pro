#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T22:41:17
#
#-------------------------------------------------

QT += widgets

TARGET = H5KernelHelp
TEMPLATE = lib
DEFINES += KERAPI_DLL
DESTDIR = ../lib
INCLUDEPATH +=  \
                ../include


SOURCES += \
    hkernelhelp.cpp

HEADERS +=  \


win32{
    UI_DIR = temp/ui
    MOC_DIR = temp/moc
    OBJECTS_DIR	= temp/obj
}

unix {
    UI_DIR = temp/ui
    MOC_DIR = temp/moc
    OBJECTS_DIR	= temp/obj
}
