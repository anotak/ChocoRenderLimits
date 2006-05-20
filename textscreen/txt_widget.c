#include <stdlib.h>

#include "txt_widget.h"

void TXT_CalcWidgetSize(txt_widget_t *widget, int *w, int *h)
{
    return widget->widget_class->size_calc(widget, w, h);
}

void TXT_DrawWidget(txt_widget_t *widget, int w, int selected)
{
    widget->widget_class->drawer(widget, w, selected);
}

void TXT_DestroyWidget(txt_widget_t *widget)
{
    widget->widget_class->destructor(widget);
}

int TXT_WidgetKeyPress(txt_widget_t *widget, int key)
{
    if (widget->widget_class->key_press != NULL)
    {
        return widget->widget_class->key_press(widget, key);
    }

    return 0;
}

