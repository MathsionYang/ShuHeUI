#pragma once
#include <QWidget>
#include <QColor>
#include "base/SHExport.h"

class SH_EXPORT QSwitchButton : public QWidget {
  Q_OBJECT
  Q_PROPERTY(QColor bgColorOff READ getBgColorOff WRITE setBgColorOff)
  Q_PROPERTY(QColor bgColorOn READ getBgColorOn WRITE setBgColorOn)
  Q_PROPERTY(
      QColor sliderColorOff READ getSliderColorOff WRITE setSliderColorOff)
  Q_PROPERTY(QColor sliderColor READ getSliderColorOn WRITE setSliderColorOn)
  Q_PROPERTY(QColor textColorOff READ getTextColorOff WRITE setTextColorOff)
  Q_PROPERTY(QColor textColor READ getTextColorOn WRITE setTextColorOn)
  Q_PROPERTY(QString textOff READ getTextOff WRITE setTextOff)
  Q_PROPERTY(QString textOn READ getTextOn WRITE setTextOn)
  Q_PROPERTY(QString imageOff READ getImageOff WRITE setImageOff)
  Q_PROPERTY(QString imageOn READ getImageOn WRITE setImageOn)

 public:
  enum ButtonStyle {
    ButtonStyle_Rect = 0,       //圆角矩形
    ButtonStyle_CircleIn = 1,   //内圆形
    ButtonStyle_CircleOut = 2,  //外圆形
    ButtonStyle_Image = 3       //图片
  };

  QSwitchButton(QWidget *parent = 0);
  ~QSwitchButton();

 protected:
  void mousePressEvent(QMouseEvent *);
  void resizeEvent(QResizeEvent *);
  void paintEvent(QPaintEvent *);
  void drawBg(QPainter *painter);
  void drawSlider(QPainter *painter);
  void drawText(QPainter *painter);
  void drawImage(QPainter *painter);

 private:
  bool checked;             //是否选中
  ButtonStyle buttonStyle;  //开关按钮样式

  QColor bgColorOff;  //关闭时背景颜色
  QColor bgColorOn;   //打开时背景颜色

  QColor sliderColorOff;  //关闭时滑块颜色
  QColor sliderColorOn;   //打开时滑块颜色

  QColor textColorOff;  //关闭时文本颜色
  QColor textColorOn;   //打开时文本颜色

  QString textOff;  //关闭时显示的文字
  QString textOn;   //打开时显示的文字

  QString imageOff;  //关闭时显示的图片
  QString imageOn;   //打开时显示的图片

  int space;       //滑块离背景间隔
  int rectRadius;  //圆角角度

  int step;       //每次移动的步长
  int startX;     //滑块开始X轴坐标
  int endX;       //滑块结束X轴坐标
  QTimer *timer;  //定时器绘制

 private slots:
  void updateValue();

 public:
  bool getChecked() const { return checked; }
  ButtonStyle getButtonStyle() const { return buttonStyle; }

  QColor getBgColorOff() const { return bgColorOff; }
  QColor getBgColorOn() const { return bgColorOn; }

  QColor getSliderColorOff() const { return sliderColorOff; }
  QColor getSliderColorOn() const { return sliderColorOn; }

  QColor getTextColorOff() const { return textColorOff; }
  QColor getTextColorOn() const { return textColorOn; }

  QString getTextOff() const { return textOff; }
  QString getTextOn() const { return textOn; }

  QString getImageOff() const { return imageOff; }
  QString getImageOn() const { return imageOn; }

  int getSpace() const { return space; }
  int getRectRadius() const { return rectRadius; }

 public slots:
  //设置是否选中
  void setChecked(bool checked);
  //设置风格样式
  void setButtonStyle(ButtonStyle buttonStyle);

  //设置关闭背景颜色
  void setBgColorOff(QColor bgColorOff);

  //设置开启背景颜色
  void setBgColorOn(QColor bgColorOn);

  //设置关闭滑块颜色
  void setSliderColorOff(QColor sliderColorOff);
  //设置开启滑块颜色
  void setSliderColorOn(QColor sliderColorOn);

  //设置关闭文本颜色
  void setTextColorOff(QColor textColorOff);
  //设置开启文本颜色
  void setTextColorOn(QColor textColorOn);

  //设置关闭文本
  void setTextOff(QString textOff);
  //设置开启文本
  void setTextOn(QString textOn);
  //设置背景图片
  void setImageOff(QString imageOff);
  void setImageOn(QString imageOn);
  //设置间隔
  void setSpace(int space);
  //设置圆角角度
  void setRectRadius(int rectRadius);

 signals:
  void checkedChanged(bool checked);
};
