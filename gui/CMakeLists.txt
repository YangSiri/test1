
set(CMAKE_INCLUDE_CURRENT_DIR  ON)
#打开Qt的MOC功能和UI文件处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#查找Qt的库
find_package(Qt5Widgets)
#- OSG
include(cmake/OSG_dep.cmake)

include_directories(ui)

add_subdirectory(src)


