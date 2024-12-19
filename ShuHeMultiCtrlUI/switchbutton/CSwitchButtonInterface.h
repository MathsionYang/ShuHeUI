#pragma once

#include <QObject>

#include "base/CShuHeMultiCtrlUIPlugin.h"

class CSwitchButtonInterface : public CShuHeMultiCtrlUIPlugin {
  Q_OBJECT
  Q_INTERFACES(QDesignerCustomWidgetInterface)

 public:
  CSwitchButtonInterface(QObject *parent);
  virtual QWidget *createWidget(QWidget *parent);
};
