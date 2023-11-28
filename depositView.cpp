#include "depositView.h"

#include <QGridLayout>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

DepositView::DepositView(QWidget* parent) : QWidget(parent) {
  QGridLayout* mainLayout = new QGridLayout;

  sum_amount = new QLabel;
  sum_amount->setText("Сумма вкалада, руб");
  sum_amount_line = new QLineEdit;
  sum_amount_line->setAlignment(Qt::AlignRight);
  sum_amount_line->setMaxLength(10);

  placement_period = new QLabel;
  placement_period->setText("Срок размещения, в месяцах");
  placement_period_line = new QSpinBox;
  placement_period_line->setAlignment(Qt::AlignRight);
  placement_period_line->setMaximum(60);

  interest_rate = new QLabel;
  interest_rate->setText("Процентная ставка, %");
  interest_rate_line = new QLineEdit;
  interest_rate_line->setAlignment(Qt::AlignRight);
  interest_rate_line->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([0-9]{1,2}[,.][0-9]{1,2})"), this));

  tax_rate = new QLabel;
  tax_rate->setText("Налоговая ставка, %");
  tax_rate_line = new QLineEdit;
  tax_rate_line->setAlignment(Qt::AlignRight);
  tax_rate_line->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([0-9]{1,2}[,.][0-9]{1,2})"), this));

  perodicity_of_payments = new QLabel;
  perodicity_of_payments->setText("Периодичность выплат");
  perodicity_of_payments_line = new QLineEdit;
  perodicity_of_payments_line->setAlignment(Qt::AlignRight);

  interest_capitalization = new QLabel;
  interest_capitalization->setText("Капитализация процентов");
  interest_capitalization_line = new QLineEdit;
  interest_capitalization_line->setAlignment(Qt::AlignRight);

  MyButton* make_a_calculation =
      CreateButton("Расчитать", SLOT(MakeCalculateClicked()));
  MyButton* return_on_calculator =
      CreateButton("Вернуться к калькулятору", SLOT(BackToCalculatorClicked()));

  interest_charges = new QLabel;
  interest_charges->setText("Начисленные проценты");

  amount_of_taxes = new QLabel;
  amount_of_taxes->setText("Сумма налогов");

  sum_amount_by_the_end = new QLabel;
  sum_amount_by_the_end->setText("Сумма на вкладе к концу срока");

  setStyleSheet(
      "MyButton { background-color: #88FFFF; font-family: Luminari; font-size: "
      "15px; color: #09B5B5; border-style: outset; border-width: 2px;"
      "border-radius: 10px; border-color: #D6D2D6; min-width: 2em; padding: "
      "2px; }"
      "QLineEdit { font-family: Chalkduster; color: #09B5B5; background-color: "
      "#81FFFF }"
      "DepositView { background-color: #BFFFFF }"
      "QLabel { font-family: Luminari; color: #09B5B5; font-size: 18px }"
      "QSpinBox { font-family: Chalkduster; color: #09B5B5; background-color: "
      "#81FFFF; font-size: 30px }");

  mainLayout->addWidget(sum_amount, 0, 0);
  mainLayout->addWidget(sum_amount_line, 0, 1);

  mainLayout->addWidget(placement_period, 1, 0);
  mainLayout->addWidget(placement_period_line, 1, 1);

  mainLayout->addWidget(interest_rate, 2, 0);
  mainLayout->addWidget(interest_rate_line, 2, 1);

  mainLayout->addWidget(tax_rate, 3, 0);
  mainLayout->addWidget(tax_rate_line, 3, 1);

  mainLayout->addWidget(perodicity_of_payments, 4, 0);
  mainLayout->addWidget(perodicity_of_payments_line, 4, 1);

  mainLayout->addWidget(interest_capitalization, 5, 0);
  mainLayout->addWidget(interest_capitalization_line, 5, 1);

  mainLayout->addWidget(make_a_calculation, 6, 1);
  mainLayout->addWidget(return_on_calculator, 6, 2);

  mainLayout->addWidget(interest_charges, 7, 0);
  mainLayout->addWidget(amount_of_taxes, 8, 0);
  mainLayout->addWidget(sum_amount_by_the_end, 9, 0);

  mainLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);

  QFont font = sum_amount_line->font();
  font.setPointSize(font.pointSize() + 7);
  sum_amount_line->setFont(font);
  interest_rate_line->setFont(font);
  tax_rate_line->setFont(font);
  perodicity_of_payments_line->setFont(font);
  interest_capitalization_line->setFont(font);

  setLayout(mainLayout);

  setWindowTitle("Deposit Calculator");
}

MyButton* DepositView::CreateButton(const QString& text,
                                           const char* member) {
  MyButton* temp = new MyButton(text);
  buttons.push_back(temp);

  connect(temp, SIGNAL(clicked()), this, member);

  return temp;
}

void DepositView::BackToCalculatorClicked() {
  this->close();
  emit firstWindow();
}

void DepositView::MakeCalculateClicked() {

}
