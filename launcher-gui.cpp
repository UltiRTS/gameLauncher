#include <SDL2/SDL.h>
#include <SDL2/SDL_test.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
SDL_Rect rect = {0, 0, 650, 650};
SDL_Renderer *WindowRen=NULL;
SDL_Window *Windows=NULL;


void bg ()
{
	SDL_SetRenderDrawColor(WindowRen, 0, 255, 255, 255);
    	SDL_RenderDrawRect(WindowRen, &rect);
    	SDL_RenderFillRect(WindowRen, &rect);

}

int terminalPos=330;
vector<string> logMsg;
int headingMsg=0;
void rollLowerRightCMD(string infoUpdate)
{
	logMsg.push_back("...");
	logMsg.push_back("...");
	logMsg.push_back("...");
	logMsg.push_back(infoUpdate);
    	char cstr1[logMsg[0].size() + 1];
	strcpy(cstr1, logMsg[0].c_str());
    	char cstr2[logMsg[1].size() + 1];
	strcpy(cstr2, logMsg[1].c_str());
	char cstr3[logMsg[2].size() + 1];
	strcpy(cstr3, logMsg[2].c_str());
	char cstr4[logMsg[3].size() + 1];
	strcpy(cstr4, logMsg[3].c_str());	
	for (int x=340; x>=terminalPos;x--)#include <SDL2/SDL.h>
#include <SDL2/SDL_test.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
SDL_Rect rect = {0, 0, 650, 650};
SDL_Renderer *WindowRen=NULL;
SDL_Window *Windows=NULL;


void bg ()
{
	SDL_SetRenderDrawColor(WindowRen, 0, 255, 255, 255);
    	SDL_RenderDrawRect(WindowRen, &rect);
    	SDL_RenderFillRect(WindowRen, &rect);

}

int terminalPos=320;
vector<string> logMsg={"...","...","..."};

int headingMsg=0;



void rollLowerRightCMD(string infoUpdate)
{

	logMsg.insert(logMsg.begin(),infoUpdate);
	 
    	char cstr1[logMsg[0].size() + 1];
	strcpy(cstr1, logMsg[0].c_str());
    	char cstr2[logMsg[1].size() + 1];
	strcpy(cstr2, logMsg[1].c_str());
	char cstr3[logMsg[2].size() + 1];
	strcpy(cstr3, logMsg[2].c_str());
	char cstr4[logMsg[3].size() + 1];
	strcpy(cstr4, logMsg[3].c_str());	
	if(headingMsg==0)
	{
		bg();
		SDL_SetRenderDrawColor(WindowRen,255,0,0,255);//Set the color of the string
		SDLTest_DrawString(WindowRen,500,320,cstr1);//Draw a string on (100,100)
		SDL_RenderPresent(WindowRen);
	}
	if(headingMsg==1)
	{
		
		SDL_SetRenderDrawColor(WindowRen,255,0,0,255);//Set the color of the string
		SDLTest_DrawString(WindowRen,500,330,cstr1);//Draw a string on (100,100)
		SDL_RenderPresent(WindowRen);

	}
	if(headingMsg==2)	
	{
		
		SDL_SetRenderDrawColor(WindowRen,255,0,0,255);//Set the color of the string
		SDLTest_DrawString(WindowRen,500,340,cstr1);//Draw a string on (100,100)
		SDL_RenderPresent(WindowRen);

	}
	
	if(headingMsg>=3)
	{
		for (int x=330; x>=terminalPos;x--)
		{	
		
	    		bg();
    		
	    		SDL_SetRenderDrawColor(WindowRen,255-(330-x)*25.5,0,0,255-(330-x)*25.5);//Set the color of the string
			SDLTest_DrawString(WindowRen,500,320,cstr4);//Draw a string on (100,100)

			SDL_SetRenderDrawColor(WindowRen,255,0,0,255);//Set the color of the string
			SDLTest_DrawString(WindowRen,500,x,cstr3);//Draw a string on (100,100)
		
			SDL_SetRenderDrawColor(WindowRen,255,0,0,255);//Set the color of the string
			SDLTest_DrawString(WindowRen,500,x+10,cstr2);//Draw a string on (100,100)
				
			SDL_SetRenderDrawColor(WindowRen,(330-x)*25.5,0,0,(330-x)*25.5);//Set the color of the string
			SDLTest_DrawString(WindowRen,500,340,cstr1);//Draw a string on (100,100)

			SDL_RenderPresent(WindowRen);
			SDL_Delay(200);
		}
	}
	//SDL_SetRenderDrawColor(WindowRen,255,0,0,255);//Set the color of the string
//	SDLTest_DrawString(WindowRen,500,340,cstr1);//Draw a string on (100,100)
//	SDL_RenderPresent(WindowRen);
	headingMsg++;
}
int main(int argc,char* argv[])
{

	SDL_Init(SDL_INIT_AUDIO);
	Windows=SDL_CreateWindow("TestString",100,100,600,350,SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	WindowRen=SDL_CreateRenderer(Windows,-1,0);
        SDL_Event event;


        


	SDL_SetRenderDrawColor(WindowRen, 0, 255, 255, 255);
	SDL_RenderFillRect(WindowRen, &rect);
    
    	rollLowerRightCMD("aaa");
	SDL_Delay(2000);
        rollLowerRightCMD("bbb");
	SDL_Delay(2000);
        rollLowerRightCMD("ccc");
        SDL_Delay(2000);
        rollLowerRightCMD("ddd");
	SDL_Delay(2000);
        rollLowerRightCMD("eee");
	SDL_Delay(2000);
        rollLowerRightCMD("fff");
	SDL_Delay(2000);
        rollLowerRightCMD("ggg");
        SDL_Delay(2000);
        rollLowerRightCMD("hhh");

	while(true)
    	{
    		
        	
		while (SDL_PollEvent(&event)) 
			{
           		if (event.type == SDL_QUIT) 
           			{
                		SDL_Quit();
                		return 0;
            			}

			}
	SDL_Delay(2);
	}
	return 0;
}
	{	
		
    		bg();
    		
    		SDL_SetRenderDrawColor(WindowRen,255-25.5*(10-(x-333)),0,0,255-25.5*(10-(x-333)));//Set the color of the string
		SDLTest_DrawString(WindowRen,500,320,cstr4);//Draw a string on (100,100)

		SDL_SetRenderDrawColor(WindowRen,255,0,0,255);//Set the color of the string
		SDLTest_DrawString(WindowRen,500,x,cstr3);//Draw a string on (100,100)
	
		SDL_SetRenderDrawColor(WindowRen,255,0,0,255);//Set the color of the string
		SDLTest_DrawString(WindowRen,500,x-10,cstr2);//Draw a string on (100,100)
		


		SDL_RenderPresent(WindowRen);
		SDL_Delay(200);
	}
	SDL_SetRenderDrawColor(WindowRen,255,0,0,255);//Set the color of the string
	SDLTest_DrawString(WindowRen,500,340,cstr1);//Draw a string on (100,100)
	SDL_RenderPresent(WindowRen);
	headingMsg++;
}
int main(int argc,char* argv[])
{

	SDL_Init(SDL_INIT_AUDIO);
	Windows=SDL_CreateWindow("TestString",100,100,600,350,SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	WindowRen=SDL_CreateRenderer(Windows,-1,0);
        SDL_Event event;
	

        


	SDL_SetRenderDrawColor(WindowRen, 0, 255, 255, 255);
	SDL_RenderFillRect(WindowRen, &rect);
    
    

	while(true)
    	{
    		
        	rollLowerRightCMD("aaa");

		while (SDL_PollEvent(&event)) 
			{
           		if (event.type == SDL_QUIT) 
           			{
                		SDL_Quit();
                		return 0;
            			}

			}
	SDL_Delay(20);
	}
	return 0;
}
