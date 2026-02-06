QT = core network sql

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../commonFiles/Entities/request.cpp \
        controller/addrequestcontroller.cpp \
        controller/changerequestcontroller.cpp \
        controller/deleterequestcontroller.cpp \
        controller/errorrequestcontroller.cpp \
        controller/getrequestcontroller.cpp \
        main.cpp \
        server/server.cpp \
        ../commonFiles/Entities/person.cpp \
        database/database.cpp \
        usecases/addrecordusecase.cpp \
        usecases/changerecordusecase.cpp \
        usecases/deleterecordusecase.cpp \
        usecases/gettableusecase.cpp

HEADERS += \
        ../commonFiles/Entities/request.h \
        controller/addrequestcontroller.h \
        controller/changerequestcontroller.h \
        controller/deleterequestcontroller.h \
        controller/errorrequestcontroller.h \
        controller/getrequestcontroller.h \
        controller/icontroller.h \
        controller/include.h \
        ../commonFiles/Entities/person.h \
        database/database.h \
        server/server.h \
        usecases/addrecordusecase.h \
        usecases/changerecordusecase.h \
        usecases/deleterecordusecase.h \
        usecases/gettableusecase.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
