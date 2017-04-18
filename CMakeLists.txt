cmake_minimum_required(VERSION 3.4)
project(apogee-engine
		VERSION 0.1.0
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
endif()

# Apogee Main Library
add_library(apogee SHARED
	"Source/Windows/Engine/UI/Window/Win32Window/Accessor.cpp"
	"Source/Windows/Engine/UI/Window/Win32Window/Initialize.cpp"
	"Source/Windows/Engine/UI/Window/Win32Window/Modifier.cpp"
	"Source/Windows/Engine/UI/Window/Win32Window/OS.cpp"
	"Source/Windows/Engine/UI/Window/Win32Window/Terminate.cpp"
	"Source/Windows/Engine/UI/Window/Win32Window/Visibility.cpp"
	"Source/Windows/Engine/UI/Window/Win32Window/Win32Window.cpp"
	"Source/Windows/Engine/UI/Window/Create.cpp"
)

target_include_directories(apogee PUBLIC
	"Include"
)
target_include_directories(apogee PRIVATE
	"Source"
)
target_compile_features(apogee PUBLIC
	cxx_std_17
)
target_compile_definitions(apogee PRIVATE
	SOLUM_EXPORT
)
target_compile_definitions(apogee PUBLIC
	SOLUM_DLL
)

# Apogee Tests
add_executable(tests
	"Tests/Main.cpp"
)
target_link_libraries(tests
	apogee
)
target_compile_definitions(tests PUBLIC
	SOLUM_DLL
)