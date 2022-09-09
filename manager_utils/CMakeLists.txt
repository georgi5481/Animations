cmake_minimum_required(VERSION 3.5.1)
	
project(manager_utils LANGUAGES CXX)		#this is the library folder !

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)	
set(_INC_DIR ${_BASE_DIR}/manager_utils)						#we made the same folder name in order to be readable
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)	

add_library(
	${PROJECT_NAME} STATIC

	${_INC_DIR}/config/DrawMgrCfg.h		#we have three separate directories after manager_utils
	${_INC_DIR}/config/RsrcMgrCfg.h		
	${_INC_DIR}/config/ManagerHandlerCfg.h		
	
	${_INC_DIR}/managers/MgrBase.h	
	${_INC_DIR}/managers/RsrcMgr.h	
	${_INC_DIR}/managers/DrawMgr.h	
	${_INC_DIR}/managers/ManagerHandler.h	
	${_INC_DIR}/drawing/Widget.h	
	${_INC_DIR}/drawing/Image.h	
	${_INC_DIR}/drawing/Text.h	
		
	${_SRC_DIR}/drawing/Text.cpp
	${_SRC_DIR}/drawing/Widget.cpp
	${_SRC_DIR}/drawing/Image.cpp
	${_SRC_DIR}/managers/DrawMgr.cpp
	${_SRC_DIR}/managers/RsrcMgr.cpp
	${_SRC_DIR}/managers/ManagerHandler.cpp	
	
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
${PROJECT_NAME} 
	PUBLIC 
		${_BASE_DIR}	#we need to include the directory
	 
	
)

target_link_libraries(
${PROJECT_NAME} 
		PUBLIC
		sdl_utils	#we include sdl_utils cuz sdl_utils links publicaly utils, and utils is linked with the main project
		
)