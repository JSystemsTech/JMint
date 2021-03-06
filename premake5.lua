workspace "JMint"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	project "JMint"
		location "JMint"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"%{prj.name}/vendor/spdlog/include"
		}
		
		filter "system:windows"
			 cppdialect "C++17"
			 staticruntime "On"
			 systemversion "latest"

			 defines
			 {
			 	 "JM_PLATFORM_WINDOWS",
				 "JM_BUILD_DLL"
			 }

			 postbuildcommands
			 {
			 	 ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			 }
			 
		filter "configurations:Debug"
			defines "JM_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "JM_RELEASE"
			optimize "On"
			
		filter "configurations:Dist"
			defines "JM_DIST"
			optimize "On"
			
project "Sandbox"
	location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
		
		includedirs
		{
			"JMint/vendor/spdlog/include",
			"JMint/src"
		}

		links
		{
			"JMint"
		}
		
		filter "system:windows"
			 cppdialect "C++17"
			 staticruntime "On"
			 systemversion "latest"
			 
			 defines
			 {
			 	 "JM_PLATFORM_WINDOWS"
			 }
			 
		filter "configurations:Debug"
			defines "JM_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "JM_RELEASE"
			optimize "On"
			
		filter "configurations:Dist"
			defines "JM_DIST"
			optimize "On"
