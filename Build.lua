IncludeDirs = {
	Core = "%{wks.location}/Core/Include",
	Glad = "%{wks.location}/Vendor/Glad/include",
	GoogleTest = "%{wks.location}/Vendor/GoogleTest/googletest/include",
	Gcem = "%{wks.location}/Vendor/Gcem/include",
	GLFW = "%{wks.location}/Vendor/Glfw/include",
	Spdlog = "%{wks.location}/Vendor/Spdlog/include"
}

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

workspace "Workspace"
	configurations { "Debug", "Release" }
	platforms { "x64" }
	startproject "App"
	
	group "Dependencies"
		include "Vendor/Glad/Build-Glad.lua"
		include "Vendor/GoogleTest/Build-GoogleTest.lua"
		include "Vendor/Gcem/Build-Gcem.lua"
		include "Vendor/Glfw/Build-Glfw.lua"
		include "Vendor/Spdlog/Build-Spdlog.lua"

	group "Core"
		include "Core/Build-Core.lua"
		include "Core-Test/Build-Core-Test.lua"

	group ""
		include "Premake/Build-Premake.lua"
		include "App/Build-App.lua"