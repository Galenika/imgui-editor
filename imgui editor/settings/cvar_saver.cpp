#include "cvar_saver.h"

#define ENCRYPTION_KEY 0xA67D7

	namespace Cvar
	{
		string IniFile = "";
		size_t IniFileLen = 0;

		void IniFileED()
		{
			for ( size_t i = 0; i < IniFileLen; i++ ) {
				IniFile[i] ^= ENCRYPTION_KEY;
			}
		}

		int InitPath(const char* szPath) {
			try {
				IniFile = szPath;
				IniFileLen = IniFile.size();
				IniFileED();
				return 0; //success!
			}
			catch (...) {
				return 1; //fail!
			}
		}

		int LoadCvar( char* szSection , char* szKey , int DefaultValue )
		{
			IniFileED();
			char IntValue[16] = { 0 };
			GetPrivateProfileStringA( szSection , szKey , to_string( DefaultValue ).c_str() , IntValue , sizeof( IntValue ) , IniFile.c_str() );
			IniFileED();
			return atoi( IntValue );
		}

		string LoadCvar( char* szSection , char* szKey , string DefaultValue )
		{
			IniFileED();
			char cTempString[16] = { 0 };
			GetPrivateProfileStringA( szSection , szKey , DefaultValue.c_str() , cTempString , sizeof( cTempString ) , IniFile.c_str() );
			IniFileED();
			return string( cTempString );
		}

		float LoadCvar( char* szSection , char* szKey , float DefaultValue )
		{
			IniFileED();
			char FloatValue[16] = { 0 };
			GetPrivateProfileStringA( szSection , szKey , to_string( DefaultValue ).c_str() , FloatValue , sizeof( FloatValue ) , IniFile.c_str() );
			IniFileED();
			return (float)atof( FloatValue );
		}

		void SaveCvar( char* szSection , char* szKey , int Value )
		{
			string IntValue = to_string( Value );
			IniFileED();
			WritePrivateProfileStringA( szSection , szKey , IntValue.c_str() , IniFile.c_str() );
			IniFileED();
		}

		void SaveCvar( char* szSection , char* szKey , float Value )
		{
			string FloatValue = to_string( Value );
			IniFileED();
			WritePrivateProfileStringA( szSection , szKey , FloatValue.c_str() , IniFile.c_str() );
			IniFileED();
		}

		void SaveCvar( char* szSection , char* szKey , string Value )
		{
			IniFileED();
			WritePrivateProfileStringA( szSection , szKey , Value.c_str() , IniFile.c_str() );
			IniFileED();
		}


        void SaveColor(char* szSection, char* szKey, float Value[4])
        {
            std::string szKeyr; szKeyr.append(szKey); szKeyr.append(".r");
            std::string szKeyg; szKeyg.append(szKey); szKeyg.append(".g");
            std::string szKeyb; szKeyb.append(szKey); szKeyb.append(".b");
            std::string szKeya; szKeya.append(szKey); szKeya.append(".a");
            
            SaveCvar(szSection, (char*)szKeyr.c_str(), Value[0]);
            SaveCvar(szSection, (char*)szKeyg.c_str(), Value[1]);
            SaveCvar(szSection, (char*)szKeyb.c_str(), Value[2]);
            SaveCvar(szSection, (char*)szKeya.c_str(), Value[3]);
        }

        void LoadColor(char* szSection, char* szKey, float Value[4])
        {
            std::string szKeyr; szKeyr.append(szKey); szKeyr.append(".r");
            std::string szKeyg; szKeyg.append(szKey); szKeyg.append(".g");
            std::string szKeyb; szKeyb.append(szKey); szKeyb.append(".b");
            std::string szKeya; szKeya.append(szKey); szKeya.append(".a");

            Value[0] = LoadCvar(szSection, (char*)szKeyr.c_str(), Value[0]);
            Value[1] = LoadCvar(szSection, (char*)szKeyg.c_str(), Value[1]);
            Value[2] = LoadCvar(szSection, (char*)szKeyb.c_str(), Value[2]);
            Value[3] = LoadCvar(szSection, (char*)szKeya.c_str(), Value[3]);
        }
	}
