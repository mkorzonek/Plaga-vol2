#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>
#include "widget.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : private Widget
{
    Q_OBJECT

public:
    Menu();
    QWidget *menu = new QWidget;
};

#endif // MENU_H
