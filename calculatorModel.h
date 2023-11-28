#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H
#include <string>

class CalculatorModel
{
	public:
		double reduction_of_variables(std::string string);

	private:
		typedef union {
				double number;
				char symbol;
		} Data;
		typedef struct node {
				Data data;
				struct node *next;
		} Node;
		typedef struct {
				Node *top;
		} Stack;

		Stack *create_stack();

		Data pop_elem(Stack *s);
		void push_elem(Stack *s, Data elem);
		void distroy(Stack *s);
		int is_empty(Stack *s);

		double check_unar_symbol(std::string string, Stack *my_stack_for_number,
														 Stack *my_stack_for_symbol);
		double line_reader(std::string string, Stack *my_stack_for_number,
											 Stack *my_stack_for_symbol);
		int check_priority(char symb);
		int character_check(std::string string, Stack *my_stack_for_number,
												Stack *my_stack_for_symbol, int *i, int *temp_priority);
		void math(Stack *my_stack_for_number, Stack *my_stack_for_symbol,
							int *temp_priority);
		double priority_6(char symbol, double number);
		double priority_5(double number_1, double number_2);
		double priority_4(char symbol, double number_1, double number_2);
		double priority_3(char symbol, double number_1);
		double priority_2(char symbol, double number_1, double number_2);
		void stack_push(Stack *my_stack_for_number, Stack *my_stack_for_symbol,
										Data elem, int *temp_priority);
};

#endif // CALCULATORMODEL_H
