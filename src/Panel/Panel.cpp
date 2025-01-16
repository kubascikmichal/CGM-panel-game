#include "Panel.h"

Panel::Panel()
{
    matrix = new Adafruit_NeoMatrix(64, 16, 1);
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
    int panel = x / 16;
    int row = y / 16;
    return 256 * panel + 16*(16-y-1) + ((y % 2) ? (x % 16) : 16 - (x % 16)-1);
}

void Panel::init()
{
    matrix->setRemapFunction(myRemapFn);
    matrix->begin();
    matrix->setTextWrap(false);
    matrix->setBrightness(10);
    matrix->setFont(&font);
}

void Panel::run()
{
    int index = 0;
    while (true)
    {
        matrix->clear();
        matrix->setTextColor(matrix->Color(0, 255, 0));
        matrix->setCursor(index, 8);
        matrix->print("ANDREJ: 6.2");
        matrix->setTextColor(matrix->Color(255, 0, 0));
        matrix->setCursor(index, 16);
        matrix->print("MICHAL: 3.5");
        matrix->show();
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        matrix->clear();
        matrix->setTextColor(matrix->Color(255, 125, 0));
        matrix->setCursor(index, 8);
        matrix->print("ANDREJ: 12.0");
        matrix->setTextColor(matrix->Color(255, 255, 0));
        matrix->setCursor(index, 16);
        matrix->print("MICHAL: 4.2");
        matrix->show();
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        matrix->clear();
        matrix->setTextColor(matrix->Color(0, 255, 0));
        matrix->setCursor(index, 8);
        matrix->print("ANDREJ: 5.5");
        matrix->setTextColor(matrix->Color(255, 0, 255));
        matrix->setCursor(index, 16);
        matrix->print("MICHAL: 15.6");
        matrix->show();
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}
