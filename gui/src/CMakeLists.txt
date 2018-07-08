# Generate code from ui files
qt5_wrap_ui(UI_HEADERS mainWindow.ui)

message(STATUS "uiheaders: ${UI_HEADERS}")



set(SRC_LISTS
        mainWindow.cpp
        ldOsgWidget.cpp
        dlg_extract.cpp
        dlg_dataManage.cpp
        dlg_dataManage.h
        ../../processing/projectManager.cpp
        ../../processing/projectManager.cpp
        ../../processing/projectManager.h
        ../../processing/constants.h
        ../../processing/LatLong-UTMconversion.cpp
        ../../processing/LatLong-UTMconversion.h
        dlg_pointcloud.cpp
        dlg_pointcloud.h)



add_executable(Widget main.cpp ${SRC_LISTS})
target_link_libraries( Widget Qt5::Widgets Qt5::Core
        ${OPENSCENEGRAPH_LIBRARIES}
        ${Boost_LIBRARIES}
        ${GLOG_LIBRARIES})
