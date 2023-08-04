QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    delete_truck_w.cpp \
    fifth_report.cpp \
    first_report_w.cpp \
    fourth_report.cpp \
    initial_capital.cpp \
    main.cpp \
    mainwindow.cpp \
    ordering_window.cpp \
    purchase_window.cpp \
    reports_window.cpp \
    second_report.cpp \
    third_report_w.cpp

HEADERS += \
    delete_truck_w.h \
    fifth_report.h \
    first_report_w.h \
    fourth_report.h \
    initial_capital.h \
    mainwindow.h \
    ordering_window.h \
    purchase_window.h \
    reports_window.h \
    second_report.h \
    third_report_w.h

FORMS += \
    delete_truck_w.ui \
    fifth_report.ui \
    first_report_w.ui \
    fourth_report.ui \
    initial_capital.ui \
    mainwindow.ui \
    ordering_window.ui \
    purchase_window.ui \
    reports_window.ui \
    second_report.ui \
    third_report_w.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
