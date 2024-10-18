project "Core-Test"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	targetdir("%{wks.location}/build/bin/" .. OutputDir .. "/%{prj.name}")
	objdir("%{wks.location}/build/bin-int/" .. OutputDir .. "/%{prj.name}")

	files {
		"Include/**.hpp",
		"Source/**.cpp"
	}

	includedirs {
		"Include",

		"%{IncludeDirs.Core}",
		"%{IncludeDirs.GoogleTest}"
	}

	links {
		"Core",
		"GoogleTest"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
		optimize "On"