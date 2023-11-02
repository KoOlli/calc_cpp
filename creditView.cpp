#include "creditView.h"

#include <QButtonGroup>
#include <QGridLayout>
#include <QHeaderView>
#include <QMenu>
#include <QMenuBar>
#include <QRegularExpressionValidator>
#include <QtGui>

CreditView::CreditView(QWidget* parent) : QWidget(parent) {
  QGridLayout* mainLayout = new QGridLayout;
  QLabel* data = new QLabel;
  data->setText("Дата, mm/yyyy");

  QLineEdit* search_data = new QLineEdit;
  search_data->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^((0[1-9])|(1[0-2])/20[0-9]{1,2})"), this));
  search_data->setAlignment(Qt::AlignRight);

  MyButton* return_on_calculator =
      CreateButton("Вернуться к калькулятору", SLOT(BackToCalculatorClicked()));

  total_loan_amount = new QLabel;
  total_loan_amount->setText("Общая сумма кредита, в рублях");

  sum_credit = new QLineEdit;
  sum_credit->setAlignment(Qt::AlignRight);

  QDate date1(2022, 12, 26);
  QDate date2(2077, 12, 26);

  int resulttt = date1.daysTo(date2);
  qDebug() << resulttt;

  sum_credit->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([0-9]{1,9}[.][0-9]{1,2})"), this));
  sum_credit->setMaxLength(10);

  term = new QLabel;
  term->setText("Срок кредита, в месяцах");

  term_in_months = new QSpinBox;
  term_in_months->setMaximum(600);
  term_in_months->setAlignment(Qt::AlignRight);

  interest_rate = new QLabel;
  interest_rate->setText("Процентная ставка");

  percentage_rate = new QLineEdit;
  percentage_rate->setAlignment(Qt::AlignRight);
  percentage_rate->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([0-9]{1,2}[.][0-9]{1,2})"), this));

  type = new QLabel;
  type->setText("Тип ежемесячных платежей");

  annuitet = new QRadioButton;
  different = new QRadioButton;

  radio_button_group = new QButtonGroup;
  annuitet->setText("аннуитетный");
  different->setText("дифференцированный");

  MyButton* make_a_calculation =
      CreateButton("Рассчитать", SLOT(MakeCalculateClicked()));

  calculation_of_payments = new QTableWidget;
  calculation_of_payments->setEditTriggers(QAbstractItemView::NoEditTriggers);
  calculation_of_payments->setColumnCount(4);

  calculation_of_payments->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Сумма платежа"));
  calculation_of_payments->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Сумма в погашение тела кредита"));
  calculation_of_payments->setColumnWidth(1, 200);
  calculation_of_payments->setHorizontalHeaderItem(
      2, new QTableWidgetItem("Сумма в погашение процентов"));
  calculation_of_payments->setColumnWidth(2, 200);
  calculation_of_payments->setHorizontalHeaderItem(
      3, new QTableWidgetItem("Остаток долга"));

  overpayment_on_a_loan = new QLabel;
  overpayment_on_a_loan->setText("Переплата по кредиту");
  overpayment_sum = new QLabel;

  total_payment = new QLabel;
  total_payment->setText("Общая выплата по кредиту");
  result = new QLabel;

  mainLayout->addWidget(data, 0, 0);
  mainLayout->addWidget(search_data, 0, 1);
  mainLayout->addWidget(total_loan_amount, 1, 0);
  mainLayout->addWidget(sum_credit, 1, 1);
  mainLayout->addWidget(term, 2, 0);
  mainLayout->addWidget(term_in_months, 2, 1);

  mainLayout->addWidget(interest_rate, 3, 0);
  mainLayout->addWidget(percentage_rate, 3, 1);
  mainLayout->addWidget(type, 4, 0);
  mainLayout->addWidget(annuitet, 4, 1);
  mainLayout->addWidget(different, 4, 2);

  mainLayout->addWidget(make_a_calculation, 5, 1);
  mainLayout->addWidget(return_on_calculator, 5, 2);

  mainLayout->addWidget(calculation_of_payments, 12, 0, 3, 5);
  mainLayout->addWidget(overpayment_on_a_loan, 10, 0);
  mainLayout->addWidget(result, 10, 1);
  mainLayout->addWidget(total_payment, 11, 0);
  mainLayout->addWidget(overpayment_sum, 11, 1);

  setStyleSheet(
      "MyButton { background-color: #81FFDF; font-family: Luminari; font-size: "
      "15px; color: #00C994; border-style: outset; border-width: 2px;"
      "border-radius: 10px; border-color: #D6D2D6; min-width: 2em; padding: "
      "2px; }"
      "QLineEdit { font-family: Chalkduster; color: #00C994; background-color: "
      "#8AFFDC }"
      "CreditView { background-color: #BEFFDE }"
      "QLabel { font-family: Luminari; color: #00C994; font-size: 18px }"
      "QSpinBox { font-family: Chalkduster; color: #00C994; background-color: "
      "#8AFFDC; font-size: 30px }"
      "QRadioButton { color: #00C994; font-size: 18px; font-family: Luminari "
      "}");

  QFont font = sum_credit->font();
  font.setPointSize(font.pointSize() + 5);
  search_data->setFont(font);
  sum_credit->setFont(font);
  term_in_months->setFont(font);
  percentage_rate->setFont(font);

  setLayout(mainLayout);

  setWindowTitle("Credit Calculator");
}

MyButton* CreditView::CreateButton(const QString& text,
                                          const char* member) {
  MyButton* temp = new MyButton(text);
  buttons.push_back(temp);

  connect(temp, SIGNAL(clicked()), this, member);

  return temp;
}

void CreditView::BackToCalculatorClicked() {
  this->close();
  emit firstWindow();
}

void CreditView::MakeCalculateClicked() {
  allButtons = findChildren<QRadioButton*>();
  for (int i = 0; i < allButtons.size(); ++i) {
    radio_button_group->addButton(allButtons[i], i);
  }
  //  qDebug() << radio_button_group->checkedId();
  if (radio_button_group->checkedId() == 0) {
    credit_controller_->AnnuitetTable(this);
  } else {
    credit_controller_->EstimationDifferent(this);
  }
}
