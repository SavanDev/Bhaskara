add_library(MainWindow
    mainwindow.cpp
    mainwindow.ui
    mainwindow.h
)
target_link_libraries(MainWindow PRIVATE Qt5::Widgets About)
