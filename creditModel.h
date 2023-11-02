#ifndef CREDITMODEL_H
#define CREDITMODEL_H
#include <iostream>

class CreditModel {
 public:
  double loan_annuitet_calculation(double sum_credit, int number_of_payment,
                                   double percent, int i);
  int check_year(int year);
  int check_days_on_month(int month, int year);
  double balance_of_debt(double sum_credit, int number_of_payment,
                         double percent, int i, double *result, int year,
                         int month);
  double overpayment(double sum_credit, int number_of_payment, double percent,
                     int i);
  double sum_percent(double *result, double percent, int year, int month,
                     double sum_credit, int i);
  double sum_body(double sum_credit, int number_of_payment, double percent,
                  double *result, int year, int month, int i);
  double part_of_the_principal(double sum_credit, int number_of_payment);
  double loan_different_calculation(double sum_credit, int number_of_payment,
                                    double *result, double percent, int month,
                                    int year, int i);
  double balance_of_debt_different(double sum_credit, int number_of_payment,
                                   int i, double *result);
  double sum_percent_of_different(double *result, double percent, int year,
                                  int month, double sum_credit, int i);
};

#endif // CREDITMODEL_H


