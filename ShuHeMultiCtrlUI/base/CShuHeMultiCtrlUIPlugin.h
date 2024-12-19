#pragma once

#include "customwidget.h"
#if defined(_MSC_VER) /* MSVC Compiler */
#pragma warning(disable : 4786)
#endif
class CShuHeMultiCtrlUIPlugin : public QObject,
                                public QDesignerCustomWidgetInterface {
  Q_OBJECT
  Q_INTERFACES(QDesignerCustomWidgetInterface)

 public:
  CShuHeMultiCtrlUIPlugin(QObject *parent = nullptr);

  bool isContainer() const;
  bool isInitialized() const;
  QIcon icon() const;
  QString domXml() const;
  QString group() const;
  QString includeFile() const;
  QString name() const;
  QString toolTip() const;
  QString whatsThis() const;
  void initialize(QDesignerFormEditorInterface *core);

 protected:
  QString m_PluginName;
  QString m_IncludeFile;
  QString m_ToolTip;
  QString m_WhatThis;
  QString m_DomXml;
  QIcon m_QIcon;
 private:
  bool initialized;
};
