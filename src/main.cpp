#include "Panel/Panel.h"
#include "Player/Player.h"

void PanelTask(void *param)
{
    Panel *p = static_cast<Panel *>(param);
    p->run();
}

void setup()
{
    Panel *p = new Panel();
    xTaskCreatePinnedToCore(PanelTask, "Panel", 8192, p, 2, NULL, 1);
}

void loop()
{
}