#include "Drawers.h"
#include <vector>

void pp_drawText(String content, int16_t x, int16_t y,
    uint16_t color,
    uint8_t size,
    uint16_t bg_color,
    uint8_t datum)
{

    std::vector<String> lines;

    if(content.length()>21){
        
    }

    tft.setTextSize(size);
    tft.setTextColor(color, bg_color);
    tft.setTextDatum(datum);
    tft.setTextWrap(true, false);
    tft.drawString(content, x, y);
}

void pp_drawBox(int16_t x, int16_t y, int16_t width, int16_t height, 
    uint16_t bg_color, 
    uint16_t stroke_color, 
    uint8_t radius, 
    bool stroke) 
{
    tft.fillRoundRect(x, y, width, height, radius, bg_color);
    if(stroke){
        tft.drawRoundRect(x, y, width, height, radius, stroke_color);
    }
}

int16_t pp_drawText_wrapped(String content, int16_t x, int16_t y,
    uint16_t color,
    uint8_t size,
    uint16_t bg_color,
    uint8_t datum)
{

    std::vector<String> lines;

    int cursor = 21;
    while(cursor <= content.length()+21){
        lines.push_back(content.substring(cursor-21, cursor));
        cursor += 21;
    }
    
    int16_t lineHeight = 8 * size + 1;
    int16_t YCursor = y;
    for( auto xl:lines){
        pp_drawText(xl, x, YCursor, color, size, bg_color, datum);
        YCursor += lineHeight;
    }
    Serial.println("Lines: " + String(lines.size()));
    if(content.length()%21==0){
        return (lines.size())*lineHeight;
    }else return (lines.size()+1)*lineHeight;
    
}
