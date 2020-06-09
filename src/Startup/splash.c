#include <gb/gb.h>
#include <studio.h>
#include "isrp_tileset.c"
#include "isrp_tilemap.c"
#include "prog_tilemap.c"
#include "prog_tileset.c"
#include "fbr_tileset.c"
#include "fbr_tilemap.h"

UINT8 i;

void performantdelay(UINT8 numloops){
    UINT8 ii;
    for(ii = 0; ii < numloops; ii++){
        wait_vbl_done();
    }     
}

void fadeout(){
	for(i=0;i<4;i++){
		switch(i){
			case 0:
				BGP_REG = 0xE4;
				break;
			case 1:
				BGP_REG = 0xF9;
				break;
			case 2:
				BGP_REG = 0xFE;
				break;
			case 3:
				BGP_REG = 0xFF;	
				break;						
		}
		performantdelay(10);
	}
}

void fadein(){
	for(i=0;i<3;i++){
		switch(i){
			case 0:
				BGP_REG = 0xFE;
				break;
			case 1:
				BGP_REG = 0xF9;
				break;
			case 2:
				BGP_REG = 0xE4;
				break;					
		}
		performantdelay(10);
	}
}

void main(){
     SHOW_BKG;
     DISPLAY_ON;

         fadeout();

     set_bkg_data(0, 114, isrp_tileset);
     set_bkg_data(0, 0, 20, 18, isrp_tilemap);

         fadein();

    performantdelay(10);

         fadeout();
    
     set_bkg_data(0, 114, prog_tileset);
     set_bkg_data(0, 0, 20, 18, prog_tilemap);

         fadein();

    performantdelay(10);

         fadeout();
    
     set_bkg_data(0, 114, fbr_tileset);
     set_bkg_data(0, 0, 20, 18, fbr_tilemap);

         fadein();



}