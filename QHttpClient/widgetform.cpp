/*NOTES:
 *1.This is the Dialog Box
 *on which the OpenGL widget is embedded
 *2.This appears when start is clicked
*/

#include "widgetform.h"
#include "ui_widgetform.h"

WidgetForm::WidgetForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WidgetForm)
{
    ui->setupUi(this);
}

WidgetForm::~WidgetForm()
{
    delete ui;
}
