# Created by github@Xmind404 on 16:49 30.06.2026.

cmake_minimum_required(VERSION 3.30)
project(currency-converter LANGUAGES CXX)

add_executable(${PROJECT_NAME}
        src/assets/ascii.h
        src/api/keys.h
        src/main.cpp
        src/functions/table_generator.h
        src/functions/table_generator.cpp
        src/functions/response.h
        src/functions/response.cpp
        src/assets/colors.h
        src/functions/currency.h
        src/functions/currency.h
        src/functions/currency.cpp
        src/assets/regex_patterns.h
        src/assets/regex_patterns.cpp
)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /std:c++latest)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -std=c++26)
endif()

find_package(cpr CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr)

# currency-converter/CMakeLists.txt
