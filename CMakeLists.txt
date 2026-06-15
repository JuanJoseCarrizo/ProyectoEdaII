cmake_minimum_required(VERSION 3.19)
project(PruebaQt LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(PruebaQt
    WIN32 MACOSX_BUNDLE

        main.cpp

        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        ciudad.h

        grafo.cpp
        grafo.h

        sistemagestionlogistico.cpp
        sistemagestionlogistico.h
)

##qt_add_translations(
##   TARGETS PruebaQt
##   TS_FILES PruebaQt_es_AR.ts
##)

target_link_libraries(PruebaQt
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS PruebaQt
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET PruebaQt
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

##hola

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/mapacordoba.jfif"
    "${CMAKE_CURRENT_BINARY_DIR}/mapacordoba.jfif"
    COPYONLY
)

##hola otra vez
