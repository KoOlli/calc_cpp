#ifndef CALCULATORXVIEW_H
#define CALCULATORXVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <iostream>
#include <QGridLayout>


#include "calculatorModel.h"
#include "mybutton.h"


class CalculatorXView : public QWidget
{
		Q_OBJECT

	signals:
		void firstWindow();

	private slots:
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

	public:
		CalculatorXView(CalculatorModel* calculator_model_);
		CalculatorXView();
		QString xxxx;
		QLineEdit* display_for_x;
		CalculatorModel* calculator_model_;

	private:
		MyButton* m_digitButtons[10];
		MyButton* CreateButton(const QString& text, void (CalculatorXView::*member)());
		QVector<MyButton*> buttons;
		int count = 0;

};

#endif // CALCULATORXVIEW_H
