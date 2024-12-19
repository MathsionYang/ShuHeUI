#include "QSwitchButton.h"

#include "QDebug.h"
#include "QEvent.h"
#include "QPainter.h"
#include "QTimer.h"
QSwitchButton::QSwitchButton(QWidget *parent) : QWidget(parent) {
  checked = false;
  buttonStyle = ButtonStyle_Rect;

  bgColorOff = QColor(225, 225, 225);
  bgColorOn = QColor(250, 250, 250);

  sliderColorOff = QColor(100, 100, 100);
  sliderColorOn = QColor(100, 184, 255);

  textColorOff = QColor(255, 255, 255);
  textColorOn = QColor(10, 10, 10);

  textOff = "";
  textOn = "";

  imageOff = ":/image/btncheckoff1.png";
  imageOn = ":/image/btncheckon1.png";

  space = 2;
  rectRadius = 0;

  step = width() / 50;
  startX = 0;
  endX = 0;

  timer = new QTimer(this);
  timer->setInterval(5);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));

  setFont(QFont("Microsoft Yahei", 10));
}

QSwitchButton::~QSwitchButton() {}

void QSwitchButton::mousePressEvent(QMouseEvent *) {
  checked = !checked;
  emit checkedChanged(checked);

  //ÿ���ƶ��Ĳ���Ϊ��ȵ� 50��֮һ
  step = width() / 50;

  //״̬�л��ı���Զ������յ�����
  if (checked) {
    if (buttonStyle == ButtonStyle_Rect) {
      endX = width() - width() / 2;
    } else if (buttonStyle == ButtonStyle_CircleIn) {
      endX = width() - height();
    } else if (buttonStyle == ButtonStyle_CircleOut) {
      endX = width() - height() + space;
    }
  } else {
    endX = 0;
  }

  timer->start();
}

void QSwitchButton::resizeEvent(QResizeEvent *) {
  //ÿ���ƶ��Ĳ���Ϊ��ȵ� 50��֮һ
  step = width() / 50;

  //�ߴ��С�ı���Զ������������Ϊ�յ�
  if (checked) {
    if (buttonStyle == ButtonStyle_Rect) {
      startX = width() - width() / 2;
    } else if (buttonStyle == ButtonStyle_CircleIn) {
      startX = width() - height();
    } else if (buttonStyle == ButtonStyle_CircleOut) {
      startX = width() - height() + space;
    }
  } else {
    startX = 0;
  }

  update();
}

void QSwitchButton::paintEvent(QPaintEvent *) {
  //����׼������,���÷����
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  if (buttonStyle == ButtonStyle_Image) {
    //����ͼƬ
    drawImage(&painter);
  } else {
    //���Ʊ���
    drawBg(&painter);
    //���ƻ���
    drawSlider(&painter);
    //��������
    drawText(&painter);
  }
}

void QSwitchButton::drawBg(QPainter *painter) {
  painter->save();
  painter->setPen(Qt::NoPen);

  if (!checked) {
    painter->setBrush(bgColorOff);
  } else {
    painter->setBrush(bgColorOn);
  }

  if (buttonStyle == ButtonStyle_Rect) {
    painter->drawRoundedRect(rect(), rectRadius, rectRadius);
  } else if (buttonStyle == ButtonStyle_CircleIn) {
    QRect rect(0, 0, width(), height());
    //�뾶Ϊ�߶ȵ�һ��
    int radius = rect.height() / 2;
    //Բ�Ŀ��Ϊ�߶�
    int circleWidth = rect.height();

    QPainterPath path;
    path.moveTo(radius, rect.left());
    path.arcTo(QRectF(rect.left(), rect.top(), circleWidth, circleWidth), 90,
               180);
    path.lineTo(rect.width() - radius, rect.height());
    path.arcTo(QRectF(rect.width() - rect.height(), rect.top(), circleWidth,
                      circleWidth),
               270, 180);
    path.lineTo(radius, rect.top());

    painter->drawPath(path);
  } else if (buttonStyle == ButtonStyle_CircleOut) {
    QRect rect(space, space, width() - space * 2, height() - space * 2);
    painter->drawRoundedRect(rect, rectRadius, rectRadius);
  }

  painter->restore();
}

void QSwitchButton::drawSlider(QPainter *painter) {
  painter->save();
  painter->setPen(Qt::NoPen);

  if (!checked) {
    painter->setBrush(sliderColorOff);
  } else {
    painter->setBrush(sliderColorOn);
  }

  if (buttonStyle == ButtonStyle_Rect) {
    int sliderWidth = width() / 2 - space * 2;
    int sliderHeight = height() - space * 2;
    QRect sliderRect(startX + space, space, sliderWidth, sliderHeight);
    painter->drawRoundedRect(sliderRect, rectRadius, rectRadius);
  } else if (buttonStyle == ButtonStyle_CircleIn) {
    QRect rect(0, 0, width(), height());
    int sliderWidth = rect.height() - space * 2;
    QRect sliderRect(startX + space, space, sliderWidth, sliderWidth);
    painter->drawEllipse(sliderRect);
  } else if (buttonStyle == ButtonStyle_CircleOut) {
    QRect rect(0, 0, width() - space, height() - space);
    int sliderWidth = rect.height();
    QRect sliderRect(startX, space / 2, sliderWidth, sliderWidth);
    painter->drawEllipse(sliderRect);
  }

  painter->restore();
}

void QSwitchButton::drawText(QPainter *painter) {
  painter->save();

  if (!checked) {
    painter->setPen(textColorOff);
    painter->drawText(width() / 2, 0, width() / 2 - space, height(),
                      Qt::AlignCenter, textOff);
  } else {
    painter->setPen(textColorOn);
    painter->drawText(0, 0, width() / 2 + space * 2, height(), Qt::AlignCenter,
                      textOn);
  }

  painter->restore();
}

void QSwitchButton::drawImage(QPainter *painter) {
  painter->save();

  QPixmap pix;

  if (!checked) {
    pix = QPixmap(imageOff);
  } else {
    pix = QPixmap(imageOn);
  }

  //�Զ��ȱ���ƽ�����ž�����ʾ
  int targetWidth = pix.width();
  int targetHeight = pix.height();
  pix = pix.scaled(targetWidth, targetHeight, Qt::KeepAspectRatio,
                   Qt::SmoothTransformation);

  int pixX = rect().center().x() - targetWidth / 2;
  int pixY = rect().center().y() - targetHeight / 2;
  QPoint point(pixX, pixY);
  painter->drawPixmap(point, pix);

  painter->restore();
}

void QSwitchButton::updateValue() {
  if (checked) {
    if (startX < endX) {
      startX = startX + step;
    } else {
      startX = endX;
      timer->stop();
    }
  } else {
    if (startX > endX) {
      startX = startX - step;
    } else {
      startX = endX;
      timer->stop();
    }
  }

  update();
}

void QSwitchButton::setChecked(bool checked) {
  if (this->checked != checked) {
    this->checked = checked;
    emit checkedChanged(checked);
    update();
  }
}

void QSwitchButton::setButtonStyle(QSwitchButton::ButtonStyle buttonStyle) {
  this->buttonStyle = buttonStyle;
  update();
}

void QSwitchButton::setBgColorOff(QColor bgColorOff) {
  this->bgColorOff = bgColorOff;
  update();
}

void QSwitchButton::setBgColorOn(QColor bgColorOn) {
  this->bgColorOn = bgColorOn;
  update();
}

void QSwitchButton::setSliderColorOff(QColor sliderColorOff) {
  this->sliderColorOff = sliderColorOff;
  update();
}

void QSwitchButton::setSliderColorOn(QColor sliderColorOn) {
  this->sliderColorOn = sliderColorOn;
  update();
}

void QSwitchButton::setTextColorOff(QColor textColorOff) {
  this->textColorOff = textColorOff;
  update();
}

void QSwitchButton::setTextColorOn(QColor textColorOn) {
  this->textColorOn = textColorOn;
  update();
}

void QSwitchButton::setTextOff(QString textOff) {
  this->textOff = textOff;
  update();
}

void QSwitchButton::setTextOn(QString textOn) {
  this->textOn = textOn;
  update();
}

void QSwitchButton::setImageOff(QString imageOff) {
  this->imageOff = imageOff;
  update();
}

void QSwitchButton::setImageOn(QString imageOn) {
  this->imageOn = imageOn;
  update();
}

void QSwitchButton::setSpace(int space) {
  this->space = space;
  update();
}

void QSwitchButton::setRectRadius(int rectRadius) {
  this->rectRadius = rectRadius;
  update();
}
