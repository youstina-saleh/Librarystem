QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpage.cpp \
    bookrecords.cpp \
    borrowreturn.cpp \
    dashboard.cpp \
    main.cpp \
    loginwindow.cpp \
    report.cpp \
    user.cpp \
    usermanager.cpp

HEADERS += \
    adminpage.h \
    bookrecords.h \
    borrowreturn.h \
    dashboard.h \
    loginwindow.h \
    report.h \
    user.h \
    usermanager.h

FORMS += \
    adminpage.ui \
    bookrecords.ui \
    borrowreturn.ui \
    dashboard.ui \
    loginwindow.ui \
    report.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
