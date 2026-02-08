 QT       += core gui network qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client/client.cpp \
    controllers/addrequestcontroller.cpp \
    controllers/changerequestcontroller.cpp \
    controllers/deleterequestcontroller.cpp \
    controllers/getrequestcontroller.cpp \
    controllers/maincontroller.cpp \
    entities/request.cpp \
    main.cpp \
    ../commonFiles/Entities/person.cpp \
    models/personmodel.cpp \
    models/proxymodel.cpp \
    usecases/getdatausecase.cpp

HEADERS += \
    ../commonFiles/Entities/person.h \
    client/client.h \
    client/iclient.h \
    controllers/addrequestcontroller.h \
    controllers/changerequestcontroller.h \
    controllers/deleterequestcontroller.h \
    controllers/getrequestcontroller.h \
    controllers/icontroller.h \
    controllers/maincontroller.h \
    entities/request.h \
    models/personmodel.h \
    models/proxymodel.h \
    usecases/getdatausecase.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
