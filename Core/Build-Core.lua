project "Core"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"
	targetdir("%{wks.location}/build/bin/" .. OutputDir .. "/%{prj.name}")
	objdir("%{wks.location}/build/bin-int/" .. OutputDir .. "/%{prj.name}")
	defines { "GLFW_INCLUDE_NONE" }

	files {
		"Include/**.ixx",
		"Source/**.cpp"
	}

	includedirs {
		"Include",

		"%{IncludeDirs.Glad}",
		"%{IncludeDirs.Gcem}",
		"%{IncludeDirs.GLFW}"
	}

	links {
		"Glad",
		"GLFW"
	}

	filter "files:**.ixx"
		compileas "Module"

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
		optimize "On"