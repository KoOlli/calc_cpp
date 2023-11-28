#include "graficsController.h"
#include "graficsView.h"

void GraficsController::Rendering(GraficsView* grafics_view_) {
    grafics_model_->Rendering(grafics_view_);
}

void GraficsController::MakeGrafStepTwo(GraficsView* grafics_view_) {
    grafics_model_->MakeGrafStepTwo(grafics_view_);
}
