#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <switch.h>

struct stat sb;

// Main program entrypoint
int file_exist (char *filename)
{
  //struct stat   buffer;   
  return (stat (filename, &sb) == 0);
}

int main(int argc, char* argv[])
{
    consoleInit(NULL);
    

// -----------------------------------------------------------------------------------------------------------------------------------------------//
//Variables and stuff
    //Main
    char cfw;
    char path[60];

    //SXOS Paths
    const char* sxos = "/sxos/titles/";
    const char* scheck = "/sxos/titles/01007EF00011E000/romfs/";
    //const char* szelda = "/sxos/titles/01007EF00011E000/zelda/";
    //const char* slinkle = "/sxos/titles/01007EF00011E000/linkle/";

     //Atmosphere Paths (WiP)
    const char* atmosphere = "/atmosphere/titles/";
    const char* acheck = "/atmosphere/titles/01007EF00011E000/romfs/";
    //const char* azelda = "/atmosphere/titles/01007EF00011E000/zelda/";
    //const char* slinkle = "/atmosphere/titles/01007EF00011E000/linkle/";

    const char* reinx = "/reinx/titles/";
    const char* rcheck = "/reinx/titles/01007EF00011E000/romfs/";
    //const char* rzelda = "/reinx/titles/01007EF00011E000/zelda/";
    //const char* rlinkle = "/reinx/titles/01007EF00011E000/linkle/";
// -----------------------------------------------------------------------------------------------------------------------------------------------//


//_______________________________________________________________________________________________________________________________________________//
//CFW Detection
    if (stat(sxos, &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        printf("Located BOTW Directory (SXOS)\n");
      	cfw = 's';
    } 
    else if (stat(atmosphere, &sb) == 0 && S_ISDIR(sb.st_mode)) 
    {
        printf("Located BOTW Directory (Atmosphere)\n");
      	cfw = 'a';
    }    
     else if (stat(reinx, &sb) == 0 && S_ISDIR(sb.st_mode)) 
    {
        printf("Located BOTW Directory (ReiNX)\n");
        cfw = 'r';
    }    
    else
    {
        printf("Cannot Detect CFW, Please Follow Install Instructions\n");
      	return 1;
    }

//_______________________________________________________________________________________________________________________________________________//

//============================================================================================================================================ //
// Functions 

   // Finds Orgional Name Of Currently Installed Mod and Sets it to "path" 
    void pathfinder()
        {
            if (stat(scheck, &sb) == 0 && S_ISDIR(sb.st_mode))
                {
                    FILE *fptr;
                    char *name;
                    long length;    
                    fptr = fopen("/sxos/titles/01007EF00011E000/romfs/name", "rb");
                    fseek(fptr, 0L, SEEK_END);
                    length = ftell(fptr);
                    rewind(fptr);
                    name = (char*)malloc((length-4) * sizeof(char));
                    fread(name, length, 1, fptr);
                    sprintf(path, "sxos/titles/01007EF00011E000/%s", name);
                }

            else if (stat(acheck, &sb) == 0 && S_ISDIR(sb.st_mode)) 
                {
                    FILE *fptr;
                    char *name;
                    long length;    
                    fptr = fopen("/atmosphere/titles/01007EF00011E000/romfs/name", "rb");
                    fseek(fptr, 0L, SEEK_END);
                    length = ftell(fptr);
                    rewind(fptr);
                    name = (char*)malloc((length-4) * sizeof(char));
                    fread(name, length, 1, fptr);
                    sprintf(path, "atmosphere/titles/01007EF00011E000/%s", name);
                }
            else if (stat(rcheck, &sb) == 0 && S_ISDIR(sb.st_mode)) 
                {
                    FILE *fptr;
                    char *name;
                    long length;    
                    fptr = fopen("/reinx/titles/01007EF00011E000/romfs/name", "rb");
                    fseek(fptr, 0L, SEEK_END);
                    length = ftell(fptr);
                    rewind(fptr);
                    name = (char*)malloc((length-4) * sizeof(char));
                    fread(name, length, 1, fptr);
                    sprintf(path, "reinx/titles/01007EF00011E000/%s", name);
                }
        }
   // Installs Mod (Bet You would have never guessed)  
    void install()
        {
            if ( cfw == 's' )
            {
                rename("/sxos/titles/01007EF00011E000/zelda", "sxos/titles/01007EF00011E000/romfs/");
    	        if (stat(scheck, &sb) == 0 && S_ISDIR(sb.st_mode))
    		        {
        	            printf("Loaded Skin\n");
                        printf("Please Reboot\n");
    		        }
    	        else 
      	            {
        	            printf("Failed To Load Skin\n");
    	            } 	
            } else if ( cfw == 'a' )
            {
                rename("/atmosphere/titles/01007EF00011E000/zelda", "atmosphere/titles/01007EF00011E000/romfs/");
    	        if (stat(scheck, &sb) == 0 && S_ISDIR(sb.st_mode))
    		        {
        	            printf("Loaded Skin\n");
                        printf("Please Reboot\n");
    		        }
    	        else 
      	            {
        	            printf("Failed To Load Skin\n");
    	            } 	
            }   else if ( cfw == 'r' )
            {
                rename("/reinx/titles/01007EF00011E000/zelda", "reinx/titles/01007EF00011E000/romfs/");
                if (stat(scheck, &sb) == 0 && S_ISDIR(sb.st_mode))
                    {
                        printf("Loaded Skin\n");
                        printf("Please Reboot\n");
                    }
                else 
                    {
                        printf("Failed To Load Skin\n");
                    }   
            }

        }
     
    // Uninstalls Mod (Bet You would have never guessed)  
    void uninstall()
        {

            //pathfinder();
            //rename("/sxos/titles/01007EF00011E000/romfs", "sxos/titles/01007EF00011E000/zelda/");
        }  
      
//============================================================================================================================================ //
//Menu    
    printf("shmadul's Mod Loader Alpha v0.43\n");
    printf("<---------- Controls ------------>'\n");
   // printf("Press UP and DOWN to select Skin\n");
    printf("Press A to install Skin\n");
    //printf("Press B to uninstall Skin\n");
    printf("\n");


//--------------------------------------------------------------------------------------------------------------------------------------------//
//Remove Existing Install

    if  ( cfw == 's' )
    {
     // rename("/sxos/titles/01007EF00011E000/romfs", "sxos/titles/01007EF00011E000/zelda/");
      printf("Removed Installed Skin");
    } 
    else if ( cfw == 'a' )
    {
     // rename("/atmosphere/titles/01007EF00011E000/romfs", "atmosphere/titles/01007EF00011E000/zelda/");
      printf("Removed Installed Skin");
    }    
    else if  ( cfw == 'r' )
    {
      rename("/reinx/titles/01007EF00011E000/romfs", "reinx/titles/01007EF00011E000/zelda/");
      printf("Removed Installed Skin");
    }    
    else
    {
        printf("ERROR MOD EXISTS AND WAS NOT ABLE TO BE REMOVED\n");
      	return 1;
    }
//--------------------------------------------------------------------------------------------------------------------------------------------//

// --------------------------------------------------------------------------------------------- //


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
           printf("Installing....\n");
           install();
        }
            
        if (kDown & KEY_B) {
           printf("Uninstalling....\n");
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
