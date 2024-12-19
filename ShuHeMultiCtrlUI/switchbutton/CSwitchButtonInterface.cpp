#include "CSwitchButtonInterface.h"
#include "switchbutton/QSwitchButton.h"
CSwitchButtonInterface::CSwitchButtonInterface(QObject *parent)
    : CShuHeMultiCtrlUIPlugin(parent) {
  m_PluginName = "QSwitchButton";
  m_IncludeFile = "switchbutton/QSwitchButton.h";
  m_QIcon = QIcon(":/sh/icon/switchButton.png");
  m_DomXml =
      "<widget class=\"QSwitchButton\" name=\"switchbutton\">\n"
      " <property name=\"geometry\">\n"
      "  <rect>\n"
      "   <x>0</x>\n"
      "   <y>0</y>\n"
      "   <width>100</width>\n"
      "   <height>36</height>\n"
      "  </rect>\n"
      " </property>\n"
      "</widget>\n";
}



QWidget *CSwitchButtonInterface::createWidget(QWidget *parent) {
  return new QSwitchButton(parent);

}
