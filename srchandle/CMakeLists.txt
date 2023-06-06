file(GLOB_RECURSE pine_sourcess ${PROJECT_SOURCE_DIR}/srchandle/*.cpp)
add_library(pine_shareds SHARED ${pine_sourcess})
