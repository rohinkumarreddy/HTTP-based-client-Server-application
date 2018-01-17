/*NOTES:
 *1.Class File for the Dialog Box
 *2.OpenGL Draw space widget is rendered
 *on this
*/
#ifndef WIDGETFORM_H
#define WIDGETFORM_H

#include <QDialog>

namespace Ui {
class WidgetForm;
}

class WidgetForm : public QDialog
{
    Q_OBJECT

public:
    explicit WidgetForm(QWidget *parent = 0);
    ~WidgetForm();

private:
    Ui::WidgetForm *ui;
};

#endif // WIDGETFORM_H
