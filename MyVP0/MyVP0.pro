TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        artist.cpp \
        functions.cpp \
        main.cpp \
        menu.cpp \
        menuitem.cpp \
        myiterator.cpp \
        myvector.cpp \
        song.cpp \
        BasicUser.cpp \
        Listener.cpp

DISTFILES += \
    MyVP0.pro.user

HEADERS += \
    artist.h \
    BasicUser.h \
    Listener.h \
    functions.h \
    menu.h \
    menuitem.h \
    myiterator.h \
    myvector.h \
    song.h
