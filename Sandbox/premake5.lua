project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs {
        "src",
        "%{IncludeDir.Carbon}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.spdlog}"
    }

    links {
        "Carbon"
    }

    filter "system:windows"
        defines {
            "CN_PLATFORM_WINDOWS"
        }

    filter {"configurations:Debug", "system:windows"}
        systemversion "latest"
        buildoptions "/MTd"
        runtime "Debug"
        symbols "on"
        defines {
            "CN_DEBUG"
        }

    filter {"configurations:Release", "system:windows"}
        systemversion "latest"
        buildoptions "/MT"
        runtime "Release"
        optimize "on"
        defines {
            "CN_RELEASE"
        }