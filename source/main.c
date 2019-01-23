#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <switch.h>

struct stat sb;

// Main program entrypoint

int main(int argc, char* argv[])
{
    consoleInit(NULL);
// Static Variables    
    const char* os = "reinx"; 
    const char* name = "zelda"; 
    const char* titleid = "01007EF00011E000";
// Variables
	char base[60];
	char mod[60];
	char installed[60];
// Path Stuff
	sprintf(base, "/%s/titles/%s/", os, titleid);
	sprintf(mod, "%s/%s/", base, name);
	sprintf(installed, "/%s/titles/%s/romfs/", os, titleid);

// Functions
void uninstall() 
	{
    	int rmstats;
		rmstats = rename(installed, mod);
		if(!rmstats) 
    		{ 
		    	printf("%s", "Uninstalled\n"); 
    		} 
    	else
    		{ 
        	perror("Error\n"); 
    		} 
   	}

void install() 
	{
    	int rmstats;
		rmstats = rename(mod, installed);
		if(!rmstats) 
    		{ 
		    	printf("%s", "Installed\n"); 
    		} 
    	else
    		{ 
        	perror("Error\n"); 
    		} 
   	}

// Menu
   	printf("@shmadul's BOTW Mod Loader\n");
   	printf("Alpha v2.0\n");
   	printf("Press A to Install\n");
   	printf("Press B to Uninstall\n");

    // Main loop
        while (appletMainLoop())
    {
        // Scan all the inputs. This should be done once for each frame
        hidScanInput();

        // hidKeysDown returns information about which buttons have been
        // just pressed in this frame compared to the previous one
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        
        //D-Pad Up
        if (kDown & KEY_UP) {
        }

        //D-Pad Down
        if (kDown & KEY_DOWN) {
        }

        //A Button
        if (kDown & KEY_A) {
        	printf("Installing, %s Mod \n", name);
        	install();
        }
            
        if (kDown & KEY_B) {
        	printf("Uninstalling, %s Mod \n", name);
        	uninstall();
        }

        if (kDown & KEY_X) {
        }

        //PlusButtonW
        if (kDown & KEY_PLUS)
            break; // break in order to return to hbmenu

        // Your code goes here

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}
