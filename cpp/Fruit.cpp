/*
 * Fruit.cpp
 *
 *  Created on: 30-Nov-2014
 *      Author: adil
 */

#include <stdio.h>

class Fruit
{
public:
	void peel()
	{
		printf("this ptr=%p\n", this);
		this->weight--;
		weight--;
	}

	Fruit();

	//Overload the '+' operator
	int operator+(Fruit &fruit);

private:
	int weight; //How is this accessible in operator+ ?
	int calories_per_oz;

};

Fruit::Fruit()
{
	this->weight = 10;
	this->calories_per_oz = 2;
}

int Fruit::operator+(Fruit &fruit)
{
	printf("Calling overload add\n");
	printf("My weight = %d\n", weight);
	printf("Operand weight = %d\n", fruit.weight);
	return weight + fruit.weight;
}

class Apple : public Fruit {
public :
	void peel() {
		printf("Peeling an apple!\n");
		//weight -= 5;
	}
};

int main()
{
	Fruit apple;
	Fruit orange;

	printf("address of apple=%p\n", &apple);
	apple.peel();
	printf("Total : %d\n", apple + orange);

	printf("\nINHERITENCE AND POLYMORPHISM\n");

	Fruit * p;
//		p = new Apple;
//		p->peel();
//		printf("Total : %d\n", *p + orange);
	return 0;
}
