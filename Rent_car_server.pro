QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_new_car.cpp \
    add_new_travel.cpp \
    change_date.cpp \
    change_vip.cpp \
    chat.cpp \
    main.cpp \
    main_page.cpp \
    reserv.cpp \
    set_car.cpp \
    travel.cpp \
    user_info.cpp

HEADERS += \
    Con_server.h \
    add_new_car.h \
    add_new_travel.h \
    change_date.h \
    change_vip.h \
    chat.h \
    con_DB_rent_car.h \
    main_page.h \
    reserv.h \
    set_car.h \
    travel.h \
    user_info.h

FORMS += \
    add_new_car.ui \
    add_new_travel.ui \
    change_date.ui \
    change_vip.ui \
    chat.ui \
    main_page.ui \
    reserv.ui \
    set_car.ui \
    travel.ui \
    user_info.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
