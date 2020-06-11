
file(GLOB SOURCES src/*.cxx)
file(GLOB_RECURSE HEADERS src/C*.h src/DetectorAPConstruction.h )

include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../core/GaugiKernel)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../core/G4Kernel)



ROOT_GENERATE_DICTIONARY(DetectorAPModelDict ${HEADERS} LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/src/LinkDef.h  MODULE DetectorAPModel)
                                      
add_library(DetectorAPModel  OBJECT ${SOURCES} DetectorAPModelDict.cxx)
install(FILES ${HEADERS}  DESTINATION DetectorAPModel)


gaugi_install_python_modules( ${CMAKE_CURRENT_SOURCE_DIR}/python DetectorAPModel)







