#include <gb/gb.h>
#include <stdio.h>
#include "isrpsplash_data.c"
#include "isrpsplash_map.c"
#include "progsplash_data.c"
#include "progsplash_map.c"
#include "fbrsplash_data.c"
#include "fbrsplash_map.c"
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
 performantdelay(10);
}

void fadein(){
	for(i=0;i<4;i++){
		switch(i){
			case 0:
				BGP_REG = 0xFF;
				break;
			case 1:
				BGP_REG = 0xFE;
				break;
			case 2:
				BGP_REG = 0xF9;
				break;
            case 3:
				BGP_REG = 0xE4;
				break;							
		}
		performantdelay(10);
	}
 performantdelay(10);
}

void main(){
     SHOW_BKG;
     DISPLAY_ON;

         fadeout();

     set_bkg_data(0, 114, isrpsplash_data);
     wait_vbl_done();
     set_bkg_tiles(0, 0, 20, 18, isrpsplash_map);
     wait_vbl_done();

     SHOW_BKG;
     DISPLAY_ON;

         fadein();
         wait_vbl_done();

    performantdelay(100);

         fadeout();
    
    performantdelay(100);

     set_bkg_data(0, 205, progsplash_data);
     set_bkg_tiles(0, 0, 20, 18, progsplash_map);
     wait_vbl_done();

         fadein();

    performantdelay(100);

         fadeout();

    performantdelay(40);
    
     set_bkg_data(0, 114, fbrsplash_data);
     set_bkg_tiles(0, 0, 20, 18, fbrsplash_map);
     wait_vbl_done();

         fadein();

    performantdelay(100);

    
        fadeout();    
    
    wait_vbl_done();


}