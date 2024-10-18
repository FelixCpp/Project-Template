project "Premake"
    kind "Utility"
    require("premake", ">=4.4")
    targetdir("%{wks.location}\\build\\bin\\" .. OutputDir .. "\\%{prj.name}")
    objdir("%{wks.location}\\build\\bin-int\\" .. OutputDir .. "\\%{prj.name}")
    files {
        "%{wks.location}\\Build.lua",
        "%{wks.location}\\**Build-*.lua",
    }

    postbuildmessage "Regenerating project files with Premake5!"
    postbuildcommands {
        "\"%{_PREMAKE_COMMAND}\" %{_ACTION} --file=\"%{wks.location}Build.lua\""
    }