add_library(About
    about.ui
    about.h
)
target_link_libraries(About PRIVATE Qt5::Widgets)
