workspace "demo_hello_world"
	-- Build Configurations
	-- debug: Debug build with symbols
	-- release: Optimized build with symbols
	-- final: All Optimizations with no symbols
	configurations {
		"debug",
		"release",
		"final"
	}
	platforms {
		"x86",
		"x64"
	}

	-- x86
	filter "platforms:x86"
		architecture "x86"
	-- x64
	filter "platforms:x64"
		architecture "x64"

	-- OSX Global Defines
	configuration "macosx"
	-- Windows Global Defines
	configuration "windows"
		defines {
			"NOMINMAX"
		}

	-- hello_world
	project "hello_world"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		location "demos/hello_world"
		targetdir "bin_%{cfg.platform}"
		objdir "obj/hello_world"
		
		vpaths { 
			["include"] = {
				"**.hpp",
				"**.inl"
			},
			["src"] = {
				"**.cpp"
			}
		}
		pchheader "pch.hpp"
		pchsource "demos/hello_world/src/pch.cpp"
		files {
			"demos/hello_world/include/**.hpp",
			"demos/hello_world/include/**.inl",
			"demos/hello_world/src/**.cpp",
			"demos/hello_world.lua"
		}
		includedirs {
			"demos/hello_world/include",
			"thirdparty/glfw-3.3/include",
			"glfw++/include"
		}
		libdirs {
			"bin_%{cfg.platform}",
			"thirdparty/glfw-3.3/lib"
		}
		
		-- Shared Linked Libs
		links {
			"glfw3",
			"glfw++%{cfg.linktarget.suffix}"
		}

		-- OSX
		configuration "macosx"
			links {
				"Cocoa.framework",
				"CoreVideo.framework",
				"IOKit.framework",
				"OpenGL.framework"
			}
		-- Windows
		configuration "windows"
			filter "action:vs2017"
				buildoptions { '/std:c++17' }
			defines { "GLFW_EXPOSE_NATIVE_WIN32" }
			links {
				"opengl32",
				"Shlwapi"
			}
		-- Debug
		filter "configurations:debug"
			defines {
				"DEBUG"
			}
			flags {
				symbols "On"
			}
			targetsuffix "_d"
		-- Release
		filter "configurations:release"
			defines {
				"NDEBUG"
			}
			flags {
				symbols "On"
			}
			targetsuffix "_r"
			optimize "Speed"
		-- Final
		filter "configurations:final"
			defines {
				"NDEBUG"
			}
			optimize "Full"