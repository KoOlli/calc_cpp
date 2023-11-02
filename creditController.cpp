#include "creditController.h"
#include "creditView.h"

void CreditController::AnnuitetTable(CreditView* credit_view_) {
  credit_view_->year = credit_view_->search_data->text().last(4).toInt();
  credit_view_->month = credit_view_->search_data->text().first(2).toInt();

  credit_view_->calculation_of_payments->setRowCount(credit_view_->term_in_months->text().toInt());

  QTableWidgetItem* item;
  double balance = credit_view_->sum_credit->text().toDouble();
  int z = 0;
  for (int i = 0; i < credit_view_->term_in_months->text().toInt(); i++) {
    item = new QTableWidgetItem(QString::number(
        credit_model_->loan_annuitet_calculation(credit_view_->sum_credit->text().toDouble(),
                                  credit_view_->term_in_months->text().toInt(),
                                  credit_view_->percentage_rate->text().toDouble(), i),
        'f', 2));
    credit_view_->calculation_of_payments->setItem(i, 0, item);

    item = new QTableWidgetItem(QString::number(
        credit_model_->sum_body(credit_view_->sum_credit->text().toDouble(), credit_view_->term_in_months->text().toInt(),
                 credit_view_->percentage_rate->text().toDouble(), &balance, credit_view_->year, credit_view_->month, i),
        'f', 2));
    credit_view_->calculation_of_payments->setItem(i, 1, item);

    item = new QTableWidgetItem(QString::number(
        credit_model_->sum_percent(&balance, credit_view_->percentage_rate->text().toDouble(), credit_view_->year, credit_view_->month,
                    credit_view_->sum_credit->text().toDouble(), i),
        'f', 2));
    credit_view_->calculation_of_payments->setItem(i, 2, item);

    item = new QTableWidgetItem(QString::number(
        credit_model_->balance_of_debt(
            credit_view_->sum_credit->text().toDouble(), credit_view_->term_in_months->text().toInt(),
            credit_view_->percentage_rate->text().toDouble(), i, &balance, credit_view_->year, credit_view_->month),
        'f', 2));
    credit_view_->calculation_of_payments->setItem(i, 3, item);
  }
  credit_view_->overpayment_sum->setText(QString::number(
      credit_model_->overpayment(credit_view_->sum_credit->text().toDouble(), credit_view_->term_in_months->text().toInt(),
                  credit_view_->percentage_rate->text().toDouble(), z),
      'f', 2));
  credit_view_->result->setText(
      QString::number((credit_model_->overpayment(credit_view_->sum_credit->text().toDouble(),
                                   credit_view_->term_in_months->text().toInt(),
                                   credit_view_->percentage_rate->text().toDouble(), z) -
                       credit_view_->sum_credit->text().toDouble()),
                      'f', 2));
}

void CreditController::EstimationDifferent(CreditView* credit_view_) {
  //  int year = 2022;
  credit_view_->calculation_of_payments->setRowCount(credit_view_->term_in_months->text().toInt());

  QTableWidgetItem* item;
  double balance = credit_view_->sum_credit->text().toDouble();
  int z = 0;
  for (int i = 0; i < credit_view_->term_in_months->text().toInt(); i++, credit_view_->month++) {
    item = new QTableWidgetItem(QString::number(
        credit_model_->loan_different_calculation(
            credit_view_->sum_credit->text().toDouble(), credit_view_->term_in_months->text().toInt(),
            &balance, credit_view_->percentage_rate->text().toDouble(), credit_view_->month, credit_view_->year, i),
        'f', 2));
    credit_view_->calculation_of_payments->setItem(i, 0, item);

    item = new QTableWidgetItem(
        QString::number(credit_model_->part_of_the_principal(credit_view_->sum_credit->text().toDouble(),
                                              credit_view_->term_in_months->text().toInt()),
                        'f', 2));
    credit_view_->calculation_of_payments->setItem(i, 1, item);

    item = new QTableWidgetItem(QString::number(
        credit_model_->sum_percent_of_different(&balance, credit_view_->percentage_rate->text().toDouble(),
                                 credit_view_->year, credit_view_->month, credit_view_->sum_credit->text().toDouble(), i),
        'f', 2));
    credit_view_->calculation_of_payments->setItem(i, 2, item);

    item = new QTableWidgetItem(QString::number(
        credit_model_->balance_of_debt_different(credit_view_->sum_credit->text().toDouble(),
                                  credit_view_->term_in_months->text().toInt(), i, &balance),
        'f', 2));
    credit_view_->calculation_of_payments->setItem(i, 3, item);
  }
  credit_view_->overpayment_sum->setText(QString::number(
      credit_model_->overpayment(credit_view_->sum_credit->text().toDouble(), credit_view_->term_in_months->text().toInt(),
                  credit_view_->percentage_rate->text().toDouble(), z),
      'f', 2));
  credit_view_->result->setText(
      QString::number((credit_model_->overpayment(credit_view_->sum_credit->text().toDouble(),
                                   credit_view_->term_in_months->text().toInt(),
                                   credit_view_->percentage_rate->text().toDouble(), z) -
                       credit_view_->sum_credit->text().toDouble()),
                      'f', 2));
}


