set(TARGET $(CMAKE_SOURCE_DIR)/cppmus-test)

if(BUILD_CORE)

    add_library(
    	cppmus-core STATIC
        AudioInput.cpp
        AudioOutput.cpp
        BufferInfo.cpp
        Context.cpp
    	Module.cpp
    )
    	
endif()

if(BUILD_PLAY)

    add_library(
        cppmus-play STATIC
        play.cpp
        PlaybackContext.cpp
    )
    
endif()


if(BUILD_TEST)
    
    add_executable(${TARGET} test.cpp)

    target_link_libraries(
        ${TARGET}
        cppmus-core
        cppmus-play
        rtaudio
    )
    
endif()
