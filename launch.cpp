#include <iostream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;


string getPath(int numArgs, char *passedArgs[])
{
    // Get the last position of '/'
    string aux(passedArgs[0]);
    // get '/' or '\\' depending on unix/mac or windows.
#if defined(_WIN32) || defined(WIN32)
    int pos = aux.rfind('\\');
#else
    int pos = aux.rfind('/');
#endif
    // Get the path and the name
    string path = aux.substr(0,pos+1);
    string name = aux.substr(pos+1);
    // show results
    return (path);
    //cout << "Name: " << name << std::endl;

}

bool isUpdated;

string getPlayerID()
{ 
// 获取并返回可以识别玩家身份的id
return "encodedString";
}

const string playerID=getPlayerID(); 

int update()
{#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>

using namespace std;

string getPath(int numArgs, char *passedArgs[])
{
    // Get the last position of '/'
    string aux(passedArgs[0]);
    // get '/' or '\\' depending on unix/mac or windows.
#if defined(_WIN32) || defined(WIN32)
    int pos = aux.rfind('\\');
#else
    int pos = aux.rfind('/');
#endif
    // Get the path and the name
    string path = aux.substr(0,pos+1);
    string name = aux.substr(pos+1);
    // show results
    return (path);
    //cout << "Name: " << name << std::endl;

}

bool exists(const char *fileName)
{
	ifstream infile(fileName);
	return infile.good();
}

string exec(const char* cmd) {
	array<char, 128> buffer;
	string result;
	unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

bool isUpdated;




int main(int numArgs, char *args[]) 
{
	
	string busyboxPath=getPath(numArgs, args)+"busybox.exe";
	string launcherPath=getPath(numArgs, args)+"launcher.exe";
	string enginePath=getPath(numArgs, args)+"engine/spring --menu 'Chobby $VERSION'";
	cout << "Checking for update"<<endl;
	string updateCMD=busyboxPath+" wget -P /dev/shm http://files.ultirts.net/newrelease/version";
	system(updateCMD.c_str()); //get the newest version and avoid writing to the actual disk if possible
	string readRemoteVerCMD=busyboxPath+" zcat /dev/shm/version";  //using some simple compression to prevent little hackers
	string version=exec(readRemoteVerCMD.c_str()); //need to get the actual output, risky but have to
	string readLocalVerCMD=busyboxPath+" zcat "+getPath(numArgs, args)+"localver";  //using some simple compression to prevent little hackers
	string lVersion=exec(readLocalVerCMD.c_str()); //need to get the actual output, risky but have to
	string localVerPath=getPath(numArgs, args)+"localver";
	if (!exists(localVerPath.c_str())) //check first run
		{
		string initVer=busyboxPath+" touch "+getPath(numArgs, args)+"localver";
		system(initVer.c_str()); //initialize the version pool
		}
	if (lVersion.compare(version) != 0)
		{
		string cpCMD="rm localver &&"+busyboxPath+" mv /dev/shm/version "+getPath(numArgs, args)+"localver";
		system(cpCMD.c_str()); //get the newest version and avoid writing to the actual disk if possible
		isUpdated=true;		
		}
	if (isUpdated)  //isUpdated is from version query
		{
		string updater=busyboxPath+" wget -P "+getPath(numArgs, args)+" http://files.ultirts.net/newrelease/updater && "+getPath(numArgs, args)+"updater";
		system(updater.c_str()); //get the newest version and avoid writing to the actual disk if possible
		cout << "Updated, running new launcher"<<endl;
		system(launcherPath.c_str());		
		return 0;		
		}
	else 
		{
		cout << "launcher path is "<< getPath(numArgs, args)<<endl;
		
		cout << "infering engine path "<< enginePath<<endl;
		system(enginePath.c_str());
		}
    	return 0;
}
// get id 到服务器并下载更新
}

int main(int numArgs, char *args[]) 
{
	string launcherPath=getPath(numArgs, args)+"launcher.exe";
	string enginePath=getPath(numArgs, args)+"engine/spring --menu 'Chobby $VERSION'";
	cout << "Checking for update"<<endl;
	
	if (isUpdated)
		{
		update();

		system(launcherPath.c_str());		
		return 0;		
		}
	else 
		{
		cout << "launcher path is "<< getPath(numArgs, args)<<endl;
		
		cout << "infering engine path "<< enginePath<<endl;
		system(enginePath.c_str());
		}
    	return 0;
}
