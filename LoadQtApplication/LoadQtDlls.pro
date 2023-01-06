
#TARGET = ZFinal_LoadQtDlls
TARGET = QTARXLoadQtDlls
#the sdk include path
INCLUDEPATH += "D:\ObjectARX 2022\inc"
INCLUDEPATH += "D:\ObjectARX 2022\inc-x64"

#rxapi.lib; acdb21.lib; acge21.lib; acad.lib; ac1st21.lib; accore.lib;
LIBS+= -L"D:\ObjectARX 2022\lib-x64" -lrxapi
LIBS+= -L"D:\ObjectARX 2022\lib-x64" -lacdb24
LIBS+= -L"D:\ObjectARX 2022\lib-x64" -lacge24
LIBS+= -L"D:\ObjectARX 2022\lib-x64" -lacad
LIBS+= -L"D:\ObjectARX 2022\lib-x64" -lac1st24
LIBS+= -L"D:\ObjectARX 2022\lib-x64" -laccore

#if _MSC_VER >= 1920   // ObjectARXSDK 2021以上
#pragma comment(lib, "AcPal.lib")
#pragma comment(lib, "acgeoment.lib")
LIBS+= -L"D:\ObjectARX 2022\lib-x64" -lAcPal
LIBS+= -L"D:\ObjectARX 2022\lib-x64" -laccore


#DEF_FILE
DEF_FILE += $$PWD/AcRxDefault.def

#use md dll
QMAKE_CXXFLAGS += /MD

#change .dll to .arx
TARGET_EXT = .arx

#remove _DEBUG
DEFINES -= _DEBUG 
DEFINES += _OBJECT_ARX_VERSION_X64_=2022

QT       += core
QT       += gui
QT       += widgets
QT       += qml

#Qt project template
TEMPLATE = lib

SOURCES += this_main.cpp \
    dialog.cpp

RESOURCES += \
    images.qrc

DESTDIR =release/Autocad2022

FORMS += \
    dialog.ui

HEADERS += \
    dialog.h
