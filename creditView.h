#ifndef CREDITVIEW_H
#define CREDITVIEW_H

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
#include "creditController.h"


class CreditView : public QWidget {
  Q_OBJECT

 signals:
  void firstWindow();

  public:
   CreditView(CreditController* credit_controller_);
   explicit CreditView(QWidget* parent = nullptr);
   QLabel* result;
   int year;
   int month;

  QLabel* total_loan_amount;
  QLineEdit* sum_credit;

  QLabel* term;
  QSpinBox* term_in_months;

  QLabel* interest_rate;
  QLineEdit* percentage_rate;

  QLabel* data;
  QLineEdit* search_data;
  QLabel* type;
  QButtonGroup* radio_button_group;
  QRadioButton* annuitet;
  QRadioButton* different;

  QTableWidget* calculation_of_payments;
  QLabel* overpayment_on_a_loan;
  QLabel* overpayment_sum;
  QLabel* total_payment;

  QVBoxLayout* layout;
  QMenuBar* menubar;
  QMenu* menu;
  QAction* action1;


private slots:
   void BackToCalculatorClicked();
   void MakeCalculateClicked();

private:
  MyButton* CreateButton(const QString& text, const char* member);
  QVector<MyButton*> buttons;
  QList<QRadioButton*> allButtons;

  CreditController* credit_controller_;

};

#endif  // CREDITVIEW_H
