workspace "Carbon"
    architecture "x64"
    startproject "Sandbox"
    configurations { "Debug", "Release" }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glfw"] = "%{wks.location}/Carbon/vendor/glfw/include"
IncludeDir["glad"] = "%{wks.location}/Carbon/vendor/glad/include"
IncludeDir["glm"] = "%{wks.location}/Carbon/vendor/glm/include"
IncludeDir["imgui"] = "%{wks.location}/Carbon/vendor/imgui"
IncludeDir["spdlog"] = "%{wks.location}/Carbon/vendor/spdlog/include"
IncludeDir["Carbon"] = "%{wks.location}/Carbon/src"

group "Dependencies"
    include "Carbon/vendor/glfw"
    include "Carbon/vendor/glad"
    include "Carbon/vendor/ImGui"
group ""

include "Carbon"
include "Sandbox"