#include "graficsModel.h"

#include "graficsView.h"


void GraficsModel::Rendering(GraficsView* grafics_view_) {
    for (X = xBegin; X <= xEnd; X += h) {
      x.push_back(X);
      y.push_back(calculator_model_->reduction_of_variables(grafics_view_->expr.toStdString().data()));
    }

}


void GraficsModel::MakeGrafStepTwo(GraficsView* grafics_view_) {
    X = xBegin;
    x.clear();
    y.clear();
    TimerSlot(grafics_view_);
}
void GraficsModel::TimerSlot(GraficsView* grafics_view_) {
  xBegin = grafics_view_->display_for_minx->value();
  xEnd = grafics_view_->display_for_maxx->value();

  N = 100000;

  X = xBegin;

  h = (xEnd - xBegin) / N;

  for (; X <= xEnd;) {
    x.push_back(X);
    QString tmp = grafics_view_->expr;
    //      if (X >= 0) {
    tmp.replace('x', "(" + QString::number(X, 'f', 4) + ")");
    if (X == xBegin) qDebug() << tmp;
    //      } else {
    //        tmp.replace('x', QString::number(-X, 'f', 4));
    //      }
    y.push_back(calculator_model_->reduction_of_variables(tmp.toStdString().data()));
    X += h;
  }
  //  graffsss->addGraph();
  grafics_view_->graffsss->graph(0)->addData(x, y);
  grafics_view_->graffsss->replot();
}
