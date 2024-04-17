QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp \
    addRecordDialog.cpp \
    createChartDialog.cpp \
    editFieldDialog.cpp \
    searchFieldDialog.cpp \
    sortTableDialog.cpp

HEADERS += \
    widget.h \
    addRecordDialog.h \
    createChartDialog.h \
    editFieldDialog.h \
    searchFieldDialog.h \
    sortTableDialog.h

FORMS += \
    widget.ui \
    addRecordDialog.ui \
    createChartDialog.ui \
    editFieldDialog.ui \
    searchFieldDialog.ui \
    sortTableDialog.ui

RESOURCES += \
    assets.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
