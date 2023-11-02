#ifndef CALCULATORVIEW_H
#define CALCULATORVIEW_H

#include <QChar>
#include <QColor>
#include <QDebug>
#include <QGridLayout>
#include <QImage>
#include <QLabel>
#include <QLineEdit>
#include <QTextLine>
#include <QValidator>
#include <QWidget>
#include <iostream>

#include "calculatorModel.h"
#include "depositView.h"
#include "calculatorXView.h"
#include "mybutton.h"
#include "graficsView.h"
#include "creditView.h"

class CalculatorView : public QWidget {
		Q_OBJECT

	private slots:

		void CheckClickedX();
		void DigitClicked();
		void UnaryOperatorClicked();
		void AuxiliaryOperatorClicked();
		void DoubleOperatorClicked();
		void EqualClicked();
		void CheckPoint();
		int PointClicked(MyButton* temp);
//		void ChangeSingClicked();
		void TrigonometryClicked();
		void Clear();
		void ClearAll();

		void DepositClicked();
		void CreditClicked();
		void GraphsClicked();

	public:
		CalculatorView();
		CalculatorView(CalculatorModel* calculator_model_);

		CalculatorXView* widget_x;
		GraficsView* widget_graphs;
		DepositView* widget_deposit;
		CreditView* widget_credit;

	private:
		CalculatorModel* calculator_model_;
		QLineEdit* m_display_up;
		MyButton* m_digitButtons[10];
		MyButton* CreateButton(const QString& text, void (CalculatorView::*member)());
		QVector<MyButton*> buttons;
		int count = 0;
};

#endif  // CALCULATORVIEW_H
