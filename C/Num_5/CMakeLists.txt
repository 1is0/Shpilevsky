cmake_minimum_required(VERSION "3.16.5")

project("Project")

add_executable("${PROJECT_NAME}" "ConsoleApplication2.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "ConsoleApplication2.cpp" DESTINATION src)
