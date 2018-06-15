cmake_minimum_required(VERSION 3.0)
add_compile_options(-Wall -Wno-deprecated -pedantic -std=c++11)
PROJECT("CG")


if (NOT APPLE)
	if (WIN32)
		set(TOOLKITS_FOLDER "" CACHE PATH "Path to toolkits folder")
		include_directories(
			${TOOLKITS_FOLDER}/glew
			${TOOLKITS_FOLDER}/glut
			${TOOLKITS_FOLDER}/devil)
		link_directories(
			${TOOLKITS_FOLDER}/glew
			${TOOLKITS_FOLDER}/glut
			${TOOLKITS_FOLDER}/devil)
	else(WIN32)
		find_package(GLEW REQUIRED)
		include_directories(${GLEW_INCLUDE_DIRS})
		link_libraries(${GLEW_LIBRARIES})
	endif(WIN32)
endif(NOT APPLE)

if (NOT WIN32)
	find_package(GLUT REQUIRED)
	include_directories(${GLUT_INCLUDE_DIR})
	link_directories(${GLUT_LIBRARY_DIRS})
	add_definitions(${GLUT_DEFINITIONS})


	find_package(DevIL REQUIRED)
    include_directories(${IL_INCLUDE_DIR})
    link_libraries(${IL_LIBRARIES} )
    add_definitions(${IL_DEFINITIONS})
endif(NOT WIN32)
	
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

add_executable(Engine Engine/main.cpp Engine/Controls.hpp Engine/Primitive.cpp Engine/Scale.hpp Engine/XMLParser.cpp Engine/Group.cpp Engine/Primitive.hpp Engine/Transformation.cpp Engine/XMLParser.hpp Engine/Group.hpp Engine/Rotate.cpp Engine/Transformation.hpp Engine/Light.cpp Engine/Rotate.hpp Engine/Translate.cpp Engine/Light.hpp Engine/Scale.cpp Engine/Translate.hpp Engine/tinyxml2.h Engine/tinyxml2.cpp )

add_executable(Generator XMLGenerator/main.cpp)



if (WIN32)
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glut32 glew32 DevIL)
    file(COPY ${TOOLKITS_FOLDER}/glew/glew32.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${TOOLKITS_FOLDER}/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${TOOLKITS_FOLDER}/devil/DevIL.dll DESTINATION ${CMAKE_BINARY_DIR})
else(WIN32)
	include_directories(${IL_INCLUDE_DIRS})
	target_link_libraries(Engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${IL_LIBRARIES} ${ILU_LIBRARIES} ${ILUT_LIBRARIES})
endif (WIN32)