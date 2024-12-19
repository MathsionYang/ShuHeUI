#pragma once

#include <QObject>
#include "customwidget.h"
#if defined(_MSC_VER) /* MSVC Compiler */
#pragma warning(disable : 4786)
#endif
class CShuHeCtrlUICollectionInterface
    : public QObject,
      public QDesignerCustomWidgetCollectionInterface {
  Q_OBJECT
  Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)

#if QT_VERSION >= 0x050000
  Q_PLUGIN_METADATA(
      IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")
#endif
 public:
  CShuHeCtrlUICollectionInterface(QObject *parent = NULL);

  virtual QList<QDesignerCustomWidgetInterface *> customWidgets() const;

 private:
  QList<QDesignerCustomWidgetInterface *> m_plugins;
};
