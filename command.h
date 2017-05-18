#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;

	public:
		Command() { }
		double execute() {
			return root->evaluate();
		}
		Base* get_root() {
			return root;
		}
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
		OpCommand() {
			root = new Op(0);
		}
		OpCommand(double value) {
			root = new Op(value);
		}
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
		AddCommand(Command* l, double r) {
			root = new Add(l->get_root(), new Op(r));
		}
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
	SubCommand(Command* l, double r) {
		root = new Sub(l->get_root(), new Op(r));
	}
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
	MultCommand(Command* l, double r) {
		root = new Mult(l->get_root(), new Op(r));
	}
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
	SqrCommand(Command* onlyChild) {
		root = new Sqr(onlyChild->get_root());
	}
};

#endif //__COMMAND_CLASS__
