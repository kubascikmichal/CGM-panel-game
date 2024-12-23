#include "Panel.h"

Panel::Panel()
{
    matrix = new Adafruit_NeoMatrix(64, 32, 15);
    init();
}
int Panel::len(const char *str, int length)
{
    int size = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            size += LOWER_CASE;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            size += UPPER_CASE;
        }
        else if (str[i] == '1')
        {
            size += ONE;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            size += NUMBER;
        }
        else if (str[i] == ' ')
        {
            size += WHITESPACE;
        }
        else if (str[i] == ':')
        {
            size += COLON;
        }
    }
    return size;
}


Panel::~Panel()
{
}

uint16_t Panel::ledInPanel(uint16_t x, uint16_t y, bool odd)
{
    if (!odd)
        return 16 * (x) + ((x % 2) ? 16 - y - 1 : y);
    else
        return 16 * (16 - x - 1) + ((x % 2) ? 16 - y - 1 : y);
}
uint16_t Panel::myRemapFn(uint16_t x, uint16_t y)
{
    int panel_X = x / PANEL_W;
    int panel_Y = y / PANEL_H;
    int base_matrix[2][4] = {{0, 3, 4, 7},
                             {1, 2, 5, 6}};

    return PANEL_COUNT * base_matrix[panel_Y][panel_X] + ledInPanel(x % PANEL_W, y % PANEL_H, panel_X % 2);
}

void Panel::init()
{
    matrix->setRemapFunction(myRemapFn);
    matrix->begin();
    matrix->setTextWrap(false);
    matrix->setBrightness(10);
    matrix->setFont(&dotmat10pt7b_v2);
}

void Panel::run()
{
    while (true)
    {
        
    }
}
