cmake_minimum_required(VERSION 3.0.2)

project(debugadapter)

set(CPPDAP_DIR ${CMAKE_SOURCE_DIR}/3rdparty/cppdap)
include_directories(${CPPDAP_DIR}/include)
find_package(Qt5 CONFIG REQUIRED Core DBus)

set(${PROJECT_NAME}_HEADERS
    debugmanager.h
    gdbproxy.h
    debugengine.h
    dapsession.h
    backendglobal.h
    locker.h
    serverinfo.h
   )

set(${PROJECT_NAME}_SOURCES
    debugmanager.cpp
    gdbproxy.cpp
    main.cpp
    debugengine.cpp
    dapsession.cpp
    serverinfo.cpp
    )

link_libraries(
    cppdap
    pthread
    )

add_executable(${PROJECT_NAME} main.cpp
    ${${PROJECT_NAME}_HEADERS}
    ${${PROJECT_NAME}_SOURCES})

target_link_libraries(${PROJECT_NAME}
  Qt5::DBus
  )

install(TARGETS ${PROJECT_NAME} DESTINATION "${LIBRARY_INSTALL_PREFIX}/tools")