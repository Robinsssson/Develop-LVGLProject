cmake_minimum_required(VERSION 3.25)
project(lvgl_demo VERSION 0.1.0)

include(CTest)
enable_testing()
# set(SDL2_DIR C:/dev/sdl/SDL2-devel-2.28.5-mingw/SDL2-2.28.5/cmake)
# find_package(SDL2 REQUIRED) 
# include_directories(${SDL2_INCLUDE_DIRS})
# list(APPEND CMAKE_PREFIX_PATH C:/dev/sdl/SDL2-devel-2.28.5-mingw/SDL2-2.28.5/cmake)
# 添加宏定
add_definitions(-DUSE_SDL)

# 添加头文件目录
include_directories(src)
include_directories(src/GUI_APP)
include_directories(src/GUI_APP/GUI_Manage)
include_directories(src/GUI_APP/GUI_LinkList)
include_directories(src/GUI_APP/GUI_Page)
# 添加子库编译
add_subdirectory("lvgl")
add_subdirectory("lv_drivers")

# 添加源文件(递归包含)
FILE(GLOB_RECURSE src_source ./src/*.c ./src/GUI_APP/*.c)

# 编译可执行文件
add_executable(${PROJECT_NAME} ${src_source})

# 链接库
target_link_libraries(${PROJECT_NAME} lvgl)
target_link_libraries(${PROJECT_NAME} lv_drivers)
target_link_libraries(${PROJECT_NAME} mingw32)
target_link_libraries(${PROJECT_NAME} SDL2main)
target_link_libraries(${PROJECT_NAME} SDL2)
# target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# 拷贝SDL2.dll 文件到 build目录
file(COPY SDL2.dll DESTINATION ../build)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
