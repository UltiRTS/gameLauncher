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
{
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
