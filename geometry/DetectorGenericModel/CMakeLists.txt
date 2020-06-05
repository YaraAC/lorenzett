
file(GLOB SOURCES src/*.cxx)
file(GLOB_RECURSE HEADERS src/C*.h src/DetectorGenericConstruction.h )

include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../core/GaugiKernel)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../core/G4Kernel)



ROOT_GENERATE_DICTIONARY(DetectorGenericModelDict ${HEADERS} LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/src/LinkDef.h  MODULE DetectorGenericModel)
                                      
add_library(DetectorGenericModel  OBJECT ${SOURCES} DetectorGenericModelDict.cxx)
install(FILES ${HEADERS}  DESTINATION DetectorGenericModel)

#
gaugi_install_python_modules( ${CMAKE_CURRENT_SOURCE_DIR}/python DetectorGenericModel)







