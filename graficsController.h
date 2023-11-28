#ifndef GRAFICSCONTROLLER_H
#define GRAFICSCONTROLLER_H

#include "graficsModel.h"

#include <QVector>
#include <QString>

class GraficsView;
class GraficsController
{
public:
    GraficsController(GraficsModel* grafics_model_);
    void Rendering(GraficsView* grafics_view_);
    void MakeGrafStepTwo(GraficsView* grafics_view_);
    GraficsModel* grafics_model_;
private:

};

#endif // GRAFICSCONTROLLER_H
