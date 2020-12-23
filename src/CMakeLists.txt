add_library(
	cppmus-core STATIC
    AudioInput.cpp
    AudioOutput.cpp
    BufferInfo.cpp
    Context.cpp
	Module.cpp
	)

add_library(
    cppmus-play STATIC
    play.cpp
    PlayableContext.cpp
)