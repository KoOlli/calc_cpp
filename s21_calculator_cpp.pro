QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculatorModel.cpp \
    calculatorView.cpp \
    calculatorXView.cpp \
    creditController.cpp \
    creditModel.cpp \
    creditView.cpp \
    depositController.cpp \
    depositModel.cpp \
    depositView.cpp \
    graficsController.cpp \
    graficsView.cpp \
    graficsModel.cpp \
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    qcustomplot.cpp

HEADERS += \
    calculatorModel.h \
    calculatorView.h \
    calculatorXView.h \
    creditController.h \
    creditModel.h \
    creditView.h \
    depositController.h \
    depositModel.h \
    depositView.h \
    graficsController.h \
    graficsView.h \
    graficsModel.h \
    mainwindow.h \
    mybutton.h \
    qcustomplot.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CMakeLists.txt \
    CMakeLists.txt.user \
    s21_calculator_cpp.pro.user
