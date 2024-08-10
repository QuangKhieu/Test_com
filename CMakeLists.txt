cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ModbusRTUExample)

# Find the Modbus library
find_package(PkgConfig REQUIRED)
pkg_check_modules(MODBUS REQUIRED libmodbus)

# Include directories for Modbus and project headers
include_directories(${MODBUS_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(modbus_rtu_example ${SOURCES})

# Link Modbus library
target_link_libraries(modbus_rtu_example ${MODBUS_LIBRARIES})

# Set C++ standard
set_target_properties(modbus_rtu_example PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
)
