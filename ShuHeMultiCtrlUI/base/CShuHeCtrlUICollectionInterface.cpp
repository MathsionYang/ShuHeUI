#include "CShuHeCtrlUICollectionInterface.h"

#include "switchbutton/CSwitchButtonInterface.h"
CShuHeCtrlUICollectionInterface::CShuHeCtrlUICollectionInterface(
    QObject *parent)
    : QObject(parent) {
  m_plugins.append(new CSwitchButtonInterface(this));
}
QList<QDesignerCustomWidgetInterface *>
CShuHeCtrlUICollectionInterface::customWidgets() const {
  return m_plugins;
}
