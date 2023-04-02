QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=$$PWD/Structs
INCLUDEPATH +=$$PWD/Edit
INCLUDEPATH +=$$PWD/Search
INCLUDEPATH +=$$PWD/Add_info

SOURCES += \
    Add_info/add_department.cpp \
    Edit/edit.cpp \
    Edit/help.cpp \
    Add_info/insert_data.cpp \
    Edit/link_teachers_subj.cpp \
    main.cpp \
    mainwindow.cpp \
    Search/search.cpp \
    Search/search_info.cpp

HEADERS += \
    Structs/Struct_search_facultaties.h \
    Structs/Struct_search_students.h \
    Structs/Struct_search_subjects.h \
    Structs/Struct_search_subjects_and_faculties.h \
    Structs/Struct_search_teachers.h \
    Structs/Struct_search_teachers_and_subjects.h \
    Add_info/add_department.h \
    Edit/edit.h \
    Edit/help.h \
    Add_info/insert_data.h \
    Edit/link_teachers_subj.h \
    mainwindow.h \
    Search/search.h \
    Search/search_info.h

FORMS += \
    Add_info/add_department.ui \
    Edit/edit.ui \
    Edit/help.ui \
    Add_info/insert_data.ui \
    Edit/link_teachers_subj.ui \
    mainwindow.ui \
    Search/search.ui \
    Search/search_info.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
