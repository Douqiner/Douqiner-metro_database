QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    info_edge.cpp \
    info_sation.cpp \
    main.cpp \
    mainwindow.cpp \
    mygraph_view.cpp \
    mytable.cpp \
    side_tool_edit.cpp

HEADERS += \
    info_edge.h \
    info_sation.h \
    mainwindow.h \
    mygraph_view.h \
    mytable.h \
    side_tool_edit.h \
    ui_mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    info_edge.ui \
    info_sation.ui \
    mytable.ui \
    side_tool_edit.ui

RESOURCES += \
    res.qrc
