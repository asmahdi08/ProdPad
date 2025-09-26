#include <TFT_eSPI.h>
#include <Arduino.h>
#include "TerminalScreen.h"
#include "./Drawers.h"
#include "./Definitions.h"
#include "../../Utils/ButtonUtils.h"


extern TFT_eSPI tft;

void TerminalScreen::draw(){
    currentY = 25;
    pp_drawBox(0,currentY,128,180,TFT_BLACK,TFT_BLACK, 0,false);
    pp_drawText("Welcome aboard!", 2, currentY,
        TFT_GREEN,
        1,
        TFT_BLACK,
        TL_DATUM
    );

    currentY += pp_drawText_wrapped("This is a terminal screen. You can display logs or other information here. Use the buttons to navigate between screens.", 2, currentY + lineHeight,
        TFT_WHITE,
        1,
        TFT_BLACK,
        TL_DATUM
    );

    pp_drawText("Press left button to go back.", 2, currentY,
        TFT_YELLOW,
        1,
        TFT_BLACK,
        TL_DATUM
    );
}
void TerminalScreen::update() {

}
int16_t TerminalScreen::handleNavigation() {
    if(ButtonUtils::isLeftButtonPressed()) {
        Serial.println("Left button pressed - Navigate to previous screen");
        // move to next screen
        return 0;
    }
    if(ButtonUtils::isRightButtonPressed()) {
        Serial.println("Right button pressed - Navigate to next screen");
        // move to next screen
        return -1;
    }
    return -1;
}