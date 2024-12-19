#include <QtCore/QtPlugin>
#include "base/CShuHeMultiCtrlUIPlugin.h"


CShuHeMultiCtrlUIPlugin::CShuHeMultiCtrlUIPlugin(QObject *parent)
    : QObject(parent) {
  initialized = false;
}

void CShuHeMultiCtrlUIPlugin::initialize(
    QDesignerFormEditorInterface * /*core*/) {
  if (initialized) return;

  initialized = true;
}

bool CShuHeMultiCtrlUIPlugin::isInitialized() const { return initialized; }



QString CShuHeMultiCtrlUIPlugin::name() const { return m_PluginName; }

QString CShuHeMultiCtrlUIPlugin::group() const { return "ShuHe UI"; }

QIcon CShuHeMultiCtrlUIPlugin::icon() const { return m_QIcon; }

QString CShuHeMultiCtrlUIPlugin::toolTip() const { return m_ToolTip; }

QString CShuHeMultiCtrlUIPlugin::whatsThis() const { return m_WhatThis; }

bool CShuHeMultiCtrlUIPlugin::isContainer() const { return false; }

QString CShuHeMultiCtrlUIPlugin::domXml() const { return m_DomXml; }

QString CShuHeMultiCtrlUIPlugin::includeFile() const { return m_IncludeFile; }


