#pragma once

#include <QtWidgets/QWidget>
#include "ui_ShuHeUITest.h"

class ShuHeUITest : public QWidget
{
    Q_OBJECT

public:
    ShuHeUITest(QWidget *parent = nullptr);
    ~ShuHeUITest();

private:
    Ui::ShuHeUITestClass ui;
};
