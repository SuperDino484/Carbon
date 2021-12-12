project "Carbon"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "cnpch.h"
    pchsource "src/cnpch.cpp"

    files {
        "src/**.cpp",
        "src/**.h",
        "vendor/glm/glm/**.hpp"
    }

    includedirs {
        "src",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.spdlog}"
    }

    links {
        "glfw",
        "glad",
        "ImGui",
        "opengl32",
    }

    defines {
        "GLFW_INCLUDE_NONE",
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