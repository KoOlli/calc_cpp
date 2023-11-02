#include "mybutton.h"

MyButton::MyButton(const QString &text, QWidget *parent) : QPushButton(parent) {
  setText(text);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}
