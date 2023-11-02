#ifndef DEPOSITVIEW_H
#define DEPOSITVIEW_H

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>

#include "mybutton.h"
#include "depositController.h"

class DepositView : public QWidget {
  Q_OBJECT

 signals:
  void firstWindow();


 public:
  DepositView(DepositController* deposit_controller_);
  explicit DepositView(QWidget* parent = nullptr);

  QLabel* sum_amount;
  QLineEdit* sum_amount_line;

  QLabel* placement_period;
  QSpinBox* placement_period_line;

  QLabel* interest_rate;
  QLineEdit* interest_rate_line;

  QLabel* tax_rate;
  QLineEdit* tax_rate_line;

  QLabel* perodicity_of_payments;
  QLineEdit* perodicity_of_payments_line;

  QLabel* interest_capitalization;
  QLineEdit* interest_capitalization_line;

  QLabel* interest_charges;
  QLabel* amount_of_taxes;
  QLabel* sum_amount_by_the_end;

private slots:
 void BackToCalculatorClicked();
 void MakeCalculateClicked();


private:

  MyButton* CreateButton(const QString& text, const char* member);
  QVector<MyButton*> buttons;
  DepositController* deposit_controller_;
};

#endif  // DEPOSITVIEW_H
