cmake_minimum_required(VERSION 3.16)
project(Landlords VERSION 0.1 LANGUAGES CXX)

# 启用Qt自动工具
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Multimedia MultimediaWidgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Multimedia MultimediaWidgets Core)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 源文件与翻译文件
set(TS_FILES Landlords_zh_CN.ts)
set(PROJECT_SOURCES
    main.cpp
    gamepanel.cpp gamepanel.h gamepanel.ui
    scorepanel.cpp scorepanel.h scorepanel.ui
    buttongroup.cpp buttongroup.h buttongroup.ui
    card.cpp card.h
    cardpanel.cpp cardpanel.h
    player.cpp player.h
    cards.cpp cards.h
    robot.cpp robot.h
    userplayer.cpp userplayer.h
    gamecontrol.cpp gamecontrol.h
    mybutton.cpp mybutton.h
    playhand.cpp playhand.h
    strategy.cpp strategy.h
    robotgrablord.cpp robotgrablord.h
    animationwindow.cpp animationwindow.h
    robotplayhand.cpp robotplayhand.h
    endingpanel.cpp endingpanel.h
    countdown.cpp countdown.h
    bgmcontrol.cpp bgmcontrol.h
    myplaylist.h myplaylist.cpp
    loading.h loading.cpp
    res.qrc
    app.rc
    ${TS_FILES}
    #${APP_ICON_WIN}
)

# 生成可执行目标
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Landlords
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Landlords SHARED ${PROJECT_SOURCES})
    else()
        add_executable(Landlords ${PROJECT_SOURCES})
    endif()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(Landlords PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)

# 平台属性
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Landlords)
endif()
set_target_properties(Landlords PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# 安装配置
include(GNUInstallDirs)
install(TARGETS Landlords
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Qt6最终处理
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Landlords)
endif()
