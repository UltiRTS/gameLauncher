#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_test.h"


using namespace std;

string getPath(int argc, char *passedargv[]) {
	// Get the last position of '/'
	string aux(passedargv[0]);
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

bool exists(const char *fileName) {
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
/*updater ends*/

SDL_Rect rect = {0, 0, 650, 650};
SDL_Renderer *WindowRen = NULL;
SDL_Window *Windows = NULL;


void bg () {
	SDL_SetRenderDrawColor(WindowRen, 0, 255, 255, 255);
	SDL_RenderDrawRect(WindowRen, &rect);
	SDL_RenderFillRect(WindowRen, &rect);
}

int terminalPos = 320;
vector<string> logMsg = {"...","...","..."};
int headingMsg = 0;

void rollLowerRightCMD(string infoUpdate) {
	logMsg.insert(logMsg.begin(),infoUpdate);
	char cstr1[logMsg[0].size() + 1];
	strcpy(cstr1, logMsg[0].c_str());
	char cstr2[logMsg[1].size() + 1];
	strcpy(cstr2, logMsg[1].c_str());
	char cstr3[logMsg[2].size() + 1];
	strcpy(cstr3, logMsg[2].c_str());
	char cstr4[logMsg[3].size() + 1];
	strcpy(cstr4, logMsg[3].c_str());

	if(headingMsg==0) {
		bg();
		SDL_SetRenderDrawColor(WindowRen,255,0,0,255);   //Set the color of the string
		SDLTest_DrawString(WindowRen,500,320,cstr1);     //Draw a string on (100,100)
		SDL_RenderPresent(WindowRen);
	}
	if(headingMsg==1) {
		SDL_SetRenderDrawColor(WindowRen,255,0,0,255);
		SDLTest_DrawString(WindowRen,500,330,cstr1);
		SDL_RenderPresent(WindowRen);
	}
	if(headingMsg==2) {
		SDL_SetRenderDrawColor(WindowRen,255,0,0,255);
		SDLTest_DrawString(WindowRen,500,340,cstr1);
		SDL_RenderPresent(WindowRen);
	}

	if(headingMsg>=3) {
		for (int x=330; x>=terminalPos;x--) {
			bg();
			SDL_SetRenderDrawColor(WindowRen,255-(330-x)*25.5,0,0,255-(330-x)*25.5);
			SDLTest_DrawString(WindowRen,500,320,cstr4);

			SDL_SetRenderDrawColor(WindowRen,255,0,0,255);
			SDLTest_DrawString(WindowRen,500,x,cstr3);

			SDL_SetRenderDrawColor(WindowRen,255,0,0,255);
			SDLTest_DrawString(WindowRen,500,x+10,cstr2);

			SDL_SetRenderDrawColor(WindowRen,(330-x)*25.5,0,0,(330-x)*25.5);
			SDLTest_DrawString(WindowRen,500,340,cstr1);

			SDL_RenderPresent(WindowRen);
			SDL_Delay(200);
		}
	}
	//SDL_SetRenderDrawColor(WindowRen,255,0,0,255);
	//SDLTest_DrawString(WindowRen,500,340,cstr1);
	//SDL_RenderPresent(WindowRen);
	headingMsg++;
}
/*gui ends*/

int main(int argc,char* argv[]) {
	SDL_Init(SDL_INIT_AUDIO);
	Windows = SDL_CreateWindow("TestString",100,100,600,350,SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	WindowRen = SDL_CreateRenderer(Windows,-1,0);
	// SDL_Event event;
	SDL_SetRenderDrawColor(WindowRen, 0, 255, 255, 255);
	SDL_RenderFillRect(WindowRen, &rect);
/*
	while(true) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				SDL_Quit();
				return 0;
			}
		}
	SDL_Delay(2);
	}
	return 0;
*/
	string basePath = getPath(argc, argv);
	string busyboxPath = basePath + "busybox.exe";
	string launcherPath = basePath + "launcher.exe";
	string enginePath = basePath + "Current_Engine-master/spring --menu 'Chobby $VERSION'";
	rollLowerRightCMD("Prob_path active");

	cout << "Checking for update" << endl;
	string updateCMD = busyboxPath + " rm -rf /dev/shm/version.zip &&" + busyboxPath +
		" wget -P /dev/shm http://files.ultirts.net/newrelease/version.zip";
	//get the newest version and avoid writing to the actual disk if possible
	system(updateCMD.c_str());
	//using some simple compression to prevent little hackers
	string readRemoteVerCMD = busyboxPath + " zcat /dev/shm/version.zip";
	//need to get the actual output, risky but have to
	string version = exec(readRemoteVerCMD.c_str());
	//using some simple compression to prevent little hackers
	string readLocalVerCMD = busyboxPath + " zcat " + basePath + "localver";
	//need to get the actual output, risky but have to
	string lVersion = exec(readLocalVerCMD.c_str());
	string localVerPath = basePath + "localver";
	rollLowerRightCMD("Prob_version active");
	//check first run
	if (!exists(localVerPath.c_str())) {
		rollLowerRightCMD("Prob_init_run active");
		string initVer = busyboxPath + " touch " + basePath + "localver";
		system(initVer.c_str()); //initialize the version pool
	}
	if (lVersion.compare(version) != 0) {
		string cpCMD = busyboxPath+" rm "+basePath+"localver &&" + busyboxPath + " mv /dev/shm/version.zip " + basePath + "localver";
		system(cpCMD.c_str()); //get the newest version and avoid writing to the actual disk if possible
		isUpdated = true;
	}
	//isUpdated is from version query
	if (isUpdated) {
		rollLowerRightCMD("Update active");
		string updater = busyboxPath + " wget -P " + basePath +
			" http://files.ultirts.net/newrelease/updater && cd " + basePath +
			" && chmod +Xx * &&" + basePath + "updater";
		system(updater.c_str()); //get the newest version and avoid writing to the actual disk if possible
		cout << "Updated, running new launcher"<<endl;
		system(launcherPath.c_str());
		return 0;
	} else {
		rollLowerRightCMD("Querying default engine");
		cout << "launcher path is "<< basePath<<endl;
		cout << "infering engine path "<< enginePath<<endl;
		SDL_Quit();
		system(enginePath.c_str());
	}
	return 0;
}
