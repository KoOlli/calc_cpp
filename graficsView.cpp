#include "graficsView.h"

#include "calculatorView.h"

GraficsView::GraficsView(QWidget* parent)
    : QWidget(parent), expr(), graffsss(new QCustomPlot(this)) {
  graffsss->setFixedSize(600, 600);
  QGridLayout* mainLayout = new QGridLayout;
  display_for_minx = new QDoubleSpinBox();
  display_for_minx->setPrefix("min x = ");
  display_for_minx->setMinimum(-1000000);
  display_for_minx->setMaximum(1000000);
  display_for_minx->setValue(-10);
  display_for_maxx = new QDoubleSpinBox();
  display_for_maxx->setPrefix("max x = ");
  display_for_maxx->setMinimum(-1000000);
  display_for_maxx->setMaximum(1000000);
  display_for_maxx->setValue(10);
  MyButton* make_graf = CreateButton("Построить график", SLOT(MakeGraf()));
  MyButton* return_calc =
      CreateButton("Вернуться к калькулятору", SLOT(ReturnGraf()));
  if (!expr.isEmpty()) {
    grafics_controller_->Rendering(this);
    graffsss->addGraph();
    graffsss->graph(0)->addData(grafics_controller_->grafics_model_->x, grafics_controller_->grafics_model_->y);
    graffsss->replot();
  }
  graffsss->xAxis->setRange(-9, 9);
  graffsss->yAxis->setRange(-9, 9);

  graffsss->setInteraction(QCP::iRangeZoom, true);
  graffsss->setInteraction(QCP::iRangeDrag, true);
  graffsss->legend->setVisible(true);

  mainLayout->addWidget(display_for_minx, 102, 0, 2, 6);
  mainLayout->addWidget(display_for_maxx, 102, 7, 2, 6);
  mainLayout->addWidget(graffsss, 1, 0, 100, 16);
  mainLayout->addWidget(make_graf, 105, 0, 4, 16);
  mainLayout->addWidget(return_calc, 109, 0, 4, 16);
  mainLayout->setGeometry(QRect(0, 0, 500, 500));
  mainLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);

  setLayout(mainLayout);

  setWindowTitle("Grafics");
}

MyButton* GraficsView::CreateButton(const QString& text, const char* member) {
  MyButton* temp = new MyButton(text);
  buttons.push_back(temp);

  connect(temp, SIGNAL(clicked()), this, member);

  return temp;
}

void GraficsView::MakeGraf() {
    graffsss->clearGraphs();
    graffsss->addGraph();
    graffsss->xAxis->setRange(display_for_minx->value(),
                              display_for_maxx->value());
    graffsss->yAxis->setRange(display_for_minx->value(),
                              display_for_maxx->value());
  graffsss->graph(0)->setLineStyle(QCPGraph::lsNone);
  graffsss->graph(0)->setPen(QPen("red"));
  graffsss->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssDot, 15));
  grafics_controller_->MakeGrafStepTwo(this);
}

void GraficsView::ReturnGraf() {
  this->close();
  emit firstWindow();
}
