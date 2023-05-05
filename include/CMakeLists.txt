add_library(lbfgs INTERFACE)
add_library(lbfgs::lbfgs ALIAS lbfgs)
target_link_libraries(lbfgs INTERFACE Eigen3::Eigen)

# Add the include paths to the Reaktoro target
target_include_directories(lbfgs
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/include
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(lbfgs INTERFACE cxx_std_11)

install(TARGETS lbfgs EXPORT lbfgsTargets)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    PATTERN "CMakeLists.txt" EXCLUDE)
