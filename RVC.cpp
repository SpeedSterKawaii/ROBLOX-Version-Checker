/******************************************************************************
 ROBLOX Version Checker - Checks the Current ROBLOX Version and Returns it.
 Developed By Speed Softwares (SpeedSterKawaii), Feel free to use it <3.
 
 Please credit me if you are going to use this in any way (exploit, UI, personal).
 NOTE: YOU EITHER GOT THIS FROM MY OFFICIAL GITHUB OR MY SITE, IF YOU DIDNT, DM ME ASAP.
*******************************************************************************/

#include <iostream>
#include <Windows.h>
#include <WinInet.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "wininet.lib")
#include <string>

//***** INTERNET CLIENT URL DOWNLOADER, DO NOT TOUCH! *****\\

std::string ReplaceAllData(std::string subject, const std::string& search,
	const std::string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

std::string DownloadURL(const char* URL) { //Download the URL from 'URL'.
	HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HINTERNET urlFile;
	std::string rtn;
	if (interwebs) {
		urlFile = InternetOpenUrlA(interwebs, URL, NULL, NULL, NULL, NULL);
		if (urlFile) {
			char buffer[2000]; //Buffer size.
			DWORD bytesRead;
			do {
				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(urlFile);
			std::string p = ReplaceAllData(rtn, "|n", "\r\n");
			return p;//Return the result.
		}
	}
	InternetCloseHandle(interwebs);
	std::string p = ReplaceAllData(rtn, "|n", "\r\n");
	return p;
}

using namespace std;

string CurrentVersion = DownloadURL("setup.roblox.com/version");//Where it grabs the version from.
string VersionToCheck = "version-UrVersionCode";//Replace with your ROBLOX version.

int TimeToWait = 4000;//How much time you would like to wait until it displays.

void CheckROBLOXVersion()//Function to CheckROBLOXVersion.
{
    if (CurrentVersion.find(VersionToCheck) != std::string::npos) 
    {
        std::cout << "Looks like this exploit needs to update...\n";
        //The version matches, that means your exploit needs to update (bad news).
    }
    else if (CurrentVersion.find("") != std::string::npos) 
    {
        std::cout << "Could not get ROBLOX version...\n";
        //Internet client failed to grab the latest version.
    }
    else
    {
        std::cout << "ROBLOX is not yet updated, keep exploiting...\n";
        //ROBLOX didn't update, that's good news for you!
    }
}

int main()
{
    SetConsoleTitleA("ROBLOX Version Checker // By SpeedSterKawaii");
    system("start https://speedsterkawaii.github.io/speed-softwares.github.io/");
    Sleep(2000);
    cout << "We are going to check the current ROBLOX version...\n";
    cout << "Please wait up to " << TimeToWait << " second(s)...\n";
    Sleep(TimeToWait);//Wait before writing results.
    CheckROBLOXVersion();
    cout << "(If you got an error, try fixing up your Internet)!\n";
    system("pause");
    return 0;
}
