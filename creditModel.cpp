#include "creditModel.h"
#include <cmath>

double CreditModel::loan_annuitet_calculation(double sum_credit,
                                                    int number_of_payment,
                                                    double percent, int i) {
  double resultat = 0.0;
  double monthy_interest_ratio = percent / 12 / 100;

  double annuitet_ratio =
      (monthy_interest_ratio *
       pow((1 + monthy_interest_ratio), number_of_payment)) /
      (pow((1 + monthy_interest_ratio), number_of_payment) - 1);
  double sum_payment = annuitet_ratio * sum_credit;
  double total_loan_amount = sum_payment * number_of_payment;
  if (i == (number_of_payment - 1)) {
    resultat = total_loan_amount - (sum_payment * i);
  } else {
    resultat = sum_payment;
  }
  return resultat;
};

int CreditModel::check_year(int year) {
  int days;
  if ((year % 4) == 0) {
    days = 366;
  } else {
    days = 365;
  }
  return days;
};

int CreditModel::check_days_on_month(int month, int year) {
  int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (check_year(year) == 366) days_in_months[1] = 29;
  return days_in_months[(month - 1) % 12];
};

double CreditModel::balance_of_debt(double sum_credit,
                                          int number_of_payment, double percent,
                                          int i, double *result, int year,
                                          int month) {
  if (i == 0) {
    *result = sum_credit - sum_body(sum_credit, number_of_payment, percent,
                                    result, year, month, i);
  } else if (sum_body(sum_credit, number_of_payment, percent, result, year,
                      month, i) > *result) {
    *result = *result - *result;
  } else {
    *result = *result - sum_body(sum_credit, number_of_payment, percent, result,
                                 year, month, i);
  }
  return *result;
};

double CreditModel::overpayment(double sum_credit, int number_of_payment,
                                      double percent, int i) {
  double result =
      loan_annuitet_calculation(sum_credit, number_of_payment, percent, i) *
      number_of_payment;
  return result;
};

double CreditModel::sum_percent(double *result, double percent, int year,
                                      int month, double sum_credit, int i) {
  double sum_for_percent_return = 0.0;
  if (i == 0) {
    sum_for_percent_return = (sum_credit)*percent / 100 *
                             check_days_on_month(month, year) /
                             check_year(year);
  } else {
    sum_for_percent_return = (*result) * percent / 100 *
                             check_days_on_month(month, year) /
                             check_year(year);
  }
  return sum_for_percent_return;
};

double CreditModel::sum_body(double sum_credit, int number_of_payment,
                                   double percent, double *result, int year,
                                   int month, int i) {
  double result_for_body;
  if (i == 0) {
    result_for_body =
        loan_annuitet_calculation(sum_credit, number_of_payment, percent, i) -
        sum_percent(result, percent, year, month, sum_credit, i);
  } else {
    result_for_body =
        loan_annuitet_calculation(sum_credit, number_of_payment, percent, i) -
        sum_percent(result, percent, year, month, sum_credit, i);
  }
  return result_for_body;
};

double CreditModel::part_of_the_principal(double sum_credit,
                                                int number_of_payment) {
  double result_for_part = sum_credit / number_of_payment;
  return result_for_part;
};

double CreditModel::loan_different_calculation(double sum_credit,
                                                     int number_of_payment,
                                                     double *result,
                                                     double percent, int month,
                                                     int year, int i) {
  double result_for_loan_dif = 0.0;
  if (i == 0) {
    result_for_loan_dif =
        part_of_the_principal(sum_credit, number_of_payment) +
        sum_percent_of_different(result, percent, year, month, sum_credit, i);
  } else {
    result_for_loan_dif =
        part_of_the_principal(sum_credit, number_of_payment) +
        sum_percent_of_different(result, percent, year, month, sum_credit, i);
  }
  return result_for_loan_dif;
};

double CreditModel::balance_of_debt_different(double sum_credit,
                                                    int number_of_payment,
                                                    int i, double *result) {
  if (i == 0) {
    *result = sum_credit - part_of_the_principal(sum_credit, number_of_payment);
  } else if (part_of_the_principal(sum_credit, number_of_payment) > *result) {
    *result = *result - *result;
  } else {
    *result = *result - part_of_the_principal(sum_credit, number_of_payment);
  }
  return *result;
};

double CreditModel::sum_percent_of_different(double *result,
                                                   double percent, int year,
                                                   int month, double sum_credit,
                                                   int i) {
  double sum_for_percent_return = 0.0;
  if (i == 0) {
    sum_for_percent_return = (sum_credit)*percent / 100 *
                             check_days_on_month(month, year) /
                             check_year(year);
  } else {
    sum_for_percent_return = (*result) * percent / 100 *
                             check_days_on_month(month, year) /
                             check_year(year);
  }
  return sum_for_percent_return;
};
