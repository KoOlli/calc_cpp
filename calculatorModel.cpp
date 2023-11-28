#include "calculatorModel.h"
#include <_ctype.h>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#define P 3.141592653589793238462643383279502884197169399375105820974944592L


CalculatorModel::Stack *CalculatorModel::create_stack() {
	Stack *s = new Stack;
	s->top = 0;
	return s;
}

CalculatorModel::Data CalculatorModel::pop_elem(Stack *s){
	Data result;
	if (s->top == NULL) {
		result.symbol = '\0';
	} else {
		Node *temp = s->top;
		s->top = s->top->next;
		result = temp->data;
		delete temp;
	}
	return result;
}

void CalculatorModel::push_elem(Stack *s, Data elem)
{
	Node *elem_in_use_now = new Node;
	elem_in_use_now->data = elem;
	if (s->top) {
		elem_in_use_now->next = s->top;
	} else {
		elem_in_use_now->next = NULL;
	}
	s->top = elem_in_use_now;
}

void CalculatorModel::distroy(Stack *s)
{
	while (is_empty(s) == 1) {
		pop_elem(s);
	}
}

int CalculatorModel::is_empty(Stack *s)
{
	int result = 1;
	if (s == NULL || s->top == NULL) {
		result = 0;
	}
	return result;
}

double CalculatorModel::reduction_of_variables(std::string string) {
	Stack *my_stack_for_number = create_stack();
	Stack *my_stack_for_symbol = create_stack();
	double result = 0;
	std::string string_final = "";
	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] == 's' && string[i + 1] == 'i') {
			string_final.push_back('S');
			i += 2;
		} else if (string[i] == 'c') {
			string_final.push_back('C');
			i += 2;
		} else if (string[i] == 't') {
			string_final.push_back('T');
			i += 2;
		} else if (string[i] == 'a' && string[i + 1] == 't') {
			string_final.push_back('I');
			i += 3;
		} else if (string[i] == 'a' && string[i + 1] == 's') {
			string_final.push_back('B');
			i += 3;
		} else if (string[i] == 'a' && string[i + 1] == 'c') {
			string_final.push_back('O');
			i += 3;
		} else if (string[i] == 'l' && string[i + 1] == 'o') {
			string_final.push_back('L');
			i += 2;
		} else if (string[i] == 'l' && string[i + 1] == 'n') {
			string_final.push_back('G');
			i++;
		} else if (string[i] == 's' && string[i + 1] == 'q') {
			string_final.push_back('Q');
			i += 3;
		} else {
			string_final.push_back(string[i]);
		}
	}
//	string_final[j]= '\0';
	check_unar_symbol(string_final, my_stack_for_number, my_stack_for_symbol);
//	if (string_final != NULL)
//	delete [] string_final;
	if (my_stack_for_number != NULL) {
		if (my_stack_for_number->top != NULL) {
			result = my_stack_for_number->top->data.number;
		}
	}
	delete my_stack_for_number;
	return result;
}

double CalculatorModel::check_unar_symbol(std::string string, Stack *my_stack_for_number,
																					Stack *my_stack_for_symbol)
{
	std::string string_final;
	if (string[0] == '-') {
		string_final.push_back('~');
	} else if (string[0] == '+') {
		string_final.push_back('#');
	} else {
		string_final.push_back(string[0]);
	}
	for (int i = 1; string[i] != '\0'; i++) {
		if (string_final[i - 1] == '(' && string[i] == '-') {
			string_final.push_back('~');
		} else if (string_final[i - 1] == '(' && string[i] == '+') {
			string_final.push_back('#');
		} else {
			string_final.push_back(string[i]);
		}
	}
	line_reader(string_final, my_stack_for_number, my_stack_for_symbol);
//	if (string_final != NULL) delete [] string_final;
	return my_stack_for_number->top->data.number;

}

double CalculatorModel::line_reader(std::string string, Stack *my_stack_for_number,
																		Stack *my_stack_for_symbol) {
	int temp_priority = 0;
	Data elem;
//	double templ = 0.0;
	std::string string_number;
//	std::string string_symbol;

	for (int i = 0; string[i] != '\0'; i++) {
		int if_isdigit_end = 0;
		while (isdigit(string[i]) == 1 || string[i] == '.') {
			string_number.push_back(string[i]);
			i++;
			if_isdigit_end = 1;
		}
		if (if_isdigit_end == 1) {
			elem.number = std::stod(string_number);
			push_elem(my_stack_for_number, elem);
		}
		if (isdigit(string[i]) != 1 && string[i] != '.') {
			elem.symbol = string[i];
			push_elem(my_stack_for_symbol, elem);
		}

		character_check(string, my_stack_for_number, my_stack_for_symbol, &i,
										&temp_priority);
		string_number.clear();
	}
	while (my_stack_for_symbol->top != NULL) {
		math(my_stack_for_number, my_stack_for_symbol, &temp_priority);
	}
	return my_stack_for_number->top->data.number;
}

int CalculatorModel::check_priority(char symb){
	int priority = 0;
	switch (symb) {
		case '(':
		case ')':
			priority = 1;
			break;
		case '+':
		case '-':
			priority = 2;
			break;
		case 'S':
		case 'C':
		case 'T':
		case 'I':
		case 'B':
		case 'O':
		case 'L':
		case 'G':
		case 'Q':
			priority = 3;
			break;
		case '%':
		case '*':
		case '/':
			priority = 4;
			break;
		case '^':
			priority = 5;
			break;
		case '~':
		case '#':
			priority = 6;
			break;
		default:
			break;
	}
	return priority;

}
int CalculatorModel::character_check(std::string string, Stack *my_stack_for_number,
																		 Stack *my_stack_for_symbol, int *i, int *temp_priority){
	Data elem;
	if ((isdigit(string[*i]) == 0 || string[*i] != '.') && string[*i] != '\0') {
		if (string[*i] == 'P') {
			elem.number = P;
			push_elem(my_stack_for_number, elem);
			return 0;
		}
		elem.symbol = string[*i];
		if (string[*i] == '(') {
			push_elem(my_stack_for_symbol, elem);
			*temp_priority = check_priority(elem.symbol);
		} else if (string[*i] == ')') {
			while (my_stack_for_symbol->top->data.symbol != '(') {
				math(my_stack_for_number, my_stack_for_symbol, temp_priority);
				if (my_stack_for_symbol->top != NULL) {
					*temp_priority =
							check_priority(my_stack_for_symbol->top->data.symbol);
				}
			}
			if (my_stack_for_symbol->top->data.symbol == '(') {
				pop_elem(my_stack_for_symbol);
				if (my_stack_for_symbol->top != NULL) {
					*temp_priority =
							check_priority(my_stack_for_symbol->top->data.symbol);
				}
			}
		} else if (check_priority(elem.symbol) == 3) {
			push_elem(my_stack_for_symbol, elem);
			*temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
		} else {
			stack_push(my_stack_for_number, my_stack_for_symbol, elem, temp_priority);
		}
	}
	return 0;

}
void CalculatorModel::math(Stack *my_stack_for_number, Stack *my_stack_for_symbol,
													 int *temp_priority){
	double a, b, c = 0.0;
	char t;
	Data elem;
	t = pop_elem(my_stack_for_symbol).symbol;

	if (check_priority(t) == 6) {
		a = pop_elem(my_stack_for_number).number;
		c = priority_6(t, a);

	} else if (check_priority(t) == 5) {
		a = pop_elem(my_stack_for_number).number;
		b = pop_elem(my_stack_for_number).number;
		c = priority_5(a, b);
	} else if (check_priority(t) == 4) {
		a = pop_elem(my_stack_for_number).number;
		b = pop_elem(my_stack_for_number).number;
		c = priority_4(t, a, b);

	} else if (check_priority(t) == 3) {
		a = pop_elem(my_stack_for_number).number;
		c = priority_3(t, a);
	} else if (check_priority(t) == 2) {
		a = pop_elem(my_stack_for_number).number;
		b = pop_elem(my_stack_for_number).number;
		c = priority_2(t, a, b);
	}
	elem.number = c;
	push_elem(my_stack_for_number, elem);
	if (my_stack_for_symbol->top != NULL) {
		*temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
	}

}
double CalculatorModel::priority_6(char symbol, double number){
	double result = 0.0;
	if (symbol == '~') {
		result = 0 - number;
	} else {
		result = number;
	}
	return result;
}
double CalculatorModel::priority_5(double number_1, double number_2){
	std::cout << number_2 << "  ||  " << number_1 << std::endl;
	double result = pow(number_2, number_1);
	return result;

}
double CalculatorModel::priority_4(char symbol, double number_1, double number_2){
	double result = 0.0;
	if (symbol == '%') {
		result = fmod(number_2, number_1);
	} else if (symbol == '*') {
		result = number_2 * number_1;
	} else {
		result = number_2 / number_1;
	}
	return result;

}
double CalculatorModel::priority_3(char symbol, double number_1){
	double result = 0.0;
	if (symbol == 'S') {
		result = sin(number_1);
	} else if (symbol == 'C') {
		result = cos(number_1);
	} else if (symbol == 'T') {
		result = tan(number_1);
	} else if (symbol == 'I') {
		result = atan(number_1);
	} else if (symbol == 'B') {
		result = asin(number_1);
	} else if (symbol == 'O') {
		result = acos(number_1);
	} else if (symbol == 'L') {
		result = log10(number_1);
	} else if (symbol == 'G') {
		result = log(number_1);
	} else {
		result = sqrt(number_1);
	}
	return result;
}

double CalculatorModel::priority_2(char symbol, double number_1, double number_2){
	double result = 0.0;
	if (symbol == '-') {
		result = number_2 - number_1;
	} else {
		result = number_2 + number_1;
	}
	return result;

}
void CalculatorModel::stack_push(Stack *my_stack_for_number, Stack *my_stack_for_symbol,
																 Data elem, int *temp_priority){
	int templ;
	if (my_stack_for_symbol->top == NULL) {
		push_elem(my_stack_for_symbol, elem);
		*temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
	} else {
		if ((check_priority(elem.symbol) <= *temp_priority) &&
				!(check_priority(elem.symbol) == 5 &&
					check_priority(my_stack_for_symbol->top->data.symbol) == 5) &&
				my_stack_for_symbol->top->data.symbol != '(') {
			templ = *temp_priority;
			while ((my_stack_for_symbol->top != NULL) &&
						 (check_priority(my_stack_for_symbol->top->data.symbol) <= templ) &&
						 my_stack_for_symbol->top->data.symbol != '(') {
				math(my_stack_for_number, my_stack_for_symbol, &templ);
			}
			push_elem(my_stack_for_symbol, elem);
			*temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
		} else {
			push_elem(my_stack_for_symbol, elem);
			*temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
		}
	}
}
