#pragma once

#include <string>
#include <vector>
#include <windows.h>

using namespace std;

namespace Cvar
{
		int	InitPath(const char* szPath);

		int		LoadCvar( char* szSection , char* szKey , int DefaultValue );
		string	LoadCvar( char* szSection , char* szKey , string DefaultValue );
		float	LoadCvar( char* szSection , char* szKey , float DefaultValue );

		void	SaveCvar( char* szSection , char* szKey , int Value );
		void	SaveCvar( char* szSection , char* szKey , float Value );
		void	SaveCvar( char* szSection , char* szKey , string Value );


        void SaveColor(char* szSection, char* szKey, float Value[4]);
        void LoadColor(char* szSection, char* szKey, float Value[4]);
}
