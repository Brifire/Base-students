QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_department.cpp \
    edit.cpp \
    help.cpp \
    insert_data.cpp \
    link_teachers_subj.cpp \
    main.cpp \
    mainwindow.cpp \
    search.cpp \
    search_info.cpp

HEADERS += \
    Struct_search_facultaties.h \
    Struct_search_students.h \
    Struct_search_subjects.h \
    Struct_search_subjects_and_faculties.h \
    Struct_search_teachers.h \
    Struct_search_teachers_and_subjects.h \
    add_department.h \
    edit.h \
    help.h \
    insert_data.h \
    link_teachers_subj.h \
    mainwindow.h \
    search.h \
    search_info.h

FORMS += \
    add_department.ui \
    edit.ui \
    help.ui \
    insert_data.ui \
    link_teachers_subj.ui \
    mainwindow.ui \
    search.ui \
    search_info.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
