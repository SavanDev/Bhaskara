if(UNIX)
	add_executable(Bhaskara
		main.cpp
		resources.qrc
	)
elseif(WIN32)
	add_executable(Bhaskara WIN32
		main.cpp
		resources.qrc
		./resources/win32.rc
	)
endif()

target_link_libraries(Bhaskara PRIVATE Qt5::Widgets About MainWindow)

add_subdirectory(about)
add_subdirectory(mainWindow)
