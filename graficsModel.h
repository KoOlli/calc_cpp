#ifndef GRAFICSMODEL_H
#define GRAFICSMODEL_H

#include "calculatorModel.h"
#include <QVector>

class GraficsView;
class GraficsModel
{

public:
    GraficsModel(CalculatorModel* calculator_model_);
    void Rendering(GraficsView* grafics_view_);
    void MakeGrafStepTwo(GraficsView* grafics_view_);
    void TimerSlot(GraficsView* grafics_view_);
        QVector<double> x, y;
private:
    CalculatorModel* calculator_model_;
    int N;
    double xBegin, xEnd, h, X;

};

#endif // GRAFICSMODEL_H
