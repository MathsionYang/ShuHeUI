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
    ButtonStyle_Rect = 0,       //Բ�Ǿ���
    ButtonStyle_CircleIn = 1,   //��Բ��
    ButtonStyle_CircleOut = 2,  //��Բ��
    ButtonStyle_Image = 3       //ͼƬ
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
  bool checked;             //�Ƿ�ѡ��
  ButtonStyle buttonStyle;  //���ذ�ť��ʽ

  QColor bgColorOff;  //�ر�ʱ������ɫ
  QColor bgColorOn;   //��ʱ������ɫ

  QColor sliderColorOff;  //�ر�ʱ������ɫ
  QColor sliderColorOn;   //��ʱ������ɫ

  QColor textColorOff;  //�ر�ʱ�ı���ɫ
  QColor textColorOn;   //��ʱ�ı���ɫ

  QString textOff;  //�ر�ʱ��ʾ������
  QString textOn;   //��ʱ��ʾ������

  QString imageOff;  //�ر�ʱ��ʾ��ͼƬ
  QString imageOn;   //��ʱ��ʾ��ͼƬ

  int space;       //�����뱳�����
  int rectRadius;  //Բ�ǽǶ�

  int step;       //ÿ���ƶ��Ĳ���
  int startX;     //���鿪ʼX������
  int endX;       //�������X������
  QTimer *timer;  //��ʱ������

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
  //�����Ƿ�ѡ��
  void setChecked(bool checked);
  //���÷����ʽ
  void setButtonStyle(ButtonStyle buttonStyle);

  //���ùرձ�����ɫ
  void setBgColorOff(QColor bgColorOff);

  //���ÿ���������ɫ
  void setBgColorOn(QColor bgColorOn);

  //���ùرջ�����ɫ
  void setSliderColorOff(QColor sliderColorOff);
  //���ÿ���������ɫ
  void setSliderColorOn(QColor sliderColorOn);

  //���ùر��ı���ɫ
  void setTextColorOff(QColor textColorOff);
  //���ÿ����ı���ɫ
  void setTextColorOn(QColor textColorOn);

  //���ùر��ı�
  void setTextOff(QString textOff);
  //���ÿ����ı�
  void setTextOn(QString textOn);
  //���ñ���ͼƬ
  void setImageOff(QString imageOff);
  void setImageOn(QString imageOn);
  //���ü��
  void setSpace(int space);
  //����Բ�ǽǶ�
  void setRectRadius(int rectRadius);

 signals:
  void checkedChanged(bool checked);
};
