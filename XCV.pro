QT       += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Model/detectedfacemodel.cpp \
    aboutbox.cpp \
    main.cpp \
    mainwin_xcv.cpp \
    mattoqt.cpp \
    videostreampresenter.cpp

INCLUDEPATH += C:/OpenCV/opencv-3.4.15/build64_/install/include
LIBS += -L C:/OpenCV/opencv-3.4.15/build64_/install/x64/mingw/lib \
    -lopencv_aruco3415 \
    -lopencv_core3415 \
    -lopencv_imgcodecs3415 \
    -lopencv_highgui3415 \
    -lopencv_imgproc3415 \
    -lopencv_videoio3415 \
    -lopencv_video3415 \
    -lopencv_objdetect3415 \
    -lopencv_face3415

HEADERS += \
    ../Model/detectedfacemodel.h \
    aboutbox.h \
    mainwin_xcv.h \
    mattoqt.h \
    videostreampresenter.h

FORMS += \
    aboutbox.ui \
    mainwin_xcv.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    iconsFile.qrc

SUBDIRS += \
    ../Model/Model.pro

STATECHARTS +=
