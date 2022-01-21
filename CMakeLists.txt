cmake_minimum_required(VERSION 3.18)
project(radius_spectrums_software_next)

#set(CMAKE_CXX_COMPILER "arm-linux-gnueabi-g++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -W -Werror -fPIC -pthread -O2")
set(SRC main.cpp
        lib/rs.hpp
        IBase/IBase.cpp
        IBase/IBase.hpp
        Base/Base.cpp
        Base/Base.hpp
        IApi/IApi.cpp
        IApi/IApi.hpp
        Api/Api.cpp
        Api/Api.hpp
        Spectrum/Spectrum.hpp
        ServiceResponse/ServiceResponse.cpp
        ServiceResponse/ServiceResponse.hpp Functions/IFunctions.hpp Functions/GetSpectrum.hpp Functions/GetSpectrums.hpp Functions/GetWaveForm.hpp Functions/IFunctions.cpp Functions/GetNoneFunc.hpp )
add_executable(${PROJECT_NAME} ${SRC})

include_directories("/")

# <------------ add hiredis dependency --------------->
find_path(HIREDIS_HEADER hiredis)
target_link_directories(${PROJECT_NAME} PUBLIC ${HIREDIS_HEADER})
target_include_directories(${PROJECT_NAME} PUBLIC ${HIREDIS_HEADER})

find_library(HIREDIS_LIB hiredis)
target_link_libraries(${PROJECT_NAME} ${HIREDIS_LIB})

# <------------ add redis-plus-plus dependency -------------->
# NOTE: this should be *sw* NOT *redis++*
find_path(REDIS_PLUS_PLUS_HEADER sw)
target_link_directories(${PROJECT_NAME} PUBLIC ${REDIS_PLUS_PLUS_HEADER})
target_include_directories(${PROJECT_NAME} PUBLIC ${REDIS_PLUS_PLUS_HEADER})

find_library(REDIS_PLUS_PLUS_LIB redis++)
target_link_libraries(${PROJECT_NAME} ${REDIS_PLUS_PLUS_LIB})

# <------------ add boost dependency -------------->
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
find_path(BOOST_HEADER boost)
target_link_directories(${PROJECT_NAME} PUBLIC ${BOOST_HEADER})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

# <------------ add json -------------->
find_package(nlohmann_json REQUIRED)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)

add_custom_target(copy_target ALL
        ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/folder ${CMAKE_RUNTIME_OUTPUT_DIR}/folder
        DEPENDS ${PROJECT_NAME})
