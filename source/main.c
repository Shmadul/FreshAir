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

    const char* os = "reinx"; 
	char old[60];
	char new[60];
	sprintf(old, "/%s/titles/01007EF00011E000/zelda/", os);
	sprintf(new, "/%s/titles/01007EF00011E000/romfs/", os);
	//const char* path = "/reinx/titles/01007EF00011E000/romfs/"; 

//Functions
void uninstall() 
	{
    	int rmstats;
		rmstats = rename(new, old);
		if(!rmstats) 
    		{ 
		    	printf("%s", "Uninstalled\n"); 
    		} 
    	else
    		{ 
        	perror("Error"); 
    		} 
   	}

void install() 
	{
    	int rmstats;
		rmstats = rename(old, new);
		if(!rmstats) 
    		{ 
		    	printf("%s", "Installed\n"); 
    		} 
    	else
    		{ 
        	perror("Error"); 
    		} 
   	}

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
           // selectSaveFromList(selection, -1, saveInfoList, info, printName);
            printf("Registered Up\n");
        }

        //D-Pad Down
        if (kDown & KEY_DOWN) {
           // selectSaveFromList(selection, 1, saveInfoList, info, printName);
            printf("Registered Down\n");
        }

        //A Button
        if (kDown & KEY_A) {
        	printf("Installing\n");
        	install();
        }
            
        if (kDown & KEY_B) {
        	printf("Uninstalling\n");
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
