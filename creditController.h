#ifndef CREDITCONTROLLER_H
#define CREDITCONTROLLER_H

#include <QLabel>
#include <QLineEdit>
#include <QMenuBar>
#include <QPixmap>
#include <QRadioButton>
#include <QSpinBox>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "mybutton.h"
#include "creditModel.h"

class CreditView;
class CreditController : public QWidget {

public:
    CreditController(CreditView* credit_view_);
    CreditController(CreditModel* credit_model_);
    void AnnuitetTable(CreditView* credit_view_);
    void EstimationDifferent(CreditView* credit_view_);

private:
 MyButton* CreateButton(const QString& text, const char* member);
 QVector<MyButton*> buttons;
 QList<QRadioButton*> allButtons;

 CreditModel* credit_model_;
};

#endif  // CREDITCONTROLLER_H
