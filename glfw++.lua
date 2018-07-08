workspace "glfw++"
	-- Build Configurations
	-- debug: Debug build with debugging & symbols
	-- release: Optimized build with debugging & symbols
	-- final: Full Optimizations with no debugging or symbols
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

	-- Windows Global Defines
	configuration "windows"
		defines {
			"NOMINMAX"
		}
	
	-- glfw++
	project "glfw++"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		location "glfw++"
		targetdir "bin_%{cfg.platform}"
		objdir "obj/glfw++"
		
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
		pchsource "glfw++/src/pch.cpp"
		files {
			"glfw++/include/**.hpp",
			"glfw++/include/**.inl",
			"glfw++/src/**.cpp",
			"glfw++.lua"
		}
		includedirs {
			"public",
			"glfw++/include",
			"thirdparty/glfw-3.3/include",
			"%VULKAN_SDK%/Include"
		}
		libdirs {
			"bin_%{cfg.platform}",
			"thirdparty/glfw-3.3/lib",
			"%VULKAN_SDK%/Source/Lib"
		}

		links {
			"glfw3"
		}
		-- OSX
		configuration "macosx"
		-- Windows
		configuration "windows"
			filter "action:vs2017"
				buildoptions {
					"/std:c++17"
				}
			defines {
				"GLFW_EXPOSE_NATIVE_WIN32"
			}
			links {
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
				"DEBUG"
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