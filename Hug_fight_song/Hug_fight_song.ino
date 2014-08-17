//
//  MyLRF03-BlinkAndSay.cpp
//  LittleRobotFriends
//
//  Created by Mark Argo on 2014-06-11.
//  Copyright (c) 2014 Aesthetec Studio Inc. All rights reserved.
//

/*
 THIS SOFTWARE IS PROVIDED “AS IS”, WITHOUT ANY REPRESENTATIONS, CONDITIONS, 
 AND/OR WARRANTIES OF ANY KIND.  WITHOUT LIMITATION, AESTHETEC STUDIO AND ITS 
 AFFILIATES, LICENSORS, SUPPLIERS, CONTRIBUTORS, SUBCONTRACTORS, DISTRIBUTORS 
 AND ALL CONTRIBUTORS DISCLAIM ANY EXPRESS OR IMPLIED REPRESENTATIONS, 
 CONDITIONS, OR WARRANTIES OF MERCHANTABILITY, MERCHANTABLE QUALITY, SATISFACTORY 
 QUALITY, NON-INFRINGEMENT, TITLE, DURABILITY, OR FITNESS FOR A PARTICULAR 
 PURPOSE, WHETHER ARISING BY STATUTE, COURSE OF DEALING, USAGE OF TRADE, OR 
 OTHERWISE.  EXCEPT AS OTHERWISE PROVIDED IN THIS AGREEMENT, YOU SHALL BEAR 
 THE ENTIRE RISK FOR ANY USE OR ANY OTHER EXPLOITATION MADE BY YOU OF ANY 
 RIGHTS IN THE COVERED SOFTWARE.
 
 Additional copyright information found at http://littlerobotfriends.com/legal/
*/

//

/*
 
 Tutorial #3 - Blinking and speaking at the same time (with multiple sounds).
 
 This sketch shows you how to create and run a custom light patterns and sounds
 at the same time. You can also create more complex expressions with multiple 
 sounds!
 
 Goals:
	- make a custom pattern
	- make a custom sound
	- make a set of custom sounds 
	- play around with the sounds to try and say 'hi, how ya doing?'
 
 */

#include "LRF.h"

// Create a light pattern for the eyes
LRFPattern myPattern = {
	LRFColor_White,			// starting color
	LRFColor_Green,			// target color
	LRFPatternMode_Fade		// pattern behaviour (see LRFUtils.h for more info)
};

// Create a sound for the speaker
LRFSound mySound = {
	LRFNote_D,				// note
	LRFOctave_6,			// octave
	LRFIntonation_Falling,	// intonation (see LRFUtils.h for more info)
	LRFDuration_Long,		// note length
	LRFDuration_None		// pause length (after note has played)
};

//MSU Fight Song
LRFSound LetterC[55] = {
{ LRFNote_F, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_FS, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_FS, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_F, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_FS, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_None }, // 7 notes

{ LRFNote_F, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_DoubleShort },
{ LRFNote_F, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_A, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_D, LRFOctave_5, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_Medium }, //13 notes

{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_DoubleShort },
{ LRFNote_A, LRFOctave_5, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_None },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_F, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_A, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_C, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_A, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_C, LRFOctave_5, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_DoubleShort },
{ LRFNote_A, LRFOctave_5, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_DoubleShort },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_DoubleShort },
{ LRFNote_F, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_DoubleShort }, // 29 notes

{ LRFNote_F, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_FS, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_FS, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_F, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_FS, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_DoubleShort }, //36 notes

{ LRFNote_D, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Short, LRFDuration_Short },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_A, LRFOctave_5, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_None },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_C, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_D, LRFOctave_5, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_DoubleMedium }, //43 notes

{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Medium },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Medium },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_DoubleShort },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_DoubleShort },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Medium },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_None },
{ LRFNote_FS, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_None },
{ LRFNote_G, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_None },
{ LRFNote_GS, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_None },
{ LRFNote_A, LRFOctave_5, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_F, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_None },
{ LRFNote_AS, LRFOctave_5, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_None } //55 notes






};


// ------------------ everything below this point runs the program --------------------

void setup(void) // Arduino setup routine that gets called ONCE when the robot turns on
{
	lrf.setup(); // lrf library should be set up before anything else
	delay(1000);
		


        lrf.setEventHandler(LRFEvent_Hug, &myHugHandler); // let's connect our event handler to the tap event								// the pattern resets after each sound
}

// Create a custom event handler function
void myHugHandler(void)
{
    // let's blink and say our array of sounds
    lrf.blinkAndSay(myPattern, LetterC, 55);
}

// Arduino loop routine that gets called OVER AND OVER while the robot runs
void loop(void)
{
	// run the lrf library
	lrf.loop();
	
	// any other functions put in here might cause the lrf to behave strange (no delays plz!)
}
