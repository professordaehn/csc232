cmake_minimum_required(VERSION 3.6)
project(lectures)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
if (MSVC)
    # Force to always compile with W4
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif ()
elseif (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif ()

find_library(CPPUNIT_LIBRARY_DEBUG
        NAMES cppunit
        cppunit_dll
        cppunitd
        cppunitd_dll
        PATHS /usr/lib
        /usr/lib64
        /usr/local/lib
        /usr/local/lib64
        PATH_SUFFIXES debug)
find_library(CPPUNIT_LIBRARY_RELEASE
        NAMES cppunit
              cppunit_dll
              cppunitd
              cppunitd_dll
        PATHS /usr/lib
              /usr/lib64
              /usr/local
              /usr/local/lib64
        PATH_SUFFIXES release)

if (CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)
    set(CPPUNIT_LIBRARY ${CPPUNIT_DEBUG})
endif (CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)

set(CPPUNIT_LIBRARY
        debug ${CPPUNIT_LIBRARY_DEBUG}
        optimized ${CPPUNIT_LIBRARY_RELEASE})

set(CMAKE_CXX_STANDARD 14)

set(SRC_MAIN_FILES src/main/cpp/Main.cpp)
set(SRC_DEMO_FILES src/main/cpp/Demo.cpp)
set(SRC_TEST_FILES src/test/cpp/UnitTestRunner.cpp)

add_executable(lectures ${SRC_MAIN_FILES})
add_executable(lecturesDemo ${SRC_DEMO_FILES})
add_executable(lecturesTest ${SRC_TEST_FILES})

if (APPLE)
    include_directories(lecturesTest PUBLIC /usr/local/include)
endif (APPLE)

target_link_libraries(lecturesTest PUBLIC ${CPPUNIT_LIBRARY})
