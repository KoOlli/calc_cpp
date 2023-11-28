#ifndef GRAFICSVIEW_H
#define GRAFICSVIEW_H
#include <QTimer>
#include <QWidget>

#include "graficsController.h"
#include "QtWidgets/qspinbox.h"
#include "mybutton.h"
#include "qcustomplot.h"


class GraficsView : public QWidget {
  Q_OBJECT

 signals:
  void firstWindow();

 private slots:
  void MakeGraf();
  void ReturnGraf();

 public:
  GraficsView(GraficsController* grafics_controller_);
//  GraficsView();
  explicit GraficsView(QWidget* parent = nullptr);
  QString expr;
  QDoubleSpinBox* display_for_minx;
  QDoubleSpinBox* display_for_maxx;

  QCustomPlot* graffsss;

  GraficsController* grafics_controller_;

 private:
  MyButton* CreateButton(const QString& text, const char* member);
  QVector<MyButton*> buttons;

  QTimer* timer;
  int time;
};

#endif  // GRAFICSVIEW_H
